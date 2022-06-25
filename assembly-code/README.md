# Assembly Code
```
gcc -S main.c
```
#### The first file is a comparation of how different look the assembly code in different platform.
- OS: Linux, CPU: Model name: Intel(R) Xeon(R) CPU E5-4627 v3 @ 2.60GHz  (get info using linux command "lscpu") - VM Server
- File: main.s-linux-rhel-8-server.txt
---
- OS: Linux, CPU: Intel(R) Core(TM) i5-6440HQ CPU @ 2.60GHz (get info using linux command "lscpu") - Laptop
- File: main.s-linux-ubuntu-20.04-laptop-2.txt
---
- OS: Windows, CPU: Intel CORE i5 vPRO 10th Gen, Intel64 Family 6 Model 142 Stepping 12 GenuineIntel ~802 Mhz (get info using powershell command "systeminfo")
- File: main.s-windows-thinkpad-laptop.txt
---
- OS: OSX, CPU: Intel(R) Core(TM) i7-5557U CPU @ 3.10GHz. (get info using Terminal command "sysctl -n machdep.cpu.brand_string")
- File: main.s-osx-macbook-pro-laptop.txt
---
- OS: OSX, CPU: Intel(R) Core(TM) i5-5257U CPU @ 2.70GHz (get info using Terminal command "sysctl -n machdep.cpu.brand_string")
- File: main.s-osx-macbook-pro-laptop-2.txt

#### Check the return value.
```
$ ./a.out
$ echo $?
0

#include <stdlib.h>
# return EXIT_SUCCESS; # equals to 0(Zero)
# return EXIT_FAILURE; # equals to 1(One)
```
