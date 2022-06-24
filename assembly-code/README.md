# Assembly Code
#### The first file is a comparation of how different look the assembly code in different platform.
- OS: Linux, CPU: Model name: Intel(R) Xeon(R) CPU E5-4627 v3 @ 2.60GHz  (get info using linux command "lscpu") - VM Server
- OS: Windows, CPU: Intel CORE i5 vPRO 10th Gen, Intel64 Family 6 Model 142 Stepping 12 GenuineIntel ~802 Mhz (get info using powershell command "systeminfo")
- OS: OSX, CPU: Intel(R) Core(TM) i7-5557U CPU @ 3.10GHz. (get info using Terminal command "sysctl -n machdep.cpu.brand_strin")

#### Check the return value.
```
$ ./a.out
$ echo $?
0

#include <stdlib.h>
# return EXIT_SUCCESS; # equals to 0(Zero)
# return EXIT_FAILURE; # equals to 1(One)
```
