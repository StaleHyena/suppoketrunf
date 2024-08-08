#!/bin/env python3
import csv
import sys

if (len(sys.argv) < 2):
    print("must provide a file path", file=sys.stderr);
    exit()

fname = sys.argv[1];
filter_func = lambda i,n,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen,leg: True;
if (len(sys.argv) >= 3):
    filter_func = lambda i,n,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen,leg: eval(sys.argv[2]);

with open(fname, newline='') as pkfile:
    nocomments = filter(lambda l: l[0] != '#' if len(l) > 0 else False, pkfile);
    pkr = csv.reader(nocomments, delimiter=',');
    for row in pkr:
        i,n,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen,leg = row;
        p = filter_func(i,n,t1,t2,tot,hp,atks,defs,satks,sdefs,spd,gen,leg);

        row[1] = f'"{n}"';
        if not p:
            continue;
        if (len(t2) == 0):
            row[3] = "Undef";
        args = ",".join(row);
        print(f"X({args})");
