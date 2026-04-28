#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// ===============================
// File Job Structure
// ===============================

struct FileJob {

    string filename;

    int priority;   // importance of file

    int deadline;   // assigned automatically

};



// ===============================
// Scheduler Class (Greedy)
// ===============================

class Scheduler {

private:

    int maxSlots;   // number of available slots

public:

    // Constructor
    Scheduler(int slots);

    // Assign deadlines automatically
    void assignDeadlines(
        vector<FileJob> &jobs
    );

    // Perform greedy scheduling
    vector<FileJob> scheduleJobs(
        vector<FileJob> jobs
    );

};

#endif