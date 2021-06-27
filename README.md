# advanced-system-programming
Explore advanced concept of System programming using C, C++ over Linux and UNIX, in some case on Windows as well.

### Table of Contents

Table of contents
=================

<!--ts-->
   * [UNIX System V](#unix-system-v)
      * [IPC](#ipc)
   * [Linux Kernel](#linux-kernel)
   * [My motivation](#my-motivation)
<!--te-->


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
