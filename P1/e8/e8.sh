#!/bin/bash

l=0
let t=0
for i in $*; do
	l=`wc -l $i | awk '{print $1}'`
	echo $l
	let t=$t+$l #let es necesario para evaluar aritmeticamente
done

echo "Total: $t, args:$#"