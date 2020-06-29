#ifndef TASK_FP_HPP
#define TASK_FP_HPP

#include "task.hpp"
#include "server.hpp"

namespace task
{
    class Task_FP : public Task
    {
    private:
        int priority;

    public:
        Task_FP(int id, double D, double T, double C_fmax, int prio);
        ~Task_FP();
        void _priority(int prio);
        int _priority();
    };
} // namespace task
#endif