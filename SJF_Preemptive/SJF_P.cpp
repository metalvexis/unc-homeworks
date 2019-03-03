#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "SJF_P.h"
using namespace std;
SJF_P::SJF_P()
{
  _processes = {};
  _totalProcessTimes = { 0 };
}

void SJF_P::addProcess(int arrivalTime, int processTime){
  _process proc;
  proc._processId = _processes.size();
  proc._arrivalTime = arrivalTime;
  proc._processTime = processTime;
  
  _processes.push_back(proc);
  
  computeTime();
}


void SJF_P::computeTime(){
  sort( _processes.begin(), _processes.end(), _compareProcessTime );
  
  _totalProcessTimes.clear();
  _totalProcessTimes.push_back(0);
  
  std::vector<_process>::iterator it;
  int index = 0;
  
  for(it = _processes.begin(); it != _processes.end(); it++, index++ ){  
    _totalProcessTimes.push_back( (*it)._processTime + _totalProcessTimes.at(index) );
  }  
}



void SJF_P::showTable(){
  int padding = 15;
  int index = 0;
  vector<_process>::iterator it;
  
  cout << "SJF_Preemptive Simulation Results" << endl;
  cout << left;
  cout << setw(padding) << "PID";
  cout << setw(padding) << "ArrivalTime";
  cout << setw(padding) << "ProcessTime";
  cout << setw(padding) << "WaitingTime";
  cout << setw(padding) << "TurnAroundTime";
  cout << endl;
  
  for(it = _processes.begin(); it != _processes.end(); it++, index++ ){
    _process proc = _processes.at(index);
    
    cout << setw(padding) << proc._processId;
    cout << setw(padding) << proc._arrivalTime;
    cout << setw(padding) << proc._processTime;
    cout << setw(padding) << _totalProcessTimes.at(index);
    cout << setw(padding) << _totalProcessTimes.at(index+1);
    cout << endl;
  }
}

bool SJF_P::_compareArrivalTime( _process proc1, _process proc2){
  return proc1._arrivalTime < proc2._arrivalTime;
}

bool SJF_P::_compareProcessTime( _process proc1, _process proc2){
  return proc1._processTime < proc2._processTime;
}