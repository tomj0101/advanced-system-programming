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
   * [Install GCC Compiler on Ubuntu/Xubuntu/Lubuntu](#install-gcc-compiler-on-ubuntu)
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
# Download CentOS 8 DVD
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

Install GCC Compiler on Ubuntu/Xubuntu/Lubuntu
-----
```
# C/C++ Development
sudo apt install build-essential -y
sudo snap install cmake --classic
sudo apt install vim -y
sudo apt install geany -y

# Java Development
sudo apt install default-jre -y && sudo apt install default-jdk -y

# Python
sudo apt install python3 -y
sudo apt install python3-pip -y
# python3 -m http.server 8080
```

Linux Lib:
```
# C++ Library Development files for International Components for Unicode
sudo apt-get install libicu-dev

sudo apt install curl

# development files and documentation for libcurl (OpenSSL flavour)
sudo aptitude install libcurl4-openssl-dev
```

Linux commands:
```
# count files using wc
ls | wc -l
ls /etc | wc -l
```

Install C/C++ on GCP VM :
```
# Google cloud platform instance

tom@dev-vm-machine:~$ uname -a
Linux dev-vm-machine 4.19.0-17-cloud-amd64 #1 SMP Debian 4.19.194-3 (2021-07-18) x86_64 GNU/Linux

tom@dev-vm-machine:~$ sudo apt-get install build-essential
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following additional packages will be installed:
  binutils binutils-common binutils-x86-64-linux-gnu cpp cpp-8 dpkg-dev fakeroot g++ g++-8 gcc gcc-8 libalgorithm-diff-perl libalgorithm-diff-xs-perl
  libalgorithm-merge-perl libasan5 libatomic1 libbinutils libc-dev-bin libc6-dev libcc1-0 libdpkg-perl libfakeroot libfile-fcntllock-perl libgcc-8-dev libgdbm-compat4
  libgomp1 libisl19 libitm1 liblocale-gettext-perl liblsan0 libmpc3 libmpfr6 libmpx2 libperl5.28 libquadmath0 libstdc++-8-dev libtsan0 libubsan1 linux-libc-dev make
  manpages manpages-dev patch perl perl-modules-5.28
Suggested packages:
  binutils-doc cpp-doc gcc-8-locales debian-keyring g++-multilib g++-8-multilib gcc-8-doc libstdc++6-8-dbg gcc-multilib autoconf automake libtool flex bison gdb gcc-doc
  gcc-8-multilib libgcc1-dbg libgomp1-dbg libitm1-dbg libatomic1-dbg libasan5-dbg liblsan0-dbg libtsan0-dbg libubsan1-dbg libmpx2-dbg libquadmath0-dbg glibc-doc git bzr
  libstdc++-8-doc make-doc ed diffutils-doc perl-doc libterm-readline-gnu-perl | libterm-readline-perl-perl libb-debug-perl liblocale-codes-perl
The following NEW packages will be installed:
  binutils binutils-common binutils-x86-64-linux-gnu build-essential cpp cpp-8 dpkg-dev fakeroot g++ g++-8 gcc gcc-8 libalgorithm-diff-perl libalgorithm-diff-xs-perl
  libalgorithm-merge-perl libasan5 libatomic1 libbinutils libc-dev-bin libc6-dev libcc1-0 libdpkg-perl libfakeroot libfile-fcntllock-perl libgcc-8-dev libgdbm-compat4
  libgomp1 libisl19 libitm1 liblocale-gettext-perl liblsan0 libmpc3 libmpfr6 libmpx2 libperl5.28 libquadmath0 libstdc++-8-dev libtsan0 libubsan1 linux-libc-dev make
  manpages manpages-dev patch perl perl-modules-5.28
0 upgraded, 46 newly installed, 0 to remove and 3 not upgraded.
Need to get 57.9 MB of archives.
After this operation, 234 MB of additional disk space will be used.
Do you want to continue? [Y/n] y
Get:1 http://deb.debian.org/debian buster/main amd64 perl-modules-5.28 all 5.28.1-6+deb10u1 [2873 kB]
Get:2 http://security.debian.org/debian-security buster/updates/main amd64 linux-libc-dev amd64 4.19.194-3 [1459 kB]
Get:3 http://deb.debian.org/debian buster/main amd64 libgdbm-compat4 amd64 1.18.1-4 [44.1 kB]    
Get:4 http://deb.debian.org/debian buster/main amd64 libperl5.28 amd64 5.28.1-6+deb10u1 [3894 kB]
Get:5 http://deb.debian.org/debian buster/main amd64 perl amd64 5.28.1-6+deb10u1 [204 kB]
Get:6 http://deb.debian.org/debian buster/main amd64 liblocale-gettext-perl amd64 1.07-3+b4 [18.9 kB]
Get:7 http://deb.debian.org/debian buster/main amd64 manpages all 4.16-2 [1295 kB]
Get:8 http://deb.debian.org/debian buster/main amd64 binutils-common amd64 2.31.1-16 [2073 kB]
Get:9 http://deb.debian.org/debian buster/main amd64 libbinutils amd64 2.31.1-16 [478 kB]
Get:10 http://deb.debian.org/debian buster/main amd64 binutils-x86-64-linux-gnu amd64 2.31.1-16 [1823 kB]
Get:11 http://deb.debian.org/debian buster/main amd64 binutils amd64 2.31.1-16 [56.8 kB]
Get:12 http://deb.debian.org/debian buster/main amd64 libc-dev-bin amd64 2.28-10 [275 kB]
Get:13 http://deb.debian.org/debian buster/main amd64 libc6-dev amd64 2.28-10 [2691 kB]
Get:14 http://deb.debian.org/debian buster/main amd64 libisl19 amd64 0.20-2 [587 kB]
Get:15 http://deb.debian.org/debian buster/main amd64 libmpfr6 amd64 4.0.2-1 [775 kB]
Setting up libmpfr6:amd64 (4.0.2-1) ...
Setting up libquadmath0:amd64 (8.3.0-6) ...
Setting up libmpc3:amd64 (1.1.0-1) ...
Setting up libatomic1:amd64 (8.3.0-6) ...
Setting up patch (2.7.6-3+deb10u1) ...
Setting up libgdbm-compat4:amd64 (1.18.1-4) ...
Setting up libperl5.28:amd64 (5.28.1-6+deb10u1) ...
Setting up libmpx2:amd64 (8.3.0-6) ...
Setting up libubsan1:amd64 (8.3.0-6) ...
Setting up libisl19:amd64 (0.20-2) ...
Setting up libbinutils:amd64 (2.31.1-16) ...
Setting up cpp-8 (8.3.0-6) ...
Setting up libc-dev-bin (2.28-10) ...
Setting up libcc1-0:amd64 (8.3.0-6) ...
Setting up liblocale-gettext-perl (1.07-3+b4) ...
Setting up liblsan0:amd64 (8.3.0-6) ...
Setting up libitm1:amd64 (8.3.0-6) ...
Setting up binutils-x86-64-linux-gnu (2.31.1-16) ...
Setting up libtsan0:amd64 (8.3.0-6) ...
Setting up manpages-dev (4.16-2) ...
Setting up binutils (2.31.1-16) ...
Setting up perl (5.28.1-6+deb10u1) ...
Setting up libdpkg-perl (1.19.7) ...
Setting up libgcc-8-dev:amd64 (8.3.0-6) ...
Setting up cpp (4:8.3.0-1) ...
Setting up libc6-dev:amd64 (2.28-10) ...
Setting up libstdc++-8-dev:amd64 (8.3.0-6) ...
Setting up gcc-8 (8.3.0-6) ...
Setting up libfile-fcntllock-perl (0.22-3+b5) ...
Setting up libalgorithm-diff-perl (1.19.03-2) ...
Setting up gcc (4:8.3.0-1) ...
Setting up dpkg-dev (1.19.7) ...
Setting up g++-8 (8.3.0-6) ...
Setting up libalgorithm-diff-xs-perl (0.04-5+b1) ...
Setting up libalgorithm-merge-perl (0.08-3) ...
Setting up g++ (4:8.3.0-1) ...
update-alternatives: using /usr/bin/g++ to provide /usr/bin/c++ (c++) in auto mode
Setting up build-essential (12.6) ...
Processing triggers for man-db (2.8.5-2) ...
Processing triggers for libc-bin (2.28-10) ...
```

### Process on Linux
```
ps, top, htop
```

### Memory management
```
$ gcc main.c -o main
$ size main
   text    data     bss     dec     hex filename
   1755     600       8    2363     93b main

$ size /usr/bin/more
   text    data     bss     dec     hex filename
  32936    1236      64   34236    85bc /usr/bin/more

$ readelf -a /usr/bin/more | more
```

### Linux SysCalls
```
# Linux kernel subsystems:
- SCHED: The Process scheduler
- MM: The memory manager
- VFS: The Virtual File system
- NET: The Network interface
- IPC: The inter-Process Communication

strace - trace system calls and signals

$ strace -p <PID>
$ strace -h

### strace C program
$ strace /home/tom/main
execve("/home/tomas/main", ["/home/tom/main"], 0x7ffc7207e160 /* 20 vars */) = 0
brk(NULL)                               = 0x55805afa4000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=39932, ...}) = 0
mmap(NULL, 39932, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fa70cfe1000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\260A\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1824496, ...}) = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fa70cfdf000
mmap(NULL, 1837056, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fa70ce1e000
mprotect(0x7fa70ce40000, 1658880, PROT_NONE) = 0

$ strace hostname
L1 munmap(0x7fd1c6eb6000, 39932)           = 0
L2 brk(NULL)                               = 0x55c807862000
L3 brk(0x55c807883000)                     = 0x55c807883000
L4 uname({sysname="Linux", nodename="dev-vm-machine", ...}) = 0
L5 fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
L6 write(1, "dev-vm-machine\n", 15dev-vm-machine
)        = 15
L7 exit_group(0)                           = ?
L8 +++ exited with 0 +++

analysis: in the line L4 we can see hostname internally call uname command that means is the same to run this command:
$ uname -n


Others system calls:
- Exit
- Wait
- Read
- Write
- Open
- Close
- Waitpid
- Getpid
- Sync
- Nice
- Kill
```

### Linux Virtual File System (VFS)
```
$ echo "Printing VFS in terminal" > /dev/pts/0
Printing VFS in terminal


```

### Linux Networking
```
The world runs on the sockets - a quote in the UNIX summit at Univ of Kansas in 1989.
- Networking started as number of research project like:
  - NPL network in the UK
  - ARPANet in the USA
  - CYCLADES in Frances
  - European Informatics Network (EIN)
  - IBM's Systems Network Architect
  - Digital Equipment Corporations DECNet
  - X.25 Protocol

- Organization Like:
  - IEEE
  - IETF
  - ISO
  - CCITT / ITU

Socket:
- Endianess is the way computers store bytes in memory.
- Big Endian, Little Endian. 
```


### My motivation
Be able to clearly communicate deep concepts to my team, sciences college, co-workers and why not, the rest of the world!
