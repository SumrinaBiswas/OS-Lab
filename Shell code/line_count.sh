#  Write a shell script to find the number of characters, words and lines in a set of files
#  given by user through the command line argument

# Check if at least one file is provided as an argument

if [ $# -lt 1 ];then
    echo "No file is given through command line "
    exit 1
fi
# Loop through all provided files
for file in "$@"
do
    # Check if the file exists
    if [[ -f "$file" ]]; then
        char=$(wc -c < "$file")
        word=$(wc -w < "$file")
        line=$(wc -l < "$file")

        # Display the results
        echo "File: $file"
        echo "Characters: $char"
        echo "Words: $word"
        echo "Lines: $line"
        echo "-----------------------------"
    else
        echo "$file not found"
    fi
done
