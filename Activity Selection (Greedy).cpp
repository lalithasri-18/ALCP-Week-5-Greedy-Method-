#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Activity {
    int start, finish;
    int id;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> arr(n);

    cout << "Enter start and finish times:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
        arr[i].id = i + 1;
    }

    sort(arr.begin(), arr.end(), compare);

    cout << "Selected Activities:\n";

    if (n == 0)
        return 0;

    cout << arr[0].start << " "
         << arr[0].finish << endl;

    int lastFinish = arr[0].finish;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            cout << arr[i].start << " "
                 << arr[i].finish << endl;

            lastFinish = arr[i].finish;
        }
    }

    return 0;
}
