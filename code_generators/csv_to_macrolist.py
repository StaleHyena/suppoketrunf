#!/bin/env python3
import csv
import sys

if (len(sys.argv) < 2):
    print("must provide a file path", file=sys.stderr);
    exit()

fname = sys.argv[1];
filter_func = lambda i,n,v,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen: True;
if (len(sys.argv) >= 3):
    filter_func = lambda i,n,v,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen: eval(sys.argv[2]);

with open(fname, newline='') as pkfile:
    nocomments = filter(lambda l: l[0] != '#' if len(l) > 0 else False, pkfile);
    pkr = csv.reader(nocomments, delimiter=',');
    for row in pkr:
        i,n,v,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen = row;
        p = filter_func(i,n,v,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen);
        if not p:
            continue;
        n = f'"{n}"' if not v.strip() else f'"{n} ({v})"';
        nlen = len(n);
        if (not t2.strip()):
            t2 = "Undef";
        args = ",".join([i,n,str(nlen),t1,t2,tot,hp,atks,defs,gen]);
        print(f"X({args})");
