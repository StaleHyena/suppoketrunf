#!/bin/env python3
import csv
import sys
from math import log2
from itertools import accumulate

if (len(sys.argv) < 2):
    print("must provide a file path", file=sys.stderr);
    exit()

fname = sys.argv[1];

# found through experimenting inside "../hash_playground"
def hash_func(name):
    og_name = name
    # tradeoff between specificity and enumerable length
    # `l` places at most, we've only got
    # 2**54 values at our disposal
    l = 11
    name_lowered = list(filter(lambda x: (x <= 'z' and x >= 'a') or x == ' ', name.lower()));
    name = list(map(lambda x: ord(x) - ord('a') + 1 if x != ' ' else 0, name_lowered));

    acc = 0;
    for i, c in enumerate(name):
        exp = l - 1 - i;
        exp = exp if exp > 0 else 0;
        acc += (27)**exp * c;
    loff = l - len(og_name)
    acc += loff
    if acc > 2**54:
        print(og_name
            + " (" + "".join(name_lowered)
            + " -> " + "".join(map(lambda x: chr(x + ord('a')), name))
            + ") extrapolates max_val with hash value " + str(acc));
    return acc;

hashtups = [];
names = [];
with open(fname, newline='') as pkfile:
    nocomments = filter(lambda l: l[0] != '#' if len(l) > 0 else False, pkfile);
    pkr = csv.reader(nocomments, delimiter=',');
    for uid, row in enumerate(pkr):
        name = row[1];
        names.append(name);
        hashtups.append((hash_func(name), uid));

hashtups.sort(key=lambda x: x[0])

def btree_from_ordered_vec(vec, start_idx, end_idx):
    bt = None;
    middle = (end_idx + start_idx) // 2;
    cur_val = vec[middle];
    if start_idx > end_idx:
        return None;

    l = btree_from_ordered_vec(vec, start_idx, middle - 1);
    r = btree_from_ordered_vec(vec, middle + 1, end_idx);
    ll = l[3] if l != None else 0;
    lr = r[3] if r != None else 0;
    return (l, cur_val, r, max(ll, lr)+1);

bt = btree_from_ordered_vec(hashtups, 0, len(hashtups) - 1);

def btree_print(a, depth, printfunc):
    if(a == None):
        print("");
        return;

    print("(", end="");
    printfunc(a);
    if (not a[0] and not a[2]):
        print(")");
        return;

    print("");
    for i in range(0, depth + 1):
        print(' ', end="");

    btree_print(a[0], depth + 1, printfunc);
    
    for i in range(0, depth + 1):
        print(' ', end="");

    btree_print(a[2], depth + 1, printfunc);

    for i in range(0, depth + 1):
        print(' ', end="");

    print(")");

def btree_macro_repr(node, total_depth, depth, bt_name, linidx):
    if node == None:
        return ("", -1);
    am_leaf = not node[0] and not node[2];
    linidx_step = 2**(total_depth - depth - 2)
    l,li = btree_macro_repr(node[0], total_depth, depth+1, bt_name, linidx - linidx_step);
    v = node[1];
    phash = node[1][0];
    pid = node[1][1];
    vpacked = (phash << 10) | pid & 0x3FF;
    cmnt = names[pid] + f", id {pid}, depth {depth}";
    r,ri = btree_macro_repr(node[2], total_depth, depth+1, bt_name, linidx + linidx_step);

    lref = f"&{bt_name}[{li}]" if li >= 0 else "NULL";
    rref = f"&{bt_name}[{ri}]" if ri >= 0 else "NULL";
    return (f"[{linidx}] = {{{vpacked}, {lref}, {rref}}}, // {cmnt}\n" + l + r, linidx);

btree_depth = bt[3];
btree_name = "pokemon_btree";
btree_ext_name = "pokemon_hashed_names_btree";
btree_repr = btree_macro_repr(bt, btree_depth, 0, btree_name, 2**(btree_depth - 1))[0];
print(f"""
#include "pokemon_dyntables.h"

btree {btree_name}[{2**btree_depth}] = {{
{btree_repr}
}};
btree *{btree_ext_name} = &{btree_name}[{2**(btree_depth - 1)}];
size_t {btree_ext_name}_depth = {btree_depth};
""");

