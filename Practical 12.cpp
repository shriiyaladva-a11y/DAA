
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 2) {
        cout << "Enter at least 2 cities.\n";
        return 0;
    }

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Fix city 0 as the starting city
    vector<int> cities;
    for (int i = 1; i < n; i++) {
        cities.push_back(i);
    }

    int minCost = INT_MAX;
    vector<int> bestPath;

    // Generate every possible order of remaining cities
    do {
        int currentCost = 0;
        int currentCity = 0;

        for (int city : cities) {
            currentCost += cost[currentCity][city];
            currentCity = city;
        }

        // Return to the starting city
        currentCost += cost[currentCity][0];

        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = cities;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    cout << "\nMinimum tour cost: " << minCost;
    cout << "\nOptimal path: 1 ";

    for (int city : bestPath) {
        cout << "-> " << city + 1 << " ";
    }

    cout << "-> 1\n";

    return 0;
}
