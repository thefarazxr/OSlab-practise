echo enter a value
read a
if [ $((a%2)) -eq 0 ]
then 
	echo "It's EVEN"
else
	echo "It's ODD"
fi

#if Shows Access Denied on execution
# ls -l ot see all file permissions in that directory.
# r=4 ,w=2, x=1 (read, write , execute )
# then type "chmod 777 file_name.sh"
# -rwxrwxrwx
# owner group others
# 7 7 7
# hence we change permission with chmod 777 etc.