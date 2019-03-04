#include <vector>

using namespace std;

#ifndef _SJF_P_H_
#define _SJF_P_H_

struct _process {
  unsigned long int _processId;
  int _arrivalTime;
  int _burstTime;
};

class SJF_P
{
  private:
    
    std::vector<_process> _processes;
    
  public:
    SJF_P();
    
    void addProcess( int, int );
    
    void computeTime();
    
    void showTable();

};

#endif // _SJF_P_H_
