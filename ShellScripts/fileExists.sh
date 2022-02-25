clear
echo "Shell script to find existance of a file"
echo "--------------------------------"
echo "Enter file name"
read fname

if [ ! -f $fname ]
then echo "File not found"
else echo "File exists"
fi

# -e: Returns true value if file exists.
# -f: Return true value if file exists and regular file.
# -r: Return true value if file exists and is readable.
# -w: Return true value if file exists and is writable.
# -x: Return true value if file exists and is executable.
# -d: Return true value if exists and is a directory.