#  a)Write a shell script to calculate the value of the series: x + x2/2! + x4/4! +..

# function fact() {
#     n=$1;
    
#     if [ $n -eq 0 ] || [ $n -eq 1 ];then
#         echo 1
#     else
#         prev=$(fact $((n - 1)))
#         echo $((n * prev))
#     fi
# }
# echo "Enter the value for x :"
# read x
# echo "Enter range : "
# read n
# e=0 
# sum=0
# for((i=0; i<=n; i++)); do
#     f=$(fact $e) # storing factorial value into f
#     t=$(echo "$x ^ $e" | bc)
#     d=$((echo "scale=2; $t / $f" | bc))
#     sum=$((echo " scale=2; $sum + $d" | bc))
#     e=$((e + 2))
# done
# echo "Sum is "
# echo $sum

#!/bin/bash

# Function to calculate factorial
fact() {
    num=$1
    result=1
    for ((i=2; i<=num; i++)); do
        result=$((result * i))
    done
    echo $result
}

# Read user input
echo "Enter the value for x:"
read x
echo "Enter the number of terms (n):"
read n

# Initialize variables
sum=0
e=0

# Loop to calculate series sum
for ((i=0; i<n; i++)); do
    f=$(fact $e)  # Factorial calculation
    t=$(echo "$x ^ $e" | bc)  # Power calculation
    d=$(echo "scale=4; $t / $f" | bc)  # Division with decimal precision
    sum=$(echo "scale=4; $sum + $d" | bc)  # Summing up terms
    e=$((e + 2))  # Increment exponent by 2
done

# Print final result
echo "Sum of the series is: $sum"
