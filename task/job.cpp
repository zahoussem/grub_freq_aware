#include "job.hpp"


namespace task {

  /**
   * The constructor of the class Job
   *@param id : The job identifier 
   *@param task : The task  
   *@param C : The job execution time 
   */
  Job::Job(int id, Task * task, double C){
    this->id = id;
    this->task = task;
    this->C =C;
  }

  /**
   * The job destructor 
   */ 
  Job::~Job(){
  }

  /**  
   * Getter of id
   */
  int Job::_id(){
    return this->id;
  }
  /**
   * setter of id
   * @param id The id to set
   */
  void Job::_id(int id){
    this->id=id;
  }

  /**  
   * Getter of task
   */
  Task * Job::_task(){
    return this->task;
  }
  
  /**
   * setter of task
   * @param task The task to set
   */
  void Job::_task(Task * task){
    this->task=task;
  }

  /**  
   * Getter of C
   */
  double Job::_C(){
    return this->C;
  }
  /**
   * setter of C
   * @param C The C to set
   */
  void Job::_C(double C){
    this->C=C;
  }
}
