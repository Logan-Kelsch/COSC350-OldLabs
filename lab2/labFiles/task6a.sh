#!/bin/bash

for i in $(seq 1 $1);
do
	let n=$1/2+1-i
	if [ $n -gt -1 ]; then
		for j in $(seq 1 $n);
		do
			echo -n " "
		done
		echo -n "*"
		let d=(i-1)*2
		for j in $(seq 1 $d);
		do
			echo -n "*"
		done
	else
		let m=$n*-1
		for j in $(seq 1 $m);
		do
			echo -n " "
		done 
		echo -n "*"
		let d=($1/2+$n)*2
		for j in $(seq 1 $d);
		do
			echo -n "*"
		done

	fi
	echo " "
done
exit 0;
