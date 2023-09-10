#SHREYA CHAVAN MT2023179

#Question 1:

#Create the following types of a files using (i) shell command (ii) system call
#a. soft link (symlink system call)
#b. hard link (link system call)
#c. FIFO (mkfifo Library Function or mknod system call)

#Date: 28th August 2023

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


