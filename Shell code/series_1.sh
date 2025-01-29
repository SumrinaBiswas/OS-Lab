# #  Write a shell script to calculate the value of the series: 1+ (x/2)^2–(x/2)3 + (x/2)^4–(x/2)5+...

read -p "Enter x : " x
read -p "Enetr range : " r
a=$x
sum=0
for((i=2; i<=r; i++))
do
    si=$(echo " (-1) ^ $i ")
    # if ((i % 2 == 0)); then
    #     sign=1
    # else
    #     sign=-1
    # fi

    d=$(echo "scale=2; $a / $i" |bc )
    t=$(echo " scale=2; ($a / 2) ^ $i" |bc )
    echo $t
    t1=$(echo "scale=2; $si * $t" | bc)
    echo "term-$i $t1"
    sum=$(echo "scale=2; $sum + $t1" | bc)
done
echo $sum
sum1=$(echo "scale=2; ($sum + 1)" | bc)

echo "Sum is $sum1"
#!/bin/bash

# # Read input values
# read -p "Enter x : " x
# read -p "Enter range : " r

# # Initialize variables
# sum=1
# sign=1  # Start with the first positive term

# # Loop through the series
# for ((i=1; i<=r; i++))
# do
#     # Calculate the term for (x/2)^i
#     term=$(echo "scale=4; ($x / 2) ^ $i" | bc)
    
#     # Alternate the sign of each term
#     if ((i % 2 == 0)); then
#         sign=-1
#     else
#         sign=1
#     fi

#     # Update the sum with the current term multiplied by the sign
#     sum=$(echo "scale=4; $sum + $sign * $term" | bc)
# done

# # Display the final result
# echo "Sum is $sum"
