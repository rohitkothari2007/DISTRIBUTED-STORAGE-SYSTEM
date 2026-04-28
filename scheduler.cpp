#include "../include/scheduler.h"

using namespace std;


// ===============================
// Constructor
// ===============================

Scheduler::Scheduler(int slots) {

    maxSlots = slots;

}



// ===============================
// Assign Deadlines Automatically
// ===============================

void Scheduler::assignDeadlines(
        vector<FileJob> &jobs) {

    cout << "\nAssigning deadlines based on priority...\n";

    for (auto &job : jobs) {

        // Higher priority → earlier deadline

        job.deadline =
            maxSlots -
            (job.priority % maxSlots);

        if (job.deadline <= 0) {

            job.deadline = 1;
        }

        cout << "File: "
             << job.filename
             << " | Priority: "
             << job.priority
             << " | Deadline Assigned: "
             << job.deadline
             << endl;
    }
}



// ===============================
// Greedy Job Scheduling Algorithm
// ===============================

vector<FileJob> Scheduler::scheduleJobs(
        vector<FileJob> jobs) {

    cout << "\nSorting files by priority...\n";


    // Sort by highest priority

    sort(
        jobs.begin(),
        jobs.end(),
        [](FileJob a, FileJob b) {

            return a.priority >
                   b.priority;
        }
    );


    cout << "Sorted order:\n";

    for (auto &job : jobs) {

        cout << job.filename
             << " (Priority "
             << job.priority
             << ")\n";
    }


    // Slot allocation

    vector<int> slots(
        maxSlots,
        -1
    );

    vector<FileJob> result;


    cout << "\nAssigning slots using Greedy method...\n";


    for (int i = 0;
         i < jobs.size();
         i++) {

        for (int j =
             min(
                 maxSlots,
                 jobs[i].deadline
             ) - 1;

             j >= 0;
             j--) {

            if (slots[j] == -1) {

                slots[j] = i;

                result.push_back(
                    jobs[i]
                );

                cout << "Placed "
                     << jobs[i].filename
                     << " into Slot "
                     << j + 1
                     << endl;

                break;
            }
        }
    }


    // Final Output

    cout << "\n--- Final Scheduled Files ---\n";

    for (auto &job : result) {

        cout << job.filename
             << " | Priority: "
             << job.priority
             << " | Deadline: "
             << job.deadline
             << endl;
    }

    return result;
}