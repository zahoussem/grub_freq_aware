#include "task.hpp"
 
#include "../common/common.hpp"
namespace task {
  
  Task::Task(int id, double D, double T, double C_fmax){
    this->id = id;
    this->D = D;
    this->T = T;
    this-> C_fmax = C_fmax;
  }


  void Task::add_predepandency(Task *tau){
  }
  
  void Task::post_postdepandency(Task *tau){ 
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
  double Task::_T(){
    return T;
  }
 
  /**  
   * setter of  T 
   * @param T The Period T to set 
   */
  void  Task::_T(double period){
    this->T = period;
  }

  /** 
      Getter of D 
  */
  
  double Task::_D(){
    return this->D;
  }
  /**  
   * setter of D 
   * @param D The D to set 
   */
  void Task::_D(double deadline){
    this->D = deadline;
  }
  
  /**
   * Calculate the utilization of the task.
   * @param s : The processor speed
   * @return The task utilization
   */
  double Task::_bw(double s){
    return (C(s))/((double)T);
  }


  bool Task::is_ready(){
    return true;
  }

  /** 
   * Computes the execution time when the processor is operating at speed s 
   * @param s is the processor speed 
   * @return The execution time at speed s
   */
  double Task::C(double s){
    return C_fmax * s; 
  }
  
  /**
   * The task destructor 
   */
  Task::~Task(){

  }
}
