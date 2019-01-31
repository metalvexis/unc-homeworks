#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "FCFS.h"
using namespace std;
FCFS::FCFS()
{
  _processes = {};
  _totalProcessTimes = { 0 };
}

void FCFS::addProcess(int arrivalTime, int processTime){
  _process proc;
  proc._processId = _processes.size();
  proc._arrivalTime = arrivalTime;
  proc._processTime = processTime;
  
  _processes.push_back(proc);
  
  computeTime();
}


void FCFS::computeTime(){
  sort( _processes.begin(), _processes.end(), _compareArrivalTime );
  
  _totalProcessTimes.clear();
  _totalProcessTimes.push_back(0);
  
  std::vector<_process>::iterator it;
  int index = 0;
  
  for(it = _processes.begin(); it != _processes.end(); it++, index++ ){  
    _totalProcessTimes.push_back( (*it)._processTime + _totalProcessTimes.at(index) );
  }  
}

void FCFS::showTable(){
  int padding = 15;
  int index = 0;
  vector<_process>::iterator it;
  
  cout << "FCFS Simulation Results" << endl;
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

bool FCFS::_compareArrivalTime( _process proc1, _process proc2){
  return proc1._arrivalTime < proc2._arrivalTime;
}