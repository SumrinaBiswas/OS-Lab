# 12) a) Write a shell script to collect n number of years from command line argument and
#  calculates which years are leap years

if [ ! "$#" ];then
    echo "no input given"
    exit 1
fi

for year in "$@"
do

    if [ $((year % 400)) -eq 0 -o $((year % 100)) -ne 0 -a $((year % 4)) -eq 0 ]
    then
    echo "Leap : $year"
    else
    echo "not Leap : $year"
    fi
done