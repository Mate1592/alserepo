#include <iostream>
#include <string>
using namespace std;
 
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};
 
int main() {
    Solution s;
    string columnTitle;
 
    cout << "Ingrese el titulo de columna (por ejemplo A, AB, ZY): ";
    cin >> columnTitle;
 
    int number = s.titleToNumber(columnTitle);
    cout << "El numero correspondiente en Excel es: " << number << endl;
 
    return 0;
}