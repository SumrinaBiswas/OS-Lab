# a) Write a shell script to calculate the first n numbers of the Fibonacci series .i.e. 0 1 1 2 3 58…andstore the result in an output file.

# function fib(){
#     n=$1

#     if [ $n -eq 0 ];then
#         echo 1
#     elif [ $n -eq 1 ];then
#         echo 1
#     else
#         prev1=$(fib $((n - 1)))
#         prev2=$(fib $((n - 2)))
#         r=$((prev1 + prev2))
#         echo $r
#     fi
# }

# # Read input from the user
# read -p "Enter the number of Fibonacci terms (n): " n

# # Validate input
# if [ $n -le 0 ]; then
#     echo "Please enter a positive integer greater than 0."
#     exit 1
# fi

# # Generate Fibonacci series
# echo "Fibonacci series (first $n terms):"
# for ((i = 0; i < n; i++)); do
#     fib $i
# done
# Output file

output_file="fibonacci_output.txt"
# Clear the output file if it exists
# > $output_file

read -p "Enter range : " n
a=0
b=1

for((i=0; i<n; i++))
do
    temp=$a
    echo "$a  " >> $output_file
    a=$b
    b=$((temp + b))
done

# Add a newline for clarity between series
echo "" >> $output_file
echo "Fibonacci series stored in $output_file"