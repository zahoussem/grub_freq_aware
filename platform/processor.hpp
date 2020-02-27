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

  public:
    task::Runqueue * _rq();
    void _rq(task::Runqueue * rq );
    
    Processor();
    Processor(int id);
    void _id(int id);
    int _id();
    void print_tq();
    void _tq(task::Taskset *ts);
    task::Taskset * _tq();
    Processor* copy();
    bool check_utilization(double speed);

    
  };

}

#endif
