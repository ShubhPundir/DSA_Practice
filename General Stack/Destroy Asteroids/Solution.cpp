#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack <int> st;

        for(int a: asteroids){
            if(a > 0){
                st.push(a);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -a){
                    st.pop();
                }

                if(st.empty() || st.top() < 0){
                    st.push(a);
                }

                if(!st.empty() && st.top() == -a){
                    st.pop();
                }
            }
        }

        vector<int> res(st.size());
        int i = st.size() - 1;

        while(!st.empty()){
            res[i--] = st.top();
            st.pop();
        }

        return res;
    }
};


int main(){
    vector<int> test = {10, 5, -20};
    Solution soln;
    vector<int> ans = soln.asteroidCollision(test);
    
    for(int a: ans){
        cout << a << " "; 
    }
}