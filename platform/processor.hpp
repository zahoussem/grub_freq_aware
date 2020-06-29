#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../task/taskset.hpp"
#include "../task/task.hpp"
#include "../task/runqueue.hpp"

#include <climits>



namespace task{
  class Taskset;
  class Task;
  class Runqueue;
}

namespace platform{

  class Processor {
  private:
    int id;
    task::Taskset *tq;
    task::Runqueue *rq; 
    task::Runqueue * a_rqs;
    task::Runqueue * b_rqs;


  public:
    task::Runqueue * _rq();
    void _rq(task::Runqueue * rq );
    

    double _bw(double speed);
    
    Processor();
    Processor(int id);
    void _id(int id);
    int _id();
    void print_tq();
    void _tq(task::Taskset *ts);
    task::Taskset * _tq();
    Processor* copy();
    bool check_bw(double speed);

    
  };

    struct CompareProc { 
    bool operator()(Processor *p1, Processor *p2) 
    { 
      return p1->_bw(1) > p2->_bw(1); 
    } 
  }; 

}

#endif
