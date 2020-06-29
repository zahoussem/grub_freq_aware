#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <vector>
#include "../task/runqueue.hpp"
#include "../task/job.hpp"
#include "../task/task.hpp"
#include "../platform/platform.hpp"

namespace task
{
    class Job;
}
namespace sched
{
    void task_arrival(task::Job *j, int sig);
    void task_completion(task::Job *j, int sig);
    void task_preemption(task::Job *j, int sig);

} // namespace sched

#endif