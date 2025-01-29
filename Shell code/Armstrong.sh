# echo "Enter a number "
# read n
n=$1
t=$n
m=$n
a=$n
c=0
s=0
while [ $t -ne 0 ] 
do
    c=$((c+1))
    t=$((t/10))
done
echo "No. of digits : $c"
while [ $m -ne 0 ] 
do
    r=$((m % 10))
    p=$(echo "$r ^ $c" | bc)
    s=$((p + s))
    m=$((m / 10))
done
if [ $a -eq $s ];then
echo "Armstrong $n"
else
echo "Not armstrong $n"
fi