#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job ID, deadline and profit:\n";
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;

        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    sort(jobs.begin(), jobs.end(), compare);

    int slots = min(n, maxDeadline);
    vector<char> slot(slots, '-');
    vector<bool> filled(slots, false);

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(slots, jobs[i].deadline) - 1;
             j >= 0; j--) {

            if (!filled[j]) {
                slot[j] = jobs[i].id;
                filled[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";

    for (int i = 0; i < slots; i++) {
        if (filled[i])
            cout << slot[i] << " ";
    }

    cout << "\nMaximum Profit: " << totalProfit;

    return 0;
}
