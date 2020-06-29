#include "task_cbs.hpp"

namespace task
{

    Task_CBS::Task_CBS(int id, double D, double T, double C_fmax, Server *s):Task(id, D, T, C_fmax)
    {
        this->server = s;
    }
    
    Task_CBS::~Task_CBS()
    {
    }

    void Task_CBS::_server(Server *s)
    {
        this->server = s;
    }

    task::Server *Task_CBS::_server()
    {
        return this->server;
    }

    double Task_CBS::_bw(double s){
        return server->_bw(s);
    }


} // namespace task