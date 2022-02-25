echo "Shell scripts for Driver's license validation"
echo "Enter your age"
read age
if [ $age -lt 16 ]
    then echo "Sorry You arent elgible now!"
    exit
elif [ $age -eq 16 ] || [ $age -eq 17 ]
then echo "you are elgible for Learners licenese, take this and come after $((18-age)) year(s)"
elif [ $age -ge 18 ]
    then echo "Do you have Learner's license? (Yes=1 No=0)"
    read ll
    if [ $ll -eq 1 ]
    then echo "From how many days u had the Learners license?"
    read days
        if [ $days -ge 30]
        then echo "Okay please proceed to take ur Permanent License"
        else
        echo "Please visit after $((30-days)) days to apply"
        fi
    else 
        echo "Apply first to Learners license"
        exit
fi
fi