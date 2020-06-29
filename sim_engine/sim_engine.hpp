#ifndef SIM_ENGINE_HPP
#define SIM_ENGINE_HPP

#include <queue>
#include <vector>
#include "../task/task.hpp"
#include "event.hpp"

namespace sim_engine
{

  class SimEngine
  {
  private:
    std::priority_queue<Event *, std::vector<Event *>, CompareEvent> *ev_list;

  public:
    static double curr_time;
    SimEngine();
    ~SimEngine();
    Event *pop_event();
    void insert_event(Event *ev);
    void simulate(double sim_time);
  };
  
} // namespace sim_engine
#endif
