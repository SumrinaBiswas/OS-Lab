# a) Write a shell script to determine the Grade as per WBUT rule. Students name, roll no
#  and marks are taken from an input file and output will store as student name , roll no,
#  marks and grade format in a file.( using case)

line=$(wc -l < student.txt)

#create output file
> grade.txt

grades()
{
    m=$1

    case $m in
        9[0-9]|100) echo "O" ;;
        8[0-9]) echo "E";;
        7[0-9]) echo "A";;
        6[0-9]) echo "B";;
        5[0-9]) echo "C";;
        4[0-9]) echo "D";;
        *) grade="F";;
    esac
}

for((i=0; i<=$line; i++))
do
    a=`head -n $i student.txt| tail -n1| cut -d "|" -f1`
    b=`head -n $i student.txt| tail -n1| cut -d "|" -f2`
    c=`head -n $i student.txt| tail -n1| cut -d "|" -f3`

    g=$(grades "$c")

    # Append the result to the output file
    echo "$a|$b|$c|$g" >> grade.txt
done