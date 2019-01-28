/*
 Input pairs consists of :
  no. of process to simulate
  process id
  arrival time
  processing time
  
Output a table with columns and rows for each input pairs:
  PID : the simulated processes
  Arrival Time : arrival time based of input
  Processing Time : process time based of input
  Waiting Time: Total time the process has to wait before it's execution begins. It is the difference between the Turn Around time and the Burst time of the process.
  Turn Around Time: Time taken to complete after arrival. In simple words, it is the difference between the Completion time and the Arrival time.
*/

#include <stdio.h>

#include "FCFS.h"

using namespace std;

int main()
{
  FCFS simulator = FCFS();
  
  simulator.addProcess(3,5);
  simulator.addProcess(2,8);
  simulator.addProcess(1,7);
  
  simulator.showTable();
  return 0;
}

