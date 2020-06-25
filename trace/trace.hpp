#ifndef TRACE_HPP
#define TRACE_HPP

#include <iostream>
#include "../sim_engine/event.hpp"
namespace trace
{

    class Trace
    {
    private:
        sim_engine::Event *ev;
        int ev_type;
        long int b_time;
        long int e_time;
    };

} // namespace trace

#endif