#  20. a) Write a shell script where you enter birthday in dd/mm/yyyy format. Your age is
#  calculated in years, months & days.

# echo "Enter date of birth (dd/mm/yyyy) : "
# read d
# IFS="/"
# set $d
# bd=$1
# bm=$2
# by=$3

# td=`date +%d`
# tm=`date +%m`
# ty=`date +%y`

# echo "Date of birth : $bd/$bm/$by"
# echo "Todays date is $td/$tm/$ty"

# daydiff=$((td-bd))
# monthdiff=$((tm-bm))
# yeardiff=$((ty-by))

# if [ "$td" -lt "$bd" ]
# then
#     daydiff=$((daydiff+30))
#     monthdiff=$((monthdiff-1))
# fi

# if [ "$tm" -lt "$bm" ]
# then
#     monthdiff=$((monthdiff + 12))
#     yeardiff=$((yeardiff - 1))
# fi



# echo "You are $yeardiff years, $monthdiff months and $daydiff days old"

echo "Enter dob(dd-mm-yyyy): "
read dob

todayDay=$(date +%d)
todayMonth=$(date +%m)
todayYear=$(date +%Y)

dobDay=$(echo "$dob" | cut -d "-" -f 1)
dobMonth=$(echo "$dob" | cut -d "-" -f 2)
dobYear=$(echo "$dob" | cut -d "-" -f 3)

calcDay=0
calcMonth=0
calcYear=0

calcDay=$((todayDay - dobDay))
calcMonth=$((todayMonth - dobMonth))
calcYear=$((todayYear - dobYear))

if ((calcDay < 0)); then
  calcDay=$((calcDay + 30))
  calcMonth=$((calcMonth - 1))
fi

if ((calcMonth < 0)); then
  calcMonth=$((calcMonth + 12))
  calcYear=$((calcYear - 1))
fi

echo "$calcYear years, $calcMonth months and $calcDay days old"