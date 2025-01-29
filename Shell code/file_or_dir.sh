# 22 a) Write a shell script which receives any number of filenames as command line
#  argument. The shell script should check whether every argument supplies are a file or a
#  directory.
#  i)
#  ii)
#  iii)
#  If it is a directory then it should be appropriately reported.
#  if it is a file name then name of the file as well as the no. of lines, words present in it should
#  be reported.
#  Check the file permission for the group. If group has no write permission then gives the write
#  permission or vice versa

#!/bin/bash

# Loop through all command line arguments
for item in "$@"
do
    if [ -d "$item" ]; then
        echo "$item is a directory."
    elif [ -f "$item" ]; then
        echo "$item is a file."
        
        # Count lines and words
        lines=$(wc -l < "$item")
        words=$(wc -w < "$item")
        
        echo "Filename: $item"
        echo "Number of lines: $lines"
        echo "Number of words: $words"
        
        # Check group write permission
        if [ -g "$item" ]; then
            if [ -w "$item" ]; then
                echo "Group has write permission. Removing it."
                chmod g-w "$item"
            else
                echo "Group does not have write permission. Adding it."
                chmod g+w "$item"
            fi
        fi
    else
        echo "$item is not a valid file or directory."
    fi
done
