#!/bin/sh

while (true)
do

rm -rf ./recipe-website

git clone https://github.com/standenboy/recipe-website

cp -r recipe-website/recipes/* recipes/ 


rm -rf ./htmlRecipes/*

array=(./recipes/*)


for i in "${array[@]}";
do
echo $i | cut -d '/' -f 3
./genpage $i > htmlRecipes/$(echo $i | cut -d '/' -f 3).html
done

./genhome > index.html


sleep 300


done

