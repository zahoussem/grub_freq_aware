#include "runqueue.hpp"
namespace task {

  /**  
   * setter of id
   * @param id The id to set
   */
  void Runqueue::_id(int id){
    this->id=id;
  }

  /**  
   * Getter of running
   */
  Task * Runqueue::_running(){
    return this->running;
  }
  
  /**
   * setter of running
   * @param running The running to set
   */
  void Runqueue::_running(Task * running){
    this->running=running;
  }

  /**  
       * Getter of a_bw
       */
  double Runqueue::_a_bw(){
      return this->a_bw;
}
  /**
     * setter of a_bw
     * @param a_bw The a_bw to set
     */
  void Runqueue::_a_bw(double a_bw){
      this->a_bw=a_bw;
}
  
  void Runqueue::add_bw(double bw){
    return;
  }


  bool Runqueue::add(Task * tau){
    return true;
  }


  
  bool Runqueue::remove(Task * tau){
    return false;
  }

  bool Runqueue::remove_bw(double bw){
    return true;
  }
  double Runqueue::compute_budget(Task * tau ){
    return 0;
  }
  /**  
   * Getter of id
   */
  int Runqueue::_id(){
    return this->id;
  }

  Task * Runqueue::pick_next_task(){
    return NULL;
  }
  
  int Runqueue::_size(){
    return 0;
  }
}
