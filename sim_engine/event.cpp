#include "event.hpp"
#include "../sched/sched.hpp"

namespace sim_engine {

  /**
   * Getter of time 
   */ 
  double Event::_time(){
    return this->time;
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
  task::Job * Event::_job(){
    return this->job;
  }
  /**  
   * setter of task 
   * @param task The task to set 
   */
  void Event::_job(task::Job *job){
    this->job = job;
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

  /** 
   * Constructor of class event
   * @param id The event identifier 
   * @param time the time of the event  
   * @param job The simulated entity
   * @param type the type of the event 
   * @param sig the processing signal
   */ 
  Event::Event(int id, double time, task::Job * job,
	       int type, int sig){
    this->id = id;
    this->time = time;
    this->job = job;
    this->type = type;
    this->sig = sig;
    assign_signal_process();
  }

  /**
   * Prints the event type 
   * Can be reimplemented for other usage of the sim engine 
   */
  std::string Event::string_type(){
    switch(type){
    case TASK_ARRIVAL : return "task_arrival"; 
    case TASK_REBOOTED: return "task_arrival";
    case TASK_KILLED : return "task_compelete";
    case TASK_FINISHED : return "task_compelete"; 
    case ACTIVE_STATE_EXHAUSTED : return "task_complete";
    case CONTENDING_STATE_EXITID : return "task_complete";
    default : return "UNKNOWN"; 
    }
    return "UNKNOWN";
  }

  /**
   * Assigns the processing to achieve for each signal
   * Must be reimplemented for other usage of the sim engine 
   */
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
  /**
   * Destructor of event 
   */
  Event::~Event(){
  }

  /** 
   * Displays the event
   */
  void Event::display(){
    std::cout<<"[Event Id : "<< id <<", TID :"<< job->_task()->_id()<< ", t:"<<time <<// ",
      // Task:"<<task->_id()
      ", Type:"<< this->string_type()<<", Sig:"<<sig <<"]"<<std::endl; 
  } 
}
