#  24 a) Write a shell script, which shows all prime numbers within a given range. (take the
#  lower & upper range through command line argument)

prime()
{
    p=$1
    f=0
    if [ $p -eq 2 ];then
        echo "Prime $p"
    else
        for((i=2; i<$p; i++)); do
            if [ $((p % i)) -eq 0 ];then
                
                f=0
                break
            else
                f=1
            fi
        done
        if [ $f -eq 1 ];then
            echo "Prime $p"
        else
            echo "not prime $p"
        fi
    fi
}

read -p "Lower range : " m
read -p "Upper range : " n

for((i=$m; i<=$n; i++ ))
do
    (prime $i)
done