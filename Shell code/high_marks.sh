# a) In an input file, there are some records of students (Roll | Name | Marks). Find the
#  student name and roll number of the student who gets the highest marks.

highest=0

# Get the total number of lines in the file
file=student.txt
line=$(wc -l < "$file")
i=1
echo "line : $line"
while [ $i -le $line ]
do
    a=`head -n $i "$file"|tail -n1|cut -d"|" -f1`
    b=`head -n $i "$file"|tail -n1|cut -d"|" -f2`
    c=`head -n $i "$file"|tail -n1|cut -d"|" -f3`

    echo "$a $b $c"

    if [ "$highest" -lt "$c" ];then
        highest=$c
        name=$a
        roll=$b
        count=$i 
    fi
    i=$((i + 1))
done


echo "Highest marks : $highest"
echo "Student's Name : $name"
echo "Roll : $roll"