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


### head - output the first part of files
```
# Display the first 20 lines of an input file.
head -n 20 < /dev/stdin

# Display the first 20 characters of an input file.
head -c 20 < /dev/stdin

# Display the lines (from line number 12 to 22, both inclusive) of a given text file.
head -n 22 /dev/stdin | tail -n 11
```

### tail - output the last part of file
```
# Display the last 20 lines of an input file.
tail -n 20 < /dev/stdin

# Display the last 20 characters of an input file.
tail -c 20 < /dev/stdin
```
### tr - translate or delete characters
```
# In a given fragment of text, replace all parentheses   with box brackets  [] with ().
tr '()' '[]'  </dev/stdin 
#In: int i=(int)5.8
#Out: int i=[int]5.8

# In a given fragment of text, delete all the lowercase characters a-z.
tr -d [:lower:] </dev/stdin
# In: Hello
# Out: H

# In a given fragment of text, replace all sequences of multiple spaces with just one space.
tr -s ' ' </dev/stdin
# In: Wor  ld
# Out: Wor ld
```


### sort - sort lines of text files
```
# Given a text file, order the lines in lexicographical order.
sort </dev/stdin

# Given a text file, order the lines in reverse lexicographical order (i.e. Z-A instead of A-Z).
sort -r </dev/stdin

# Using sort command to get numeric ascending order
sort -n </dev/stdin
1,2,3,4

# Using sort command to get numeric descending/reverse
sort -nr </dev/stdin
4,3,2,1

# Rearrange the rows of the table in descending order of the values for the average temperature in January (i.e, the mean temperature value provided in the second column)., 2nd column is the temperature, tab separated 
#$ man sort
# -n, --numeric-sort
# -k, --key=KEYDEF, -k2 = 2nd column
# -r, --reverse
# -t, --field-separator=SEP
sort -n -k2 -r -t $'\t'
# Data
#Albany, N.Y.    22.2    46.6    71.1    49.3    38.60    136    64.4    57
#Albuquerque, N.M.    35.7    55.6    78.5    57.3    9.47    60    11.0    64

# Column definition.
#(a) the name of the city (b) the average monthly temperature in Jan (in Fahreneit). (c) the average monthly temperature in April (in Fahreneit). (d) the average monthly temperature in July (in Fahreneit). (e) the average monthly temperature in October (in Fahreneit).

# now sort in ascending order by the 2nd column
sort -n -k2  -t $'\t'

# now sort using other separated
sort -nr -k2  -t $'|'
```
