#include "processor.hpp"

namespace platform{

  /** 
   * The constructor of the class processor 
   */
  Processor::Processor() {
    this->tq = new task::Taskset(-1);
  }

  /**
   * Checks the schedulability using utilization based test 
   * @return true if the test succeed, otherwise it returns false
   */
  bool Processor::check_bw(double speed){
    return tq->bw(speed)>1;
  }

  /**  
   * setter of rq
   * @param rq The rq to set
   */
  void Processor::_rq(task::Runqueue * rq){
    this->rq=rq;
  }


  double Processor::_bw(double speed){
    return rq->_bw(speed);
  }
    

  /**  
   * Getter of rq
   */
  task::Runqueue * Processor::_rq(){
    return this->rq;
  }

  /**
   * Constructor of class processor of identifier id 
   * @param id : The identifier of the processor 
   */ 
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

  /* 
   * Prints the task queue allocated to this processor 
   */ 
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
