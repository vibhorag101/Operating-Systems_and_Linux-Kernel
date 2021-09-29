#! /bin/bash
# A simple command line calculator with arguments and operations passed as arguments
OPERATION="$1"
OP1=$2
OP2=$3
case $OPERATION in
    add)
    echo "Performing addition"
    SUM=$((OP1+OP2))
    echo "Addition is : $SUM"
    ;;

    sub)
    echo "Performing subtraction"
    SUM=$(($OP1-$OP2))
    echo "Subtraction is : $SUM"
    ;;

    div)
    echo "Performing division"
    SUM=$(($OP1/$OP2))
    echo "Division is : $SUM"
    ;;

    exp)
    echo "Performing exponentiation"
    SUM=$(($OP1**$OP2))
    echo "Exponentiation is : $SUM"
    ;;
esac

    
