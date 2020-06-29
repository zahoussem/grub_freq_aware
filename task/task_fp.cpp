#include "task_fp.hpp"

namespace task
{
    Task_FP::Task_FP(int id, double D, double T, double C_fmax, int prio) : Task(id, D, T, C_fmax)
    {
        this->priority = prio;
    }

    Task_FP::~Task_FP()
    {
    }

    void Task_FP::_priority(int prio)
    {
        this->priority = prio;
    }

    int Task_FP::_priority()
    {
        return this->priority;
    }

} // namespace task