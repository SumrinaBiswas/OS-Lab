
function pal()
{
    a=$1
    b=$a
    s=0
    while [ $b -ne 0 ]
    do
        rev=$((b % 10))
        s=$(((s * 10) + rev))
        b=$((b / 10))
    done
    if [ $a -eq $s ];then
    echo "Palindrome : $a"
    else
    echo "Not Palindrome : $a" 
    fi
}

#pal $1  // command line argument

# list of command line argument

# Check if at least one number is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <list of numbers>"
    exit 1
fi

# Iterate through the command-line arguments
for number in "$@"; do
    pal "$number"
done