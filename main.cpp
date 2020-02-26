#include <iostream>

#include "sim_engine/sim_engine.hpp"


using namespace std;
int main(int argc, char ** argv){

  task::Task * tau_1 = new task::Task(0,25,50,20);
  task::Task * tau_2 = new task::Task(0,26,51,21);
  sim_engine::Event *ev_1 = new sim_engine::Event(0,0,tau_1,TASK_ARRIVAL,-1);
  sim_engine::Event *ev_2 = new sim_engine::Event(1,0,tau_1,TASK_ARRIVAL,-1);

  
}
