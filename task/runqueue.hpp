#ifndef RUNQUEUE_HPP
#define RUNQUEUE_HPP


#include "task.hpp"

#include <iostream>

namespace task {

  class Task;
  
  class Runqueue {

  private :
    int id;
    Task *running;
    double a_bw;
    std::vector<Task * > * rq_list;

  public :
    double _a_bw(double speed);
    void _a_bw(double a_bw, double speed);
    int _id();
    void _id(int id);
    Task * _running();
    void _running(Task * tau);
    double compute_budget(Task * tau );
    bool remove_bw(double bw, double speed);
    int _size();
    Task * pick_next_task();
    bool remove_task(Task * tau);
    bool add_task(Task * tau);
    bool add_bw(double bw);
    double _bw(double speed );
  };  
}

#endif 
