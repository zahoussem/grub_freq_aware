#include "sim_engine.hpp" 
namespace sim_engine {

  SimEngine::SimEngine(){
    this->ev_list = new std::priority_queue<Event *, std::vector<Event *>, CompareEvent>();
  }
  
  Event *  SimEngine::pop_event(){
    Event *ev = ev_list->top();
    ev_list->pop();
    return ev;
  }

  
  void SimEngine::insert_event(Event *ev){
    ev_list->push(ev);
  }

  
  void SimEngine::simulate(double sim_time){
    double t=0;
    printf("here ? \n");
    while (t<= sim_time && !ev_list->size()==0){
      printf("entered ? \n");
      Event *ev = pop_event();
      printf("poped %p \n", ev);
      ev->display();
      printf("not ispl %p \n", ev->_task());
      t=ev->_time();
      (*(ev->process))(ev->_task(), ev->_sig());
    }
  }
}
