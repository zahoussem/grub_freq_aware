#ifndef EVENT_HPP
#define EVENT_HPP

#include "../task/job.hpp"
#include "../common/common.hpp"
#include "../sched/scheduler.hpp"


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
