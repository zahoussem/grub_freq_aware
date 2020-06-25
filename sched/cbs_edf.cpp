#include "sched.hpp"


namespace sched {
  int alg = 0;
  // platform::Platform * pl;
  // void init_rq_list(int m){
  //   pl=new platform::Platform(m);
  // }

  // Houssam : This function allocates a task to a runqueue
  bool allocate_task_proc(task::Task * tau, int alg){
    // Houssam : I need to write this
    // Houssam : Need to add it here rq->add_bw(tau->_server()->_bw());
    return true;
  }
  
  void move_to_inactive(task::Task * tau){
#ifdef DEBUG
    printf("move to inactive called \n");
#else
    task::Runqueue *rq = tau->_proc()->_rq();
    bool res = rq->remove_task(tau);
    if (!res)
      return ;
    res = rq->add_task(tau);
    if (!res)
      rq->remove_bw(tau->_server()->_bw());
#endif
  }

  // called when  a new task arrives
  void task_arrival(task::Job *job, int sig){
    PRINT_DEBUG_("Task Arrival begin \n");
    task::Task * tau = job->_task();
    tau->_server()->update_v();
    tau->_server()->postpone_d();
    if (sig == 20)
      {
	bool res=allocate_task_proc(tau,alg);
	if (!res)
	  {
	    return;
	  }
      }
    PRINT_DEBUG_("Calling resched From Task Arrival \n");
    resched(tau->_proc()->_rq());
    PRINT_DEBUG_("Task_arrival event end \n");
  }

  // called when  a new task arrives
  void task_complete(task::Job *job, int sig){
    task::Task * tau = job->_task();
#ifdef DEBUG
    printf("Task complete called with signal %d \n",sig);
#else
    tau->_server()->update_v();
    task::Taskset  *tq = tau->_proc()->_tq();
    if (tau->_server()->_v() > sim_engine::SimEngine::curr_time)
      tau->_server()->arm_act_cont_timer(sig);
    else 
      if (sig == 10)
	if (!tq->remove(tau)); 
    return;
    move_to_inactive(tau);
    printf("Calling resched From Task Compeletion \n");
    resched(tau->_proc()->_rq());
#endif
  }

  // called when  a new task arrives
  void act_cont_timer_fired(task::Job *job, int sig){
    task::Task * tau = job->_task();
#ifdef DEBUG
    printf("Active contending timer fired with %d \n",sig);
#else
    if (tau->_server()->_state()==ACTIVE_CONTENDING)
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
  void main_timer_fired(task::Job *job, int sig){
    task::Task * tau = job->_task();
#ifdef DEBUG
    printf("Task main timer fired with signal %d \n",sig);
#else
    tau->_server()->update_v();
    tau->_server()->postpone_d();
    resched(tau->_proc()->_rq());
#endif
  }

  bool resched(task::Runqueue *rq){
    PRINT_DEBUG_("RESCHED STARTED \n");
    if (rq->_size() ==0){
      PRINT_DEBUG_("RUNQUEUE IS EMPTY \n");
      return true;

    }
    PRINT_DEBUG_("RUNQUE is not empty \n");
    task::Task * m_p = rq->pick_next_task();
    if (m_p != rq->_running())
      {
	if (rq->_running())
	  {
	    rq->_running()->_server()->compute_remaining();
	    rq->_running()->_server()->update_v();
	  }
	double ba = rq->compute_budget(m_p);
	// Houssam : the budget assignment bellow must verify that if
	// their is not even until ba, then insert an end event
	
	// Houssam : The budget needs to be the mini between remaining
	// and ba
	m_p->_server()->_budget(ba);     
	rq->_running(m_p);
      }
    return true;
  }

}
