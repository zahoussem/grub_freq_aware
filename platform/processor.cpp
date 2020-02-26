#include "processor.hpp"

namespace platform{

  Processor::Processor() {
    this->tq = new task::Taskset(-1);
  }

  bool Processor::check_utilization(double speed){
    return tq->utilization(speed)>1;
  }


  
  Processor::Processor(int id) {
    this->id=id; 
    this->tq = new task::Taskset(id);
  }

  /**  
   * setter of id 
   * @param id The id to set 
   */
  void Processor::_id(int id){
    this->id = id;
  }

  /**
   * Getter of id 
   */ 
  int Processor::_id(){
    return id;
  }

  void Processor::print_tq(){
    std::cout<<"[Proc : "<<_id()<<"=> ";
    for (int i=0;i<tq->_size();i++)
      std::cout<<tq->get(i)->_id()<<",";
    std::cout<<"]"<<std::endl;
  }

  /**  
   * setter of tq 
   * @param tq The tq to set 
   */
  void Processor::_tq(task::Taskset *tq){
    this->tq = tq;
  }

  /**
   * Getter of tq 
   */ 
  task::Taskset *Processor::_tq(){
    return tq;
  }


}



