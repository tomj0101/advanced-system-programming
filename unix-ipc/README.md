# quick test
```
gcc sm_server.c -o sm_server.o
gcc sm_client.c -o sm_client.o

./sm_server.o
./sm_client.o
```

#### IPC in more context
```
1- communication between parent and chield process
2- Communication between unrelated process

IPC can use:
- Pipes
- FIFO (First In, Firts Out)
- Message Queues
- Shared Memory
- Semaphores
- Signals


## Pipe (Unnamed Pipes)
Ex: ls -lrt / | more

## FIFO (named pipes)
echo "Great!!" > mypipes
car nypipes

## Shared Memory
ipcs - show information on IPC facilities

gcc sm_server.c -o sm_server.out
./sm_server.out

$ ipcs
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x0000048f 0          tom        <permission>        100        1                       

------ Semaphore Arrays --------
key        semid      owner      perms      nsems 

## Message Queue
- Messages queues are created by a syscall
- Each Read and write creates a syscall to the kernel (BE CAREFULLY)

## Semaphores
- Two types of:
  -> Binary : 0 or 1, true or false
  -> Counting

## Signals
- Are notification of an event occurrence
kill -l 
     -l, --list [signal]
         List signal names.  This option has optional argument, which will convert signal
         number to signal name, or other way round.

$ kill -l 
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX


## Final thoughts and Wrapup
-- Many of the IPC constructs we use today came in Linux came from UNIX System V.
-- POSIX standards now govern the use and definition of IPC constructs
-- POSIX has added a number of modern features like support for threads, etc.


```
