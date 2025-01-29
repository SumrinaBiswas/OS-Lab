# 28 a) Write a shell script to check how many files in your current directory and display the
#  name of the largest file

count=$(ls -1 | wc -l )
echo "Total file count : $count"

largest=$(ls -S | head -n 1)
echo "The largest file in the current directory is: $largest"
