#!/bin/bash

let n=1
let m=1
while [ $1 -gt $n ]; do
	let n=$n+1
	let m=$n*$m
done
echo -n "Factorial of "
echo -n $1
echo -n " equals "
echo $m

exit 0
