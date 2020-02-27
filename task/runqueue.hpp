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
  public :

    double _a_bw();
    void _a_bw(double a_bw);
    
    int _id();
    void _id(int id);
    Task * _running();
    void _running(Task * tau);
    double compute_budget(Task * tau );
    bool remove_bw(double bw);
    int _size();
    Task * pick_next_task();
    bool remove(Task * tau);
    bool add(Task * tau);
    void add_bw(double bw);
  };  
}

#endif 
