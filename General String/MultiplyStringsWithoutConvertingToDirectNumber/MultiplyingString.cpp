#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();

        // Base conditions
        if(m == 0 || n == 0 || "0" == num1 || "0" == num2) return "0";
        if("1" == num1) return num2;
        if("1" == num2) return num1;

        vector<int> result(n+m, 0);
        // multiply in a reverse fashion
        for(int i = n - 1; i >= 0; --i){
            for(int j = m - 1; j >= 0; --j){
                int product = (num1[i] - '0') * (num2[j] - '0');
                // adding previous values in result array into this product
                product += result[i+j+1];

                // adding the new product into the resultant array;
                result[i + j + 1] = product % 10;
                result[i + j] += product / 10; 
            }
        }

        string s;
        int i = 0;
        // Skip leading zeros
        while (i < result.size() - 1 && result[i] == 0) { // Keep at least one digit if the result is "0"
            i++;
        }

        while (i < result.size()) {
            s += std::to_string(result[i]);
            i++;
        }
        
        return s;
    
    }
};

int main(){
    Solution sol;
    cout << sol.multiply("19","19");

}