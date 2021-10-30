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


```
