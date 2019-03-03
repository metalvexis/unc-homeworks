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
#include <iostream>
#include "SJF_NONP.h"
#include <locale>  

using namespace std;

int main()
{
  SJF_NONP simulator = SJF_NONP();
  char confirmInput = 'n';
  int pid = 0;
  while( confirmInput != 'y' ){
    int arrivalTime, processingTime;
    
    cout << "PID: " << pid << endl;    
        
    cout << "Input Arrival Time > ";    
    cin >> arrivalTime;
    
    cout << "Input Processing Time > ";
    cin >> processingTime;
    
    simulator.addProcess(arrivalTime, processingTime);
    pid++;
    cout << "Start Simulation ? (y/n) > ";
    cin >> confirmInput;
    
    confirmInput = std::tolower(confirmInput);
    
    cout << endl << endl;
  }
  
  simulator.showTable();
  
  return 0;
}

