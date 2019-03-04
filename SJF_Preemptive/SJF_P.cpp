#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "SJF_P.h"
using namespace std;
SJF_P::SJF_P()
{
  _processes = {};
}

void SJF_P::addProcess(int arrivalTime, int burstTime){
  _process proc = {
    ._processId = _processes.size(), 
    ._arrivalTime = arrivalTime,
    ._burstTime = burstTime
  };
  
  _processes.push_back(proc);
  
  computeTime();
}


void SJF_P::computeTime(){

}



void SJF_P::showTable(){
  int padding = 15;
  int index = 0;
  vector<_process>::iterator it;
  
  cout << "SJF_Preemptive Simulation Results" << endl;
  cout << left;
  cout << setw(padding) << "PID";
  cout << setw(padding) << "ArrivalTime";
  cout << setw(padding) << "BurstTime";
  cout << setw(padding) << "WaitingTime";
  cout << setw(padding) << "TurnAroundTime";
  cout << endl;
  
  for(it = _processes.begin(); it != _processes.end(); it++, index++ ){
    _process proc = _processes.at(index);
    
    cout << setw(padding) << proc._processId;
    cout << setw(padding) << proc._arrivalTime;
    cout << setw(padding) << proc._burstTime;
    cout << endl;
  }
}