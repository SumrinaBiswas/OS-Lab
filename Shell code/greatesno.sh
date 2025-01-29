#  11. a) Write a shell script to select greatest and lowest numbers from a set of numbers
#  which are present in a file

line=$(wc -l < file_2.txt)
echo "No of line : $line"

greatest=`head -n 1 file_2.txt| tail -n1`
lowest=`head -n 1 file_2.txt| tail -n1`

for((i=0; i<=$line; i++))
do
   
    a=`head -n $i file_2.txt| tail -n1`
    if [ "$greatest" -lt "$a" ];then
        greatest=$a
    fi
    if [ $lowest -gt $a ];then
        lowest=$a
    fi
done

echo "Greatest : $greatest"
echo "Lowest : $lowest"