#ifndef JOB_HPP
#define JOB_HPP

#include "task.hpp"
#include "../common/common.hpp"

namespace task {
  class Job {

  private :
    int id;
    Task * task;
    double C;

  public:
    Job(int id, Task * task, double C);
    ~Job();
    int _id();
    void _id(int id);
    Task * _task();
    void _task(Task * tau);
    double _C();
    void _C(double C);
  };
}
#endif 
