# advanced-system-programming
Explore advanced concept of System programming using C, C++ over Linux and UNIX, in some case on Windows as well.

### Table of Contents

Table of contents
=================

<!--ts-->
   * [UNIX System V](#unix-system-v)
      * [IPC](#ipc)
   * [Linux Kernel](#linux-kernel)
   * [Installing Enterprise Linux](#installing-enterprise-linux)
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
