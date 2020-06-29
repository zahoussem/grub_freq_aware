#include "server.hpp"

namespace task
{
  /**
   * The Constructor of the Class server 
   * @param budget The budget that is allocated to the current server
   * @param T The period of the server 
   */
  Server::Server(double budget, double T)
  {
    this->budget = budget;
    this->T = T;
    this->v = 0;
    this->remaining = 0;
    this->d = 0;
    this->state = INACTIVE;
    this->bw = budget / T;
  }
  /**
   * The destructor of the class server 
   */
  Server::~Server()
  {
  }

  /**  
   * Getter of state
   */
  int Server::_state()
  {
    return this->state;
  }
  /**
   * setter of state
   * @param state The state to set
   */
  void Server::_state(int state)
  {
    this->state = state;
  }

  /**  
   * Getter of Ts
   */
  double Server::_T()
  {
    return this->T;
  }
  /**
   * setter of Ts
   * @param Ts The Ts to set
   */
  void Server::_T(double T)
  {
    this->T = T;
  }

  /**  
   * Getter of d
   */
  double Server::_d()
  {
    return this->d;
  }
  /**
   * setter of d
   * @param d The d to set
   */
  void Server::_d(double d)
  {
    this->d = d;
  }

  /**
   * Postpones the current server absolute deadline
   */
  void Server::postpone_d()
  {
    this->d += this->T;
  }

  /**  
   * Getter of budget
   */
  double Server::_budget(double speed)
  {
    return this->budget/speed;
  }
  /**
   * setter of budget
   * @param budget The budget to set
   */
  void Server::_budget(double budget, double speed)
  {
    this->budget = budget/speed;
  }

  /**  
   * Getter of v
   */
  double Server::_v()
  {
    return this->v;
  }
  /**
   * setter of v
   * @param v The v to set
   */
  void Server::_v(double v)
  {
    this->v = v;
  }

  /** 
   * Computing the remaining time to finish the server budget
   */
  void Server::compute_remaining()
  {
    // Houssam : Computes ramaining execution time
  }

  /** 
   * Updating the virtual time 
   */
  void Server::update_v()
  {
    // Houssam : Computes the virtual time!!
    // Need to compute the elapsed time from the latest current
  }

  /**  
   * Getter of remaining
   */
  double Server::_remaining()
  {
    return this->remaining;
  }

  /**
   * setter of remaining
   * @param remaining The remaining to set
   */
  void Server::_remaining(double remaining)
  {
    this->remaining = remaining;
  }

  /**  
   * Getter of bw
   */
  double Server::_bw(double speed)
  {
    return this->bw/speed;
  }

  /**
   * setter of bw
   * @param bw The bw to set
   */
  void Server::_bw(double bw, double speed)
  {
    this->bw = bw/speed;
  }

  /** 
   * Arms the active contending times 
   * @param time The time to wait before signaling 
   * return false if the operation fails
   */
  bool Server::arm_act_cont_timer(double time)
  {
    // Houssam : This function adds an event of active_contending to the event list
    return 0;
  }

} // namespace task
