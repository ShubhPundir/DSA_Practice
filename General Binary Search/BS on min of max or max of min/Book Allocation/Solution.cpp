#include <bits/stdc++.h>
using namespace std;

class Solution{
    int allowed(vector<int>& books, int maxPages){
        int student = 1, pageStudent = 0;

        for(int i = 0; i < books.size(); i++){
            if(pageStudent + books[i] <= maxPages){
                pageStudent += books[i];
            } else {
                student++;
            }
        }
        return student;
    }
public:
    int linearViaSliding(vector<int>& books, int students){    
        if(books.size() < students) return -1;
        int surplus = books.size() - students;
        // it means that each student at max might have 1 + surplus books alloted to them.
        // hence it should be a max of sliding window technique. Since all books would be positive.

        int window = 0;
        for(int i = 0; i <= surplus; i++){
            window += books[i];
        }

        int current = window;
        for(int i = 1; i <= books.size() - (surplus + 1); i++){
            current = current - books[i] + books[books.size() - i + 1] ;
            window = max(window, current);
        }
        
        cout << "MAX PAGES: " << window << endl;
        return window;
    }
    int linear(vector<int>& books, int students){
        
        if(books.size() < students) return -1;

        int low = *max_element(books.begin(), books.end());
        int high = accumulate(books.begin(), books.end(), 0);
        int countStudents = 0;

        for(int pages = low; pages <= high; pages++){
            countStudents = allowed(books, pages);

            if(countStudents == students){
                cout << "MAX PAGES: " << pages << endl;
                return pages;
            }
        }
        return -1;
    }

    int bs(vector<int>& books, int students){
        
        if(books.size() < students) return -1;

        int low = *max_element(books.begin(), books.end());
        int high = accumulate(books.begin(), books.end(), 0);
        int ans = -1;

        while (low <= high){
            int mid = (low + high) / 2;
            if(allowed(books, mid) == students){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << "MAX PAGES: " << ans << endl;
        return ans;
    }
};

int main(){
    Solution soln;
    int students = 2; // number of students
    vector<int> books {12, 34, 67, 90};
    // books must not be shared between students. Although, a student might have multiple books.
    // all books must be allocated to the students. Hence, the array must be exhausted
    // books alloted to a single student must be contiguous
    // we have to find out that the maximum number of books alloted to any student must be minimum
    // it will only be max for a student, when the books alloted > 1 and contiguous

    // cout << soln.linearViaSliding(books, students);
    cout << soln.bs(books, students);
    return 0;
}