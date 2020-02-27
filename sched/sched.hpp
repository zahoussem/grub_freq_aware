#ifndef SCHED_H
#define SCHED_H

#define DEBUG_MODE

#include "../task/task.hpp"
#include "../task/runqueue.hpp"

namespace sched {
  static double curr_time;
  void move_to_inactive(task::Task * tau);
  void task_arrival(task::Task *tau, int sig);
  void task_complete(task::Task *tau, int sig);
  void act_cont_timer_fired(task::Task *tau, int sig);
  void main_timer_fired(task::Task *tau, int sig);
  bool resched(task::Runqueue *rq); 
}
#endif
