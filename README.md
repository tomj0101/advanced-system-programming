# advanced-system-programming
Explore advanced concept of System programming using C, C++ over Linux and UNIX, in some case on Windows as well.

### Table of Contents

Table of contents
=================

<!--ts-->

   * [Compiler Optimization flag](#compiler-Optimization-flag)
   * [UNIX System V](#unix-system-v)
      * [IPC](#ipc)
      * [Admin Unix Command](#admin-unix-commands)
   * [Linux Kernel](#linux-kernel)
   * [Installing Enterprise Linux](#installing-enterprise-linux)
   * [My motivation](#my-motivation)
<!--te-->

Compiler Optimization flag
-----

Compiler Optimization flag = GCC optimization levels.

- -O (Same as -O1)
- -O0 (do no optimization, the default if no optimization level is specified)
- -O1 (optimize minimally)
- -O2 (optimize more) # in some academic papers show this one as the one used in the Linux Kernel compilation.
- -O3 (optimize even more)
- -Ofast (optimize very aggressively to the point of breaking standard compliance)
- -Og (Optimize debugging experience. -Og enables optimizations that do not interfere with debugging. It should be the optimization level of choice for the standard edit-compile-debug cycle, offering a reasonable level of optimization while maintaining fast compilation and a good debugging experience.)
- -Os (Optimize for size. -Os enables all -O2 optimizations that do not typically increase code size. It also performs further optimizations designed to reduce code size. -Os disables the following optimization flags: -falign-functions -falign-jumps -falign-loops -falign-labels -freorder-blocks -freorder-blocks-and-partition -fprefetch-loop-arrays -ftree-vect-loop-version)



Other info about the -Ofast is this one:

- -Ofast: Equivalent to -O3 -ffast-math. -ffast-math triggers non-standards-compliant floating point optimizations. This allows the compiler to pretend that floating point numbers are infinitely precise, and that algebra on them follows the standard rules of real number algebra. It also tells the compiler to tell the hardware to flush denormals to zero and treat denormals as zero, at least on some processors, including x86 and x86-64. Denormals trigger a slow path on many FPUs, and so treating them as zero (which does not trigger the slow path) can be a big performance win, but performace is not always equal to the right result.

References: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

```bash
CC=gcc 
# CC=clang++

$ ${CC} file1.cpp file2.cpp file3.cpp \
  -std=c++14  -o app.bin -O3 -g \
  -Wall -Wextra -pendantic \
  -lpthread -lblas -lboost_system -lboost_filesystem \
  -I./include/path1/with/headers1 -I./include2 -L./path/lib1 -L./pathLib2

```


IPC
-----

System V IPC is the name given to three interprocess communication mechanisms that are widely available on UNIX systems: message queues, semaphore, and shared memory.

Before start playing with UNIX environment, we will need any OS based UNIX that use System V, we will used a Vagrant VM for run Openindiana, Openindiana is based on OpenSolaris codebase. 

A commercial UNIX based in System V are AIX (by IBM), Solaris(before SUN, now ORACLE) and HP-UX(by HP).

```bash
➥ cd unix-ipc
➥ vagrant up
➥ vagrant ssh

# make sure the GCC compiler was installed
➥ gcc --version
# output:
gcc (OpenIndiana 8.4.0-oi-2) 8.4.0

# Shutdown the VM
➥ vagrant halt

# Remove the Openindiana from your developer machine
➥ vagrant destroy

```


Admin Unix Command
-----
This is a good helper for your active development task on UNIX System.

```bash
# HP-UX command to get Physical Memory Information
➥ machinfo |grep Memory
# output:
Memory: 130948 MB (127.88 GB)

# OR
➥ /usr/contrib/bin/machinfo |grep Memory
# output:
Memory: 130948 MB (127.88 GB)

# OR
➥ machinfo
# output:
CPU info:
   Intel(R)  Itanium(R)  Processor 9550 (2.39 GHz, 32 MB)
   4 cores, 8 logical processors per socket
   6.38 GT/s QPI, CPU version D0
          Active processor count:
          1 socket
          1 core
          1 logical processor (1 per socket)
          LCPU attribute is disabled

Memory: 130948 MB (127.88 GB)

Firmware info:
   Firmware revision:  02.40
   FP SWA driver revision: 1.23
   IPMI is supported on this system.
   BMC firmware revision: 1.61

Platform info:
   Model:                  "ia64 hp Integrity BL890c i4 nPar"
   Machine ID number:      77398900-da2f-11e2-8084-dee5468e3y7f
   Machine serial number:  SGH319V9YY

OS info:
   Nodename:  PCPEPSVS
   Release:   HP-UX B.11.31
   Version:   U (unlimited-user license)
   Machine:   ia64
   ID Number: 2000259378
   vmunix _release_version:
@(#) $Revision: vmunix:    B.11.31_LR FLAVOR=perf
```

Linux Kernel
-----
The Linux® kernel is the main component of a Linux operating system (OS) and is the core interface between a computer’s hardware and its processes. It communicates between the 2, managing resources as efficiently as possible.


Installing Enterprise Linux
-----
In my case is very common to find RedHat Linux Server like official OS for different big CORE System, some labs environment can run in CentOS, but if is a critical application, usually will require the same OS as production server has. 

Installing CentOS will work for labs and experimental development.
```
# Create boot USB using Linux "Ubuntu 20.04"
# Download CENTOS 7 DVD
wget http://mirror.math.princeton.edu/pub/centos/8.4.2105/isos/x86_64/CentOS-8.4.2105-x86_64-dvd1.iso

# Find out the name of your USB drive with the lsblk command:
$ lsblk

# output
loop73                  7:73   0    11M  1 loop  /snap/nmap/2536
sda                     8:0    0 931.5G  0 disk  
├─sda1                  8:1    0   512M  0 part  /boot/efi
├─sda2                  8:2    0     1K  0 part  
├─sda5                  8:5    0   731M  0 part  /boot
└─sda6                  8:6    0 930.3G  0 part  
  └─sda6_crypt        253:0    0 930.3G  0 crypt 
    ├─vgubuntu-root   253:1    0 929.3G  0 lvm   /
    └─vgubuntu-swap_1 253:2    0   976M  0 lvm   [SWAP]
sdb                     8:16   1   239G  0 disk  /media/developer/CENTOS8DVD


# unmount
sudo umount /media/developer/CENTOS8DVD

# lash the CentOS ISO image to the USB drive
sudo dd bs=4M if=/home/developer/Downloads/CentOS-8.4.2105-x86_64-dvd1.iso of=/media/developer/CENTOS8DVD status=progress oflag=sync

# output
9881780224 bytes (9.9 GB, 9.2 GiB) copied, 50 s, 198 MB/s
2367+1 records in
2367+1 records out
9928966144 bytes (9.9 GB, 9.2 GiB) copied, 50.3358 s, 197 MB/s


```


### My motivation
Be able to clearly communicate deep concepts to my team, sciences college, co-workers and why not, the rest of the world!
