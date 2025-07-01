#include "MinHeap_Scheduler.h"

int main() {

    int arrivalTimes[] = { 5, 3, 1, 4, 2 };
    int totalTasks = sizeof(arrivalTimes) / sizeof(arrivalTimes[0]);


    MinHeap scheduler;
    scheduler.scheduleTasks(arrivalTimes, totalTasks);

    return 0;
}
