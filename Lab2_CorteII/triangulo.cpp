#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
 
        // Primera fila siempre es [1]
        triangle.push_back({1});
 
        // Generar las siguientes filas
        for (int i = 1; i < numRows; i++) {
            vector<int> row(i + 1, 1); // cada fila empieza y termina con 1
 
            // Calcular los valores del medio
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
 
            triangle.push_back(row);
        }
 
        return triangle;
    }
};
 
int main() {
    Solution sol;
    int numRows;
 
    cout << "Ingrese el número de filas del Triángulo de Pascal: ";
    cin >> numRows;
 
    vector<vector<int>> result = sol.generate(numRows);
 
    cout << "\nTriángulo de Pascal con " << numRows << " filas:\n";
    for (auto &row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
 
    return 0;
}
 