# Using selection sort logic
echo "Array sorting script"
echo "Enter array size: "
read size
echo "Enter array values: "
i=0
while [ $i -lt $size ]
do
read a[$i]
((i=i+1))
done 

i=0
while [ $i -lt $((size-1)) ]
do
((j=i+1))
while [ $j -lt $size ]
do
if [ $((a[j])) -lt $((a[i]))  ]
then
    ((temp=a[j]))
    ((a[j]=a[i]))
    ((a[i]=temp))
fi
((j=j+1))
done
((i=i+1))
done


echo "----------------------------------------------------------------"
echo "----------------------------------------------------------------"
echo "Sorted Array :"
i=0
while [ $i -lt $size ]
do
echo $((a[i]))
((i=i+1))
done 