#include <iostream>

#include "sim_engine/sim_engine.hpp"


using namespace std;
int main(int argc, char ** argv){

  platform::Processor * p_1 = new platform::Processor();
  platform::Processor * p_2 = new platform::Processor();
  
  task::Server * s_1 = new task::Server(4,10);
  task::Task * tau_1 = new task::Task(0,25,50,20,s_1);
  task::Server * s_2 = new task::Server(4,10);
  task::Task * tau_2 = new task::Task(1,26,51,21,s_2);

  tau_1->_proc(p_1);
  tau_2->_proc(p_2);
  
  task::Job * j_1 = new task::Job(0,tau_1,21);
  task::Job * j_2 = new task::Job(0,tau_1,19);
  task::Job * j_3 = new task::Job(0,tau_2,21);
  
  
  sim_engine::Event *ev_1 = new sim_engine::Event(0,0,j_1,TASK_ARRIVAL,-1);
  sim_engine::Event *ev_2 = new sim_engine::Event(1,15,j_2,TASK_ARRIVAL,-1);
  sim_engine::Event *ev_3 = new sim_engine::Event(3,31,j_3,TASK_ARRIVAL,-1);


  sim_engine::SimEngine * se = new sim_engine::SimEngine();
  se->insert_event(ev_1);
  se->insert_event(ev_2);
  se->insert_event(ev_3);
  se->simulate(10);  
}
