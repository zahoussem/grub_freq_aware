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
    double t;
    while (t<= sim_time && !ev_list->size()==0){
      Event *ev = pop_event();
      t=ev->_time();
      (*(ev->process))(ev->_task(), ev->_sig());
    }
  }
}
