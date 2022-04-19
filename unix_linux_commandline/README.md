# Unix and Linux Commandline

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
