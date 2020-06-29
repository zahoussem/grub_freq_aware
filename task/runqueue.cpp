#include "runqueue.hpp"
namespace task
{

  /**  
   * setter of id
   * @param id The id to set
   */
  void Runqueue::_id(int id)
  {
    this->id = id;
  }

  /**  
   * Getter of running
   */
  Task *Runqueue::_running()
  {
    return this->running;
  }

  /**
   * setter of running
   * @param running The running to set
   */
  void Runqueue::_running(Task *running)
  {
    this->running = running;
  }

  /**  
   * Getter of a_bw
   */
  double Runqueue::_a_bw(double speed)
  {
    return this->a_bw / speed;
  }

  /**
   * setter of a_bw
   * @param a_bw The a_bw to set
   */
  void Runqueue::_a_bw(double a_bw, double speed)
  {
    this->a_bw = a_bw / speed;
  }

  /* 
   * Increases the active bandwiwdth by bw
   * @param bw The bandwidth to add 
   * @param returns true if the added bandwidth is not greater than 1 
   */
  bool Runqueue::add_bw(double bw)
  {
    if (a_bw + bw > 1)
      return false;
    a_bw += bw;
    return true;
  }

  /*
   * Adds Tau to the current runqueue 
   * @param tau The task to add to the current runqueue
   * @return true if adding the task compeletes successfully, otherwise something went wrong 
   */
  bool Runqueue::add_task(Task *tau)
  {
    // Houssam : need to be written
    return true;
  }

  /*
   * Removes The task from the current runqueue 
   * @param tau The task to remove 
   *  @return false if the task is not found
   */
  bool Runqueue::remove_task(Task *tau)
  {
    // Houssam : need to be written
    return false;
  }

  // Computes the total bandwidth
  double Runqueue::_bw(double speed)
  {
    std::vector<Task *>::iterator ptr;
    double bw = 0;
    for (ptr = this->rq_list->begin(); ptr < this->rq_list->end(); ptr++)
      bw += (*ptr)->_bw(speed);
    return bw;
  }

  /**
   * Removes bw for the active bandiwdth 
   * @param bw The bandwidth to remove 
   * @return true if bw can be retrieved, otherwise some thing went wrong 
   */
  bool Runqueue::remove_bw(double bw, double speed)
  {
    if (a_bw - bw / speed < 0)
      return false;
    a_bw -= bw / speed;
    return true;
  }

  /**
   * Compute the budget for a given task 
   * @param tau The task to consider when computing the budget 
   * @return The maximum  budget for task tau 
   */
  double Runqueue::compute_budget(Task *tau)
  {
    // Houssam : compute the budget for the execution task
    return 0;
  }

  /**  
   * Getter of id
   */
  int Runqueue::_id()
  {
    return this->id;
  }

  /**
   * The task to run 
   *@return the most priority task according to a scheduling policy
   */
  Task *Runqueue::pick_next_task()
  {
    // Houssam : returns the next task that can be selected by the
    // scheduler according to the scheduling policy
    return NULL;
  }

  /**
   * The size of the runqueue 
   * @return the size of the runqueue 
   */
  int Runqueue::_size()
  {
    // Houssam : return the size of the runqueue
    return 0;
  }
} // namespace task
