#ifndef SERVER_HPP
#define SERVER_HPP

#include "../common/common.hpp"
namespace task {

  class Server {

  private :
    double bw;
    double budget;
    double v;
    double remaining;
    double d;
    double T;
    int state;

  public :
    Server(double budget, double T);
    ~Server();
    int _state();
    void _state(int state);
    double _v();
    void _v(double v);    
    double _bw();
    void _bw(double bw);
    void _budget(double budget);
    double _budget();
    void postpone_d();
    void _d(double d);
    double _d();
    double _T();
    void _T(double T);
    bool arm_act_cont_timer(double time);
    double _remaining();
    void _remaining(double remaining);
    void compute_remaining();
    void update_v();
  };

}
#endif 
