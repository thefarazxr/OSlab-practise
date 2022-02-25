echo "Shell Script to search in an array"
echo "Enter array size: "
read size
echo "Enter array values: "
i=0
while [ $i -lt $size ]
do
read a[$i]
i=$((i+1))
done 

echo "Enter Key to search in an array"
read key
i=0
flager=0
while [ $i -lt $size ]
do
if [ $((a[i])) -eq $key ]
then 
    echo "Value found at location $((i+1))"
    flager=1
fi
i=$((i+1))
done 
if [ $flager -eq 0 ] 
then echo "Value not in the array"
fi