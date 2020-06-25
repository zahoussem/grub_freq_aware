#include "sim_engine.hpp"

namespace sim_engine {


  /**
   * Constructor of sim engine 
   */
  SimEngine::SimEngine(){
    this->ev_list = new std::priority_queue<Event *, std::vector<Event *>, CompareEvent>();
  }

  /** 
   * 1. Extracts the elements on the top 
   * 2. Delete the first element
   * @return return the element on the top of the event list 
   */
  Event *  SimEngine::pop_event(){
    Event *ev = ev_list->top();
    ev_list->pop();
    return ev;
  }



  /** 
   * Inserts an event to event list 
   * @param ev: The event to insert in event list 
   */
  void SimEngine::insert_event(Event *ev){
    ev_list->push(ev);
  }

  /** 
   * Runs the simulation
   * @param sim_time: The simulation time
   */
  double SimEngine::curr_time=0;
  void SimEngine::simulate(double simu_time){    
    while (curr_time<= simu_time && !ev_list->size()==0){
      Event *ev = pop_event();
      curr_time=ev->_time();
      PRINT_DEBUG_("Handling Event  :     ");
      ev->display();
      (*(ev->process))(ev->_job(), ev->_sig());
    }
  }  
}
