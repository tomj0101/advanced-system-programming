# advanced-system-programming
Explore advanced concept of System programming using C, C++ over Linux and UNIX, in some case on Windows as well.

### Table of Contents

Table of contents
=================

<!--ts-->

   * [Compiler Optimization flag](#compiler-Optimization-flag)
   * [UNIX System V](#unix-system-v)
      * [IPC](#ipc)
   * [Linux Kernel](#linux-kernel)
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


Linux Kernel
-----
The Linux® kernel is the main component of a Linux operating system (OS) and is the core interface between a computer’s hardware and its processes. It communicates between the 2, managing resources as efficiently as possible.




### My motivation
Be able to clearly communicate deep concepts to my team, sciences college, co-workers and why not, the rest of the world!
