# Unix and Linux Commandline
### Don't forget tge basic
read, echo, printf, loop, if, elfi  

### bc - An arbitrary precision calculator language
```
paramters:
-l, --mathlib
              Define the standard math library.
              
$ echo "4/3" | bc -l
1.33333333333333333333

printf "%.3f \n" `echo "4/3" | bc -l`
1.333


$ printf "%.3f \n" `echo "sqrt(25)" | bc -l`
5.000 

Math Library:

       s (x)  The sine of x, x is in radians.

       c (x)  The cosine of x, x is in radians.

       a (x)  The arctangent of x, arctangent returns radians.

       l (x)  The natural logarithm of x.

       e (x)  The exponential function of raising e to the value x.

       j (n,x)
              The Bessel function of integer order n of x.
```

### cut - remove sections from each line of files
```
Display the  2 and 7 character from each line of text of the stdin
$ cut -c 2,7 /dev/stdin

Input (stdin)
Hello
World
how are you

Expected Output
e
o
oe

Display a range of characters starting at the 2 position of a string and ending at the 7 position
$ cut -c 2-7 /dev/stdin

Given a tab delimited file with several columns (tsv format) print the first three fields.
$ cut -d $'\t' -f -3 /dev/stdin

Print the characters from thirteenth position to the end.
cut -c 13- /dev/stdin

Given a sentence, identify and display its fourth word. Assume that the space (' ') is the only delimiter between words.
$ cut -d ' ' -f 4 /dev/stdin

Given a sentence, identify and display its first three words. Assume that the space (' ') is the only delimiter between words.
$ cut -d ' ' -f -3 /dev/stdin
$ cut -d ' ' -f 1-3 /dev/stdin
both parameters are the same 1-3 and -3

Given a tab delimited file with several columns (tsv format) print the fields from second fields to last field.
$ cut -d $'\t' -f 2- /dev/stdin


```
