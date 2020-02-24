#include "processor.hpp"

namespace platform{

  /***********************common functions ***********************************/
  Processor::Processor() {
    this->ts = new task::Taskset(-1);
  }

  bool Processor::check_utilization(double speed){
    return ts->utilization(speed)>1;
  }

  Processor::Processor(int id) {
    this->id=id; 
    this->ts = new task::Taskset(id);
  }

  void Processor::_id(int id){
    this->id = id;
  }
  
  int Processor::_id(){
    return id;
  }

  void Processor::print_ts(){
    std::cout<<"[Proc : "<<_id()<<"=> ";
    for (int i=0;i<ts->_size();i++)
      std::cout<<ts->get(i)->_id()<<",";
    std::cout<<"]"<<std::endl;
  }
    
  void Processor::_ts(task::Taskset *ts){
    this->ts = ts;
  }

  task::Taskset *Processor::_ts(){
    return ts;
  }


}



