// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <pb_decode.h>
// #include <pb_encode.h>
// #include <tahu.h>
// #include <tahu.pb.h>
// #include <mach/clock.h>
// #include <mach/mach.h>

// uint64_t get_current_timestamp() {
//     // Set the timestamp
//     struct timespec ts;
// #ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
//     clock_serv_t cclock;
//     mach_timespec_t mts;
//     host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
//     clock_get_time(cclock, &mts);
//     mach_port_deallocate(mach_task_self(), cclock);
//     ts.tv_sec = mts.tv_sec;
//     ts.tv_nsec = mts.tv_nsec;
// #else
//     clock_gettime(CLOCK_REALTIME, &ts);
// #endif
//     return ts.tv_sec * UINT64_C(1000) + ts.tv_nsec / 1000000;
// }
