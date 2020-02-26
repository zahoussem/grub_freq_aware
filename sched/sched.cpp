#include "sched.hpp"

void move_to_inactive(task::Task * tau){
  task::runqueue *rq = tau->proc->rq;
  bool res = rq->remove(tau);
  if (!res)
    return ;
  bool res = rq->add(tau);
  if (!res)
    rq->remove_bw(tau->bw); 
}

// called when  a new task arrives
void task_arrival(task::Task *tau, int sig){
  tau->update_v();
  tau->postpone_d();
  task::runqueue *rq = tau->proc->rq;
  task::runqueue *tq = tau->proc->tq;
  if (sig == 20)
    if (!tq->check_acceptance(tau))
      return;
    else
      tq->add(tau);
  bool res = rq->add(tau);
  if (!res)
    return;
  rq->add_bw(tau->bw);
  resched(rq);
}

// called when  a new task arrives
void task_complete(task::Task *tau, int sig){
  tau->update_v();
  task::runqueue *tq = tau->proc->tq;
  if (tau->_v() > curr_time)
    tau->arm_act_cont_timer(sig);
  else 
    if (sig == 10)
      if (!tq->remove(tau)); 
  return;
  move_to_inactive(tau);
  resched(tau->proc->rq;);
}

// called when  a new task arrives
void act_cont_timer_fired(task::Task *tau, int sig){
  if (tau->_state()==ACTIVE)
    return;
  task::runqueue *tq = tau->proc->tq;
  if (sig == 30)
      if (!tq->remove(tau)); 
  return;  
  move_to_inactive(tau);
  resched(tau->proc->rq);
}


// called when  a new task arrives
void main_timer_fired(task::Task *tau, int sig){
  tau->update_v();
  tau->postpone_d();
  resched(tau->proc->rq);
}

int resched(task::Runqueue *rq){
    if (rq->size ==0)
        return SCHED_SUCCES;
    struct struct_task_gr *tau;
    task::Task * m_p = rq->pick_next_task();
    if (m_p != rq->running)
      {
	if (rq->running)
	  {
	    rq->running->compute_remaining();
	    rq->running->update_v();
	  }
      int ba = rq->compute_budget(m_p);
      // the budget assignment bellow must verify that if their is not even until ba, then insert an end event
      m_p->_budget(ba);     
      rq->running = m_p;
      }
    return SCHED_SUCCES;
}
