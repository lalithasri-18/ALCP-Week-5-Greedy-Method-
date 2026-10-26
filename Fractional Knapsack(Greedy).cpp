#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
    int wt, val;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.val / a.wt;
    double r2 = (double)b.val / b.wt;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), compare);

    double profit = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].wt <= W) {
            W = W - arr[i].wt;
            profit += arr[i].val;
        }
        else {
            profit += arr[i].val * ((double)W / arr[i].wt);
            break;
        }
    }
    return profit;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> arr(n);

    cout << "Enter weight and value:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].wt >> arr[i].val;
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum Profit: "
         << fractionalKnapsack(W, arr);

    return 0;
}
