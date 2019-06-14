**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Created Process - is a process that has been created but not yet ran.
- User running - A user process and is running.
- Kernel Running Process - A kernel process and is runnig.
- Zombie Process - is a process that has completed it's execution but is still in process table because the parent process has not read it's exit status.
- Preempted - A process switches from kernel to user mode.
- Ready to run in memory - A process that is ready to run in memory and ready to be scheduled by the kernel.
- Ready to run, swapped – Ready to run but no main memory available.
- Sleep, swapped Process - A process that has been swapped to secondary storage and is currently blocked.
- Asleep in memory - In memory but currently blocked.

**2. What is a zombie process?**

- A process that has completed it's execution but is still in process table because the parent process has not read it's exit status.

**3. How does a zombie process get created? How does one get destroyed?**

- Parent process has not read a child's exit status making it (the child process which has finished executing) a zombie process. You destroy a child process by having it's exit status read by the parent with the wait system call which will reap the child from the process table.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- Some benefits of compiled languages versus non-compiled languages are that the compiled languages have higher execution speed because they are converted directly into machine code compared with the non-compiled languages which need to go through compiler first adding an extra step.
