#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Please enter at least one variable."
	exit 0
else
	let n=$1
	let t=0
	let tmp=0
	while [ $n -gt 0 ];
	do
		let tmp=($n%10)
		let t=$t+$tmp
		let n=$n/10
	done
	echo -n "The sum is "
	echo $t
fi
exit 0
