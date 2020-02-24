#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../task/taskset.hpp"
#include "../task/task.hpp"

#include <climits>



namespace task{
  class Taskset;
  class Task;
}

namespace platform{

  class Processor {
  private:
    int id;
    task::Taskset *ts;
#ifdef HPC_MODE
    int TAG;
    int policy;
#endif
#ifdef LIMITED_MODE
    std::map<task::Task *, int> *cps;
    double cost;
    int last_q;
#endif
  public:


    /**************************common functions ***********************/
    Processor();
    Processor(int id);
    void _id(int id);
    int _id();
    void print_ts();
    void _ts(task::Taskset *ts);
    task::Taskset * _ts();
    Processor* copy();
    bool check_utilization(double speed);
   
    /************************HPC Mode ************************************/
#ifdef HPC_MODE
    int _TAG();
    void _TAG(int tag);
    Processor(int id, int tag, task::Taskset* ts);
#endif
#ifdef LIMITED_MODE
    double _cost();
    void _cost(double cost);
    void _last_q(int last_q);
    bool test_and_select_optimized(task::Task *tau);
    bool compute_q_and_select_optimized(task::Task *tau);
    int dbf(int D);
    int _last_q();
#endif
  };

}

#endif
