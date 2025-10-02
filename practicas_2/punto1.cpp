#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int *arr = nums.data(); // apuntador al primer elemento del vector

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (*(arr + i) + *(arr + j) == target) { 
                    return {i, j}; 
                }
            }
        }
        return {};
    }
};

int main() {
    int n, target;

    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Ingrese los elementos del arreglo: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Ingrese el valor objetivo (target): ";
    cin >> target;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices encontrados: ";
        for (int i : result) cout << i << " ";
        cout << endl;
    } else {
        cout << "No se encontro una solucion." << endl;
    }

    return 0; 
}
