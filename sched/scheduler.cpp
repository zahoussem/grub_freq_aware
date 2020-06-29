#include "scheduler.hpp"

#define N_PROC 2
#define ALLOC BF
#define PARTITIONED 0
#define GLOBAL 1
namespace sched
{

    // Processor runqueue

    // First time blocked
    task::Runqueue *fb_rqs;

    platform::Platform *pl;

    int policy = PARTITIONED;
    int alloc_strategy = BF;

    platform::Processor *allocate_task_proc_rqs(task::Task *tau, platform::Platform *pl)
    {
        if (policy == PARTITIONED)
        {
        }
        else
        {
            PRINT_DEBUG_("Not yet supported, May fail");
        }
        PRINT_DEBUG_("Allocate task to proc rqs \n");
        return NULL;
    }

    void move_task_blocked_rqs(task::Task *tau, platform::Platform *pl)
    {
        PRINT_DEBUG_("Move to blocked called \n");
    }
    void resched(platform::Processor *p)
    {
        PRINT_DEBUG_("RESCHED CALLED \n ");
    }

    void move_task_to_a_rq(task::Task *tau, platform::Processor *p)
    {
        PRINT_DEBUG_("Move to active runqueue called \n");
    }

    void task_preemption(task::Job *j, int sig)
    {
        PRINT_DEBUG_("PREEMPTION CALLED \n");
    }

    void task_arrival(task::Job *j, int sig)
    {
        PRINT_DEBUG_("TASK ARRIVAL ?? \n ");
        if (j->_task()->is_ready())
        {
            if (policy == PARTITIONED)
            {
                platform::Processor *proc = allocate_task_proc_rqs(j->_task(), pl);
                if (proc == NULL) {
                    PRINT_DEBUG_("No room to execute, task will not be executed, all its dependencies will be blocked \n");
                    return; 
                }
                move_task_to_a_rq(j->_task(), proc);
                resched(proc);
            }
            else
            {
                PRINT_DEBUG_("GLOBAL SCHEDULING NOT YET SUPPORTED \n");
            }
        }
        else
        {
            move_task_blocked_rqs(j->_task(), pl);
        }
    }

    void task_completion(task::Job *j, int sig)
    {
    }

} // namespace sched