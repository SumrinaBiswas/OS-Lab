# a) Write a shell script to check if a given date is valid or not

read -p "Enter date in dd/mm/yyyy format : " d

IFS="/"
set $d
dd=$1
mm=$2
yy=$3

if [ $mm -eq 2 ];then
    if [ $((yy % 400)) -eq 0 -o $((yy % 100)) -ne 0 -a $((yy % 4)) -eq 0 ];then
        if [ $dd -le 29 ];then
            echo "Valid date"
        else
            echo "Invalid date"
        fi
    else
        if [ $dd -le 28 ];then
            echo "Valid date"
        else
            echo "Invalid date"
        fi
    fi
elif [ $mm -eq 1 ] || [ $mm -eq 3 ] || [ $mm -eq 5 ] || [ $mm -eq 7 ] || [ $mm -eq 8 ] || [ $mm -eq 10 ] || [ $mm -eq 12 ] ;then
    if [ $dd -le 31 ] && [ $dd -gt 0];then
        echo "Valid date"
    else
        echo "Invalid date"
    fi 
elif [ $mm -eq 4 ] || [ $mm -eq 6 ] || [ $mm -eq 9 ] || [ $mm -eq 11 ];then
    if [ $dd -le 30 ] && [ $dd -gt 0 ];then
        echo "Valid date"
    else
        echo "Invalid date"
    fi 
else
    echo "Invalid date"
fi