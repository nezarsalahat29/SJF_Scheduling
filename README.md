# SJF_Scheduling

In this assignment, you will implement a simple OS scheduler using C/C++. The scheduler’s task is to
receive a set of processes and their details, and then decide the order of executing these processes
based on the chosen algorithm. Finally, the scheduler will output the order of process execution, in
addition to some stats about each of the processes.

The scheduling algorithm chosen for this assignment will be SJF (Shortest Job First). The input will start
with an integer N, representing the number of processes, followed by N lines (one for each process). For
each line i, the line will start with a string s, representing the process name, followed by 2 numbers
representing the arrival time and processing time for the ith process, respectively.

Your program should print a line indicating the order of executing the processes. Then, for each process,
the program should print a line showing the process’s name, response time, turnaround time, and delay.
See the sample output below for details.

The input will be read from a file (in.txt), and the output should be written to a file (out.txt). The output
format must strictly match the formatting shown in the sample output.
