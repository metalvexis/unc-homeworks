#include <vector>

using namespace std;

#ifndef _FCFS_H_
#define _FCFS_H_

struct _process {
  int _processId;
  int _processTime;
  int _arrivalTime;
};

class FCFS
{
  private:
    
    std::vector<_process> _processes;
    std::vector<int> _totalProcessTimes;
    
    static bool _compareArrivalTime( _process, _process );
  public:
    FCFS();
    
    ~FCFS();
    
    void addProcess( int, int );
    
    void computeTime();
    
    void showTable();

};

#endif // _FCFS_H_
