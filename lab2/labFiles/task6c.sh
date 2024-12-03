#!/bin/bash

for i in $(seq 1 $2);
do
	let h=($2/2)
	let n=$h+1-i
	if [ $n -gt 0 ]; then
		for j in $(seq 1 $1);
		do
			echo -n " "
		done
		echo -n "*"
		let d=(i-1)*2
		for j in $(seq 1 $d);
		do
			echo -n "*"
		done
	elif [ $n -eq 0 ]; then
		for j in $(seq 1 $1);
		do
			echo -n "*"
		done
		for j in $(seq 1 $2);
		do
			echo -n "*"
		done
	else
		for j in $(seq 1 $1);
		do
			echo -n " "
		done 
		echo -n "*"
		let d=($h+$n)*2
		for j in $(seq 1 $d);
		do
			echo -n "*"
		done

	fi
	echo " "
done
exit 0;
