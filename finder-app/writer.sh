#!/bin/bash

set -u

if [ -z $1 ] || [ -z $2 ]
then
	exit 1
fi

PTH=$(echo $1 | sed -n 's/^\(.*\/\)*\(.*\)/\1/p')

if [[ ! $(mkdir -p "$PTH") -eq 0 ]]
then
	exit 1
fi

touch $1
echo $2 > $1
