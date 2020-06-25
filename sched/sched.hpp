#ifndef SCHED_HPP
#define SCHED_HPP

namespace sched
{
  class Scheduler
  {
  public:
    void (*task_arrival)(task::Job *job, int sig);
    void (*task_complete)(task::Job *job, int sig);
    bool (*resched)(task::Runqueue *rq);
    bool (*allocate_task_proc)(task::Task *tau, int alg);
  };
} // namespace sched
#endif