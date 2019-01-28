#include <vector>
#include <iostream>
#include <algorithm>
#include "FCFS.h"
using namespace std;
FCFS::FCFS()
{
  _processes = {};
  _totalProcessTimes = { 0 };
}

FCFS::~FCFS()
{
}

void FCFS::addProcess(int arrivalTime, int processTime){
  _process proc;
  proc._processId = _processes.size();
  proc._arrivalTime = arrivalTime;
  proc._processTime = processTime;
  
  _processes.push_back(proc);
}


// TODO: Compute Time FCFS
void FCFS::computeTime(){
  sort( _processes.begin(), _processes.end(), _compareArrivalTime );
  
  _totalProcessTimes.clear();
  _totalProcessTimes.push_back(0);
  
  for(it = _processes.begin(); it != _processes.end(); it++, index++ ){  
//    _totalProcessTimes.push_back( it + it. );
  }
//  _totalProcessTimes.push_back();
}

void FCFS::showTable(){
  int index = 0;
  vector<_process>::iterator it;
  

  
  for(it = _processes.begin(); it != _processes.end(); it++, index++ ){
    _process proc = _processes.at(index);
    
    cout << "ProcessId: " << proc._processId << " ";
    
    cout << "ArrivalTime: " << proc._arrivalTime << " ";
    
    cout << "ProcessTime: " << proc._processTime << endl;
  }
}
bool FCFS::_compareArrivalTime( _process proc1, _process proc2){
  return proc1._arrivalTime < proc2._arrivalTime;
}