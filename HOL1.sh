#!/bin/bash
filename="newfile.txt"
softlink="sl.txt"
hardlink="hl.txt"
fifo="fifo.txt"

#this is for softlink
ln -s $filename $softlink

# this is for hardlink
ln $filename $hardlink

#for fifo file
mkfifo $fifo

ls -l > temp.txt
cat temp.txt

rm $softlink $hardlink $fifo "temp.txt"


