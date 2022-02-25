echo "Enter the first number :"
read a
echo "Enter the second number :"
read b

echo "Available operations are :"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "Enter your choice of operations"
read c
case $c in
1) res="Addition ="$((a+b));;
2) res="Subtraction ="$((a-b));;
3) res="Multiplication ="$((a*b));;
4) res="Division ="$((a/b));;
*) res="Invalid Operation";;
esac
echo $res
