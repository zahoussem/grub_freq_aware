#ifndef TASK_CBS_HPP
#define TASK_CBS_HPP 

#include "task.hpp"
#include "server.hpp"

namespace task { 

    class Task_CBS : public Task {
        private  :
            task::Server * server; 
        public : 
            Task_CBS(int id, double D, double T, double C_fmax, Server *s);
            ~Task_CBS();
            void _server(Server *s);
            Server * _server();
            virtual double _bw(double s);
    };
}
#endif 