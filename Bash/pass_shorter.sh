#! /bin/bash

# head -n 60 input.txt | tail -n 20

filename="pass_dict.txt"
offset=50000000
size=`cat $filename | wc -l`
parts=$(($size/$offset + 1))

echo "It required $parts parts"

for (( i=1; i<=$parts; i++ )); do
    echo "Creating pass_dict$i.txt..."
    head -n $(($i*$offset)) $filename | tail -n $offset > "pass_dict$i.txt"
done