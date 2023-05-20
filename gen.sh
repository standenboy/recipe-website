#!/bin/sh

rm -rf ./htmlRecipes/*

array=(./recipes/*)


for i in "${array[@]}";
do
echo $i | cut -d '/' -f 3
./genpage $i > htmlRecipes/$(echo $i | cut -d '/' -f 3).html
done

./genhome > index.html


