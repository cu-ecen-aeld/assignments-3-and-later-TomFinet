#!/bin/bash

set -u

if [ ! -d $1 ] || [ -z $2 ]
then
	exit 1
fi

NUM_FILES=$(ls $1 | wc -l)
NUM_MATCH=$(grep $2 $1/* | wc -l)

echo "The number of files are ${NUM_FILES} and the number of matching lines are ${NUM_MATCH}"
