#ifndef SCHED_H
#define SCHED_H

#include "../common/common.hpp"
#include "../task/job.hpp"
#include "../task/task.hpp"
#include "../task/runqueue.hpp"

#include "../sim_engine/sim_engine.hpp"

namespace sched {
  void move_to_inactive(task::Task * tau);
  void task_arrival(task::Job *job, int sig);
  void task_complete(task::Job *job, int sig);
  void act_cont_timer_fired(task::Job *job, int sig);
  void main_timer_fired(task::Job *job, int sig);
  bool resched(task::Runqueue *rq);
  bool allocate_task_proc(task::Task * tau, int alg);
}
#endif
