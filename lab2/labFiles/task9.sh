#!/bin/bash

echo -n "Enter Name of Directory: "
read dirName
#directory success
if [ -d $dirName ]; then
	let tries=0
	while [ $tries -lt 3 ]; do
		echo -n "Please Enter an Existing File's name: "
		read $fileName
		if [ -e $fileName ]; then
			echo "exists"
			if [ -r $fileName ]; then
				echo "readable"
				echo -n "Please enter word you would like to find: "
				read word
				if grep -q "$word" "$fileName"; then
					echo "<$word> FOUND!"
				else
					echo "<$word> NOT FOUND."
					exit 4
				fi
			else
				echo "File is not readable."
				exit 3
			fi
		else
			let tries=$(expr tries+1)
		fi
	done
		echo "You did not enter an Existing File's name."
		exit 2
	
#directory fail
else
	echo "Local Directory Not Found, Please Try Again."
	exit 1
fi
exit 0
