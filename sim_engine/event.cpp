#include "event.hpp"
#include "../sched/sched.hpp"

namespace sim_engine {

  /**
   * Getter of time 
   */ 
  double Event::_time(){
    return  this->time;
  }
  
  /**  
   * setter of time 
   * @param time The time to set 
   */
  void Event::_time(double t){
    this->time = t;
  }
  /**
   * Getter of type 
   */ 
  int Event::_type(){
    return this->type;
  }
  
  /**  
   * setter of type 
   * @param type The type to set 
   */
  void Event::_type(int type){
    this->type=type;
  }


  /**
   * Getter of sig 
   */ 
  int Event::_sig(){
    return this->sig;
  }

  
  /**  
   * setter of sig 
   * @param sig The sig to set 
   */
  void Event::_sig(int sig){
    this->sig = sig;
  }
 
  
  /**
   * Getter of task 
   */ 
  task::Task * Event::_task(){
    return this->task;
  }
  /**  
   * setter of task 
   * @param task The task to set 
   */
  void Event::_task(task::Task *tau){
    this->task = tau;
  }

  /**  
   * setter of id
   * @param id The id to set
   */
  void Event::_id(int id){
    this->id=id;
  }
  
  /**  
   * Getter of id
   */
  int Event::_id(){
    return this->id;
  }

  Event::Event(int id, double time, task::Task * tau,
	       int type, int sig){
    this->time = time;
    this->task = task;
    this->type = type;
    this->sig = sig;
    this->id = id;
    
  }

  void Event::assign_signal_process(){
    switch(type){
    case TASK_ARRIVAL : process = &(sched::task_arrival); sig=20;
      break;
    case TASK_REBOOTED: process = &(sched::task_arrival), sig = 21;
      break;
    case TASK_KILLED : process = &(sched::task_complete), sig = 10;
      break;
    case TASK_FINISHED : process = &(sched::task_complete), sig = 11;
      break;
    case ACTIVE_STATE_EXHAUSTED : process = &(sched::task_complete), sig = 0;
      break;
    case CONTENDING_STATE_EXITID : process = &(sched::task_complete), sig = 0;
      break;
    default : fatal_error(0, "UNDEFINED SIMULATION SIGNAL"); 
    }
  }
  Event::~Event(){
  }

  void Event::display(){
    std::cout<<"[Event Id : "<< id << ", t:"<<time <<// ",
						     // Task:"<<task->_id()
						       ", Type:"<< type<<", Sig:"<<sig <<"]"<<std::endl; 
  }
}
  
