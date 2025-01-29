#  9.
#  a) Write a shell script to find the numbers of files are present within a directory and their
#  names. Store the output in a file and display it.

ls > filelist.txt

output_file=filelist.txt

count=0
for file in $(cat filelist.txt)
do
    count=$((count + 1))
done
echo " " >> $output_file
echo "Total files : $count" >> $output_file
