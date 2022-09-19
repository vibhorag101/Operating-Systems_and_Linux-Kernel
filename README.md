# Operating System and Linux Kernel projects
This repo contains the Mini Projects based on Operating Systems and Linux Kernel patching.
The mini projects are based on the following topics.
1. CSV Parser using LPThread and Processes.
2. Calling a function by modifying its call stack using Assembly Language and C.
3. IPC using Signals like Sigalarm, Sigkill etc.
4. Making a system call by modifying Linux Kernel to copy data from one matrix to other.
5. Making a sycall to modify the Linux Scheduler to delay a process with a given PID.
6. IPC using UNIX Domain Sockets, FIFO, and Message Queues.
7. Implementing syscalls in Kernel and maintaining sync between them. Using /dev/urandom file and implementing producer-consumer problem.
8. Implementation of Deadlock Prevention using Dinining Philosophers problem.

## Directory Structure
- Assignment_N
- --- Assignment_Subfolder
- ------ Assignment Code Files
- --------Makefile
- --- Problem Statement PDF
- --- Deatiled ProjectReport of the Solution.

## How to run the code
Just run the following commands inside the subfolder having their own makefiles
Note : You need a `UNIX Shell` to execute these commands. If you are a windows guy you can use a `VM` or `WSL`
```
make
then run the main file on terminal using ./main
```
