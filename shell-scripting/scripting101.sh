#! /bin/bash

# ECHO COMMAND
echo "Welcome for the Shell scripting blueprint"
# echo Welcome messages 1!
# echo "Welcome messages 2!"
# echo 'Welcome messages 2!'

# VARIABLES
# Uppercase by convention
# Letters, numbers, underscores
NAME="Tom"
# echo "My name is $NAME"
# echo "My name is ${NAME}"

# USER INPUT
#read -p "Enter your name: " NAME
#echo "Hello $NAME, nice to meet you!"

# SIMPLE IF STATEMENT
# if [ "$NAME" == "Tom" ]
# then
#   echo "Your name is Tom"
# fi

# IF-ELSE
# if [ "$NAME" == "Tom" ]
# then
#   echo "Your name is Tom"
# else 
#   echo "Your name is NOT Tom"
# fi

# ELSE-IF (elif)
# if [ "$NAME" == "Tom" ]
# then
#   echo "Your name is Tom"
# elif [ "$NAME" == "Vike" ]
# then  
#   echo "Your name is Vike"
# else 
#   echo "Your name is NOT Tom or Vike"
# fi

# check if $ORACLE_HOME or $JAVA_HOME variable is a empty string
# if [ -z "$ORACLE_HOME" ]  ||  [ -z "$JAVA_HOME" ] 
# then
#   echo "\$ORACLE_HOME or \$JAVA_HOME are empty"
#   exit 1
# else 
#   echo "Put your code here......."
# fi

# COMPARISON
# NUM1=40
# NUM2=34
# if [ "$NUM1" -gt "$NUM2" ]
# then
#   echo "$NUM1 is greater than $NUM2"
# else
#   echo "$NUM1 is less than $NUM2"
# fi

########
# val1 -eq val2 Returns true if the values are equal
# val1 -ne val2 Returns true if the values are not equal
# val1 -gt val2 Returns true if val1 is greater than val2
# val1 -ge val2 Returns true if val1 is greater than or equal to val2
# val1 -lt val2 Returns true if val1 is less than val2
# val1 -le val2 Returns true if val1 is less than or equal to val2
########

# FILE CONDITIONS
# FILE="test.txt"
# if [ -e "$FILE" ]
# then
#   echo "$FILE exists"
# else
#   echo "$FILE does NOT exist"
# fi

########
# -d file   True if the file is a directory
# -e file   True if the file exists (note that this is not particularly portable, thus -f is generally used)
# -f file   True if the provided string is a file
# -g file   True if the group id is set on a file
# -r file   True if the file is readable
# -s file   True if the file has a non-zero size
# -u    True if the user id is set on a file
# -w    True if the file is writable
# -x    True if the file is an executable
########

#CASE STATEMENT
# read -p "Are you 21 or over? Y/N " ANSWER
# case "$ANSWER" in 
#   [yY] | [yY][eE][sS])
#     echo "You can be a president :)"
#     ;;
#   [nN] | [nN][oO])
#     echo "Sorry, no be a president"
#     ;;
#   *)
#     echo "Please enter y/yes or n/no"
#     ;;
# esac

# SIMPLE FOR LOOP
# NAMES="Python C C++ Perl"
# for NAME in $NAMES
#   do
#     echo "I code in $NAME"
# done

# FOR LOOP TO RENAME FILES
# FILES=$(ls *.txt)
# NEW="new"
# for FILE in $FILES  
#   do
#     echo "Renaming $FILE to new-$FILE"
#     mv $FILE $NEW-$FILE
# done

# WHILE LOOP - READ THROUGH A FILE LINE BY LINE
# LINE=1
# while read -r CURRENT_LINE
#   do
#     echo "$LINE: $CURRENT_LINE"
#     ((LINE++))
# done < "./new-1.txt"

# FUNCTION
# function sayWelcome() {
#   echo "Welcome Mrs."
# }
# sayHello

# FUNCTION WITH PARAMS
# function greet() {
#   echo "Hello, I am $1 and I am $2"
# }

# greet "Tom" "40"

# CREATE FOLDER AND WRITE TO A FILE
# mkdir src
# touch "src/data.txt"
# echo "content for data folder" >> "src/data.txt"
# echo "Created src/data.txt"
