#!/bin/env python3
import csv

names = [];
name_lens = [];
with open("../pokemon.csv", newline='') as pkfile:
    pkr = csv.reader(pkfile, delimiter=',');
    for row in pkr:
        name = row[1];
        filtered_name = ""
        for c in name:
            if (c.lower() <= 'z' and c.lower() >= 'a') or c == ' ':
                filtered_name += c;
        name_lens.append((len(name), len(filtered_name)))
        names.append(row[1]);

# So, to get a progressive
# hash going, i've decided to make a base-27 positional
# number system to assign each pokemon name a number.
# place values work as usual, units on the right, leftmost
# is most significant. that works out to making so each
# additional letter given makes the hash closer to the actual
# value of a valid pokemon name.

def hash_func(name):
    og_name = name
    # tradeoff between specificity and enumerable length
    # `l` places at most, we've only got
    # 2**54 values at our disposal
    l = 10
    name_lowered = list(filter(lambda x: (x <= 'z' and x >= 'a') or x == ' ', name.lower()));
    name = list(map(lambda x: ord(x) - ord('a') + 1 if x != ' ' else 0, name_lowered));

    acc = 0;
    for i, c in enumerate(name):
        exp = l - i;
        exp = exp if exp > 0 else 0;
        acc += (27)**exp * c;
    #loff = l - len(og_name)
    #acc += loff
    if acc > 2**54:
        print("")
        print(og_name
            + " (" + "".join(name_lowered)
            + " -> " + "".join(map(lambda x: chr(x + ord('a')), name))
            + ") extrapolates max_val with hash value " + str(acc));
        print("")
    return acc;

hashes = [ (name, hash_func(name)) for name in names];

seen = set()
dupes = []
for pair in hashes:
    if pair[1] in seen:
        conflicts = []
        for n, h in hashes:
            if h == pair[1]:
                if n != pair[0]:
                    conflicts.append((n,h))
        dupes.append((pair, conflicts))
    seen.add(pair[1])

dupes.sort(key=lambda x: x[1])
for pair, conflicts in dupes:
    name_o = "".join(filter(lambda x: (x <= 'z' and x >= 'a') or x == ' ', pair[0].lower()));

    print(pair[0] + "(" + name_o + ") hash " + str(pair[1]), end="");
    print(" conflicts with: ");
    for n, h in conflicts:
        name = "".join(filter(lambda x: (x <= 'z' and x >= 'a') or x == ' ', n.lower()));
        print(n + "(" + name + ") hash " + str(h));
    print("");
print("----")
hashes.sort(key=lambda x: x[1])
for pair in hashes:
    name = "".join(filter(lambda x: (x <= 'z' and x >= 'a') or x == ' ', pair[0].lower()));

    print(pair[0] + "(" + name + ") hash " + str(pair[1]));
#print(hashes)
