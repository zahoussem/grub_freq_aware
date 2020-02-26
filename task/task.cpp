#include "task.hpp"

#include "../common/common.hpp"
namespace task {
  
  Task::Task(int id, int D, int T, double C_fmax){
    this->id = id;
    this->D = D;
    this->T = T;
    this-> C_fmax = C_fmax;
  }

  int _D();
  void _D(int D);
  int _T();
  void _T(int T);
  
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


  
  int Task::arm_act_cont_timer(task::Task *tau){
  // This function adds an event of active_contending to the event list
  return 0; 
}

}
