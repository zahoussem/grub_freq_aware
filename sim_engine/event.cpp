#include "event.hpp"


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
  Event::~Event(){
  }
}
