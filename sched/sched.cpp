#include "sched.hpp"

namespace sched {

  
  
  void move_to_inactive(task::Task * tau){
    #ifdef DEBUG
    printf("move to inactive called \n");
    #else
    task::Runqueue *rq = tau->_proc()->_rq();
    bool res = rq->remove(tau);
    if (!res)
      return ;
    res = rq->add(tau);
    if (!res)
      rq->remove_bw(tau->_bw());
    #endif
  }

  // called when  a new task arrives
  void task_arrival(task::Task *tau, int sig){
#ifdef DEBUG
    printf("Task arrival called with signal %d \n",sig);
#else
    tau->update_v();
    tau->postpone_d();
    task::Runqueue *rq = tau->_proc()->_rq();
    task::Taskset *tq = tau->_proc()->_tq();
    if (sig == 20)
      if (!tq->check_acceptance(tau))
	return;
      else
	tq->add(tau);
    bool res = rq->add(tau);
    if (!res)
      return;
    rq->add_bw(tau->_bw());
    resched(rq);
    #endif
  }

  // called when  a new task arrives
  void task_complete(task::Task *tau, int sig){
#ifdef DEBUG
    printf("Task complete called with signal %d \n",sig);
#else
    tau->update_v();
    task::Taskset  *tq = tau->_proc()->_tq();
    if (tau->_v() > curr_time)
      tau->arm_act_cont_timer(sig);
    else 
      if (sig == 10)
	if (!tq->remove(tau)); 
    return;
    move_to_inactive(tau);
    resched(tau->_proc()->_rq());
    #endif
  }

  // called when  a new task arrives
  void act_cont_timer_fired(task::Task *tau, int sig){
    #ifdef DEBUG
    printf("Active contending timer fired with %d \n",sig);
#else
    if (tau->_state()==ACTIVE_CONTENDING)
      return;
    task::Taskset *tq = tau->_proc()->_tq();
    if (sig == 30)
      if (!tq->remove(tau)); 
    return;  
    move_to_inactive(tau);
    resched(tau->_proc()->_rq());
#endif
  }


  // called when  a new task arrives
  void main_timer_fired(task::Task *tau, int sig){
#ifdef DEBUG
    printf("Task main timer fired with signal %d \n",sig);
#else
    tau->update_v();
    tau->postpone_d();
    resched(tau->_proc()->_rq());
#endif
  }

  bool resched(task::Runqueue *rq){
    if (rq->_size() ==0)
      return true;
    struct struct_task_gr *tau;
    task::Task * m_p = rq->pick_next_task();
    if (m_p != rq->_running())
      {
	if (rq->_running())
	  {
	    rq->_running()->compute_remaining();
	    rq->_running()->update_v();
	  }
	double ba = rq->compute_budget(m_p);
	// Houssam  : the budget assignment bellow must verify that if their is not even until ba, then insert an end event
	// Houssam : The budget needs to be the mini between remaining and ba 
	m_p->_budget(ba);     
	rq->_running(m_p);
      }
    return true;
  }

}
