#include <iostream>
#include <stack>

using namespace std;

void monotone_stack(int* nums) {
    stack<int> st;

    for(int i = 0; i < 8; i++) {
        int num = nums[i];
        while(!st.empty() && num >= st.top()) {
            st.pop();
        }
        st.push(num);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

}

void print(int* nums) {
    for(int i = 0; i < 8; i++) {
        cout << nums[i] << endl;
    }
}

int main() {
    int n = 8;
    int nums[n];

    for(int i = 0; i < n; i++) cin >> nums[i];

    // print(nums);

    monotone_stack(nums);





    return 0;
}