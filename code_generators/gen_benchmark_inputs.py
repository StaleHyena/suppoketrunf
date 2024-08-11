#!/bin/env python3
import csv
import sys
from math import log2
from itertools import accumulate

if (len(sys.argv) < 2):
    print("must provide a file path", file=sys.stderr);
    exit()

fname = sys.argv[1];

names = [];
longest_name_len = 0;

with open(fname, newline='') as pkfile:
    nocomments = filter(lambda l: l[0] != '#' if len(l) > 0 else False, pkfile);
    pkr = csv.reader(nocomments, delimiter=',');
    for uid, row in enumerate(pkr):
        name = row[1];
        names.append(name);
        namelen = len(name);
        if namelen > longest_name_len:
            longest_name_len = namelen;

ins = set()
for i in range(0, longest_name_len-1):
    for name in names:
        if len(name) < i:
            continue;
        ins.add(name[:i+1])

for query in ins:
    print(query);

