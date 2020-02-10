#!/bin/bash
for i in {8..24}
do
# ./locations.out $((2**$i)) $((2**(24-$i)))
python update_locations.py $((2**$i)) $((25-$i))

done
