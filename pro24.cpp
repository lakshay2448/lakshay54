#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to perform MergePurge
int merge_purge(const vector<Item>& items, int max_weight) {
    // Sort items based on their weight
    vector<Item> sorted_items = items;
    sort(sorted_items.begin(), sorted_items.end(), [](const Item& a, const Item& b) {
        return a.weight < b.weight;
    });

    // Initialize include and exclude sets
    vector<pair<int, int>> include;
    vector<pair<int, int>> exclude;
    exclude.push_back({0, 0});

    // Iterate through each item
    for (const auto& item : sorted_items) {
        int item_value = item.value;
        int item_weight = item.weight;

        // Create a new set to store potential solutions
        vector<pair<int, int>> new_include;

        // Iterate through the include set
        for (const auto& inc : include) {
            int inc_value = inc.first;
            int inc_weight = inc.second;

            // Check if adding the current item doesn't exceed the maximum weight
            if (inc_weight + item_weight <= max_weight) {
                new_include.push_back({inc_value + item_value, inc_weight + item_weight});
            }
        }

        // Merge the include and exclude sets
        include.insert(include.end(), new_include.begin(), new_include.end());

        // Purge the include set
        for (auto it = include.begin(); it != include.end();) {
            if (it->second > max_weight) {
                it = include.erase(it);
            } else {
                // Check if adding this item can't lead to a better solution
                if (it->first <= item_value) {
                    exclude.push_back(*it);
                }
                ++it;
            }
        }
    }

    // Find the maximum value among include and exclude sets
    int max_value = 0;
    for (const auto& inc : include) {
        max_value = max(max_value, inc.first);
    }
    for (const auto& exc : exclude) {
        max_value = max(max_value, exc.first);
    }
    return max_value;
}

int main() {
    // Example usage:
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // Format: {value, weight}
    int max_weight = 50;
    cout << "Maximum value: " << merge_purge(items, max_weight) << endl;

    return 0;
}