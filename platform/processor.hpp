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
    task::Taskset *tq;
    //    std::priority_queue<int, task::Task> rq;

  public:
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
