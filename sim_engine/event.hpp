#ifndef EVENT_HPP
#define EVENT_HPP

#include "../task/job.hpp"
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
    task::Job * job;
    int type;
    int sig;
    int id;
    
  public:
    void assign_signal_process();
    void (*process)(task::Job * job, int sig);
    Event(int id, double time, task::Job * tau, int type, int sig);
    ~Event();
    int _id();
    void _id(int id);
    std::string string_type();
    double _time();
    void _time(double t);
    task::Job * _job();
    void _job(task::Job *job);
    void _type(int type);
    void _sig(int sig);
    int _type();
    int _sig();
    void display();
    
  };

  struct CompareEvent { 
    bool operator()(Event *p1, Event *p2) 
    { 
      return p1->_time() > p2->_time(); 
    } 
  }; 
}

#endif 
