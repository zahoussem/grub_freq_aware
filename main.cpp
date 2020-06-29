#include <iostream>

#include "task/task.hpp"
#include "task/job.hpp"
#include "task/server.hpp"
#include "task/task_cbs.hpp"

#include "sim_engine/sim_engine.hpp"

int main(int argc, char **argv)
{

  task::Task *tau_1 = new task::Task(0, 25, 50, 10);

  task::Server *s = new task::Server(5, 10);
  task::Task *tau_2 = new task::Task_CBS(1, 26, 50, 5, s);

  task::Job *j_1 = new task::Job(0, tau_1, 21);
  task::Job *j_2 = new task::Job(1, tau_1, 19);
  task::Job *j_3 = new task::Job(0, tau_2, 21);


  sim_engine::Event * ev_1 = new sim_engine::Event(0, 0, j_1, TASK_ARRIVAL,  0);
  sim_engine::Event * ev_2 = new sim_engine::Event(1, 0, j_2, TASK_ARRIVAL,  0);
  sim_engine::Event * ev_3 = new sim_engine::Event(2, 20, j_3, TASK_ARRIVAL,  0);
  
  sim_engine::SimEngine * se = new sim_engine::SimEngine();
  se->insert_event(ev_1);
  se->insert_event(ev_2);
  se->insert_event(ev_3);
  

  se->simulate(50);



}
