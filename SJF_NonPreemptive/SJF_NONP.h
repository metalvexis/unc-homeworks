#include <vector>

using namespace std;

#ifndef _SJF_NONP_H_
#define _SJF_NONP_H_

struct _process {
  int _processId;
  int _processTime;
  int _arrivalTime;
};

class SJF_NONP
{
  private:
    
    std::vector<_process> _processes;
    
    std::vector<int> _totalProcessTimes;
    
    static bool _compareArrivalTime( _process, _process );

    static bool _compareProcessTime( _process, _process );
    
  public:
    SJF_NONP();
    
    void addProcess( int, int );
    
    void computeTime();
    
    void showTable();

};

#endif // _SJF_NONP_H_
