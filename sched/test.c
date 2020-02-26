#include "NVHOST.h"


int main(void **a){

    dbg_section_begin("Emulation begining time");
    print_spec(curr_time_spec_abs());


    int SIG_SCHED =-1;





    // just for test to be deleted on final
    struct struct_task_gr tau_1={1,to_time_spec(4500,toMillis), to_time_spec( 5000,toMillis),to_time_spec(400,toMillis)};
    struct struct_task_gr tau_2={2,to_time_spec(20,toMillis),to_time_spec(4000,toMillis),to_time_spec(1400,toMillis)};
    struct struct_task_gr tau_3={3,to_time_spec(1300,toMillis),to_time_spec(1500,toMillis),to_time_spec(1400,toMillis)};
    struct struct_task_gr tau_4={4,to_time_spec(1400,toMillis),to_time_spec(1800,toMillis),to_time_spec(1400,toMillis)};
    struct struct_task_gr tau_5={5,to_time_spec(1100,toMillis),to_time_spec(11000,toMillis),to_time_spec(1400,toMillis)};
    struct struct_task_gr tau_6={6,to_time_spec(1200,toMillis),to_time_spec(11500,toMillis),to_time_spec(1400,toMillis)};

    init_gr_task(&tau_1);
    init_gr_task(&tau_2);
    init_gr_task(&tau_3);
    init_gr_task(&tau_4);
    init_gr_task(&tau_5);
    init_gr_task(&tau_6);


    print_task(&tau_1);
    print_task(&tau_2);
    print_task(&tau_3);
    print_task(&tau_4);
    print_task(&tau_5);
    print_task(&tau_6);


    struct struct_task_gr *ts={&tau_1, &tau_2, &tau_3, &tau_4, &tau_5, &tau_6};
    init_main_scheduler();

    int res = GPU_SIGNAL_HANDLER(TASK_ENTERED, tau_1.id,&tau_1);
    if (res){
        dbg_msg("Something went wrong please check 1");
        exit(-1);
    }

    res = GPU_SIGNAL_HANDLER(TASK_ENTERED, tau_2.id,&tau_2);
    if (res){
        dbg_msg("Something went wrong please check 1");
        exit(-1);
    }



    /*res = GPU_SIGNAL_HANDLER(TASK_ENTERED, tau_3.id,&tau_3);
    if (res){
        dbg_msg("Something went wrong please check 1");
        exit(-1);
    }
    res = GPU_SIGNAL_HANDLER(TASK_ENTERED, tau_4.id,&tau_4);
    if (res){
        dbg_msg("Something went wrong please check 1");
        exit(-1);
    }
    res = GPU_SIGNAL_HANDLER(TASK_ENTERED, tau_5.id,&tau_5);
    if (res){
        dbg_msg("Something went wrong please check 1");
        exit(-1);
    }

*/


    res = GPU_SIGNAL_HANDLER(TASK_ARRIVAL, tau_1.id,&tau_1);
    if (res){
        dbg_msg("Something went wrong please check 2");
        exit(-1);
    }



    res = GPU_SIGNAL_HANDLER(TASK_ARRIVAL, tau_2.id,&tau_2);
    if (res){
        dbg_msg("Something went wrong please check 4");
        exit(-1);
    }






    int b=1;
    while(b){
        if (sched_maker.rq_list[0].running->id == 2){



            while (sched_maker.rq_list[0].running->id == 2);
            res = GPU_SIGNAL_HANDLER(TASK_END, tau_2.id,&tau_2);
            if (res){
                dbg_msg("Something went wrong please check 3");
                exit(-1);
            }

            res = GPU_SIGNAL_HANDLER(TASK_END, tau_1.id,&tau_1);
            if (res){
                dbg_msg("Something went wrong please check 5");
                exit(-1);
            }
            b=0;

        }

    }
  //  while(1);


if (DEBUG_MODE)
    dbg_msg("wats");


    /*
    print_sched_current_state();


    dbg_section_end();

    res = GPU_SIGNAL_HANDLER(TASK_END, tau_1.id,&tau_1);
    if (res){
        dbg_msg("Something went wrong please check 3");
        exit(-1);
    }


    print_sched_current_state();

*/





    /*    print_rq_allocated(sched_maker.rq_list[0]);
    dbg_msg("*********************************************************");
    res = GPU_SIGNAL_HANDLER(TASK_EXITED, tau_1.id,&tau_1);
    if (res){
        dbg_msg("Something went wrong please check 2");
        exit(-1);
    }


    print_rq_allocated(sched_maker.rq_list[0]);


    dbg_msg("*********************************************************");

*/


    /*
     *
    while(SIG_SCHED != 9999)
    {
        int result = scanf("Entered Signal %d ", &SIG_SCHED);
        printf("My integer %d",SIG_SCHED);


    }
    */




}
