#include "task.hpp"

#include "../common/common.hpp"
namespace task {

  /**  
   * setter of proc
   * @param proc The proc to set
   */
  void Task::_proc(platform::Processor * proc){
    this->proc=proc;
  }



  void Task::postpone_d(){
  }
  
  /**  
   * Getter of budget
   */
  double Task::_budget(){
    return this->budget;
  }
  /**
   * setter of budget
   * @param budget The budget to set
   */
  void Task::_budget(double budget){
    this->budget=budget;
  }

  /**  
   * Getter of v
   */
  double Task::_v(){
    return this->v;
  }
  /**
   * setter of v
   * @param v The v to set
   */
  void Task::_v(double v){
    this->v=v;
  }

  void Task::compute_remaining(){
  }
  void Task::update_v(){
  }

  /**  
   * Getter of remaining
   */
  double Task::_remaining(){
    return this->remaining;
  }
  /**
   * setter of remaining
   * @param remaining The remaining to set
   */
  void Task::_remaining(double remaining){
    this->remaining=remaining;
  }

  
  /**  
   * Getter of bw
   */
  double Task::_bw(){
    return this->bw;
  }
  /**
   * setter of bw
   * @param bw The bw to set
   */
  void Task::_bw(double bw){
    this->bw=bw;
  }
  
  /**  
   * Getter of proc
   */
  platform::Processor * Task::_proc(){
    return this->proc;
  }

  /**  
   * Getter of state
   */
  int Task::_state(){
    return this->state;
  }
  /**
   * setter of state
   * @param state The state to set
   */
  void Task::_state(int state){
    this->state=state;
  }

  
  
  Task::Task(int id, int D, int T, double C_fmax){
    this->id = id;
    this->D = D;
    this->T = T;
    this-> C_fmax = C_fmax;
  }

 
  /** 
   *@return : returns the task id 
   */
  int Task::_id(){
    return this-> id;
  }

  /**  
   * setter of id 
   * @param id The id to set 
   */
  void Task::_id(int id){
    this-> id = id;
  }

  /**
   * Display the task informations and content
   */
  void Task::display(){
    std::cout<<"[Task ID:"<<id ;
    std::cout<<"D:"<<_D()<<"T : "<< _T() << std::endl;
  }

  /** 
      Getter of Period T 
  */ 
  int Task::_T(){
    return T;
  }
 
  /**  
   * setter of  T 
   * @param T The Period T to set 
   */
  void  Task::_T(int period){
    this->T = period;
  }

  /** 
      Getter of D 
  */ 
  int Task::_D(){
    return this->D;
  }
  /**  
   * setter of D 
   * @param D The D to set 
   */
  void  Task::_D(int deadline){
    this->D = deadline;
  }


  
  /**
   * Calculate the utilization of the task.
   * @param s : The processor speed
   * @return The task utilization
   */
  double Task::utilization(double s){
    return (C(s))/((double)T);
  }


  double Task::C(double s){
    return C_fmax * s; 
  }
  /**
   * The task destructor 
   */
  Task::~Task(){
  }


  
  int Task::arm_act_cont_timer(double time){
    // This function adds an event of active_contending to the event list
    return 0; 
  }

}
