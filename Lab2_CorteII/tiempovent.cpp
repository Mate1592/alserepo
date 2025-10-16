#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Precio mínimo visto hasta ahora
        int maxProfit = 0;        // Máxima ganancia posible
 
        for (int price : prices) {
            minPrice = min(minPrice, price);           // Actualiza el mínimo
            maxProfit = max(maxProfit, price - minPrice); // Calcula posible ganancia
        }
 
        return maxProfit;
    }
};
 
int main() {
    Solution sol;
    int n;
 
    cout << "Ingrese el número de días: ";
    cin >> n;
 
    vector<int> prices(n);
    cout << "Ingrese los precios del stock separados por espacio:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
 
    int result = sol.maxProfit(prices);
    cout << "La ganancia máxima posible es: " << result << endl;
 
    return 0;
}