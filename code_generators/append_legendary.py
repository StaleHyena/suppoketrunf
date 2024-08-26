#!/usr/bin/env python3

from typing import List, Tuple
from dataclasses import dataclass
import csv
import requests
import sys

if (len(sys.argv) < 2):
    print("must provide a file path", file=sys.stderr);
    exit()

fname = sys.argv[1];

with open(fname, newline='') as pkfile:
    base_url = "https://pokeapi.co/api/v2"
    s = requests.session()
    nocomments = filter(lambda l: l[0] != '#' if len(l) > 0 else False, pkfile);
    pkr = csv.reader(nocomments, delimiter=',');
    for row in pkr:
        i, n, v = row[0:3];
        i = int(i)
        n = f'"{n}"'
        v = f'"{v}"'
        res = s.get(f"{base_url}/pokemon-species/{i}").json()
        legendary = res['is_legendary'];
        print(f"{str(i)},{n},{v}," + ",".join(row[3:]) + f",{legendary}");

