#ifndef EVENT_HPP
#define EVENT_HPP

#include "../task/task.hpp"
#include "../common/common.hpp"

#define TASK_ARRIVAL 0
#define TASK_KILLED 1 
#define TASK_FINISHED 2 
#define ACTIVE_STATE_EXHAUSTED 3 
#define CONTENDING_STATE_EXITID 4
#define TASK_REBOOTED 5 
namespace sim_engine {

  class Event {
  private : 
    double time;
    task::Task * task;
    int type;
    int sig;
    int id;
    
  public:
    void assign_signal_process();
    void (*process)(task::Task * tau, int sig);
    Event(int id, double time, task::Task * tau, int type, int sig);
    ~Event();
    int _id();
    void _id(int id);
    
    double _time();
    void _time(double t);
    task::Task * _task();
    void _task(task::Task *tau);
    void _type(int type);
    void _sig(int sig);
    int _type();
    int _sig();
    
  };

  struct CompareEvent { 
    bool operator()(Event *p1, Event *p2) 
    { 
      return p1->_time() < p2->_time(); 
    } 
  }; 
}

#endif 
