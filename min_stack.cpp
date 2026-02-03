#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; 
    stack<int> minStack;  

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() 
{
    MinStack minStack;

    cout << "Pushing values: -2, 0, -3" << endl;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Current minimum: " << minStack.getMin() << endl; 

    cout << "Popping top value" << endl;
    minStack.pop();

    cout << "Top value after pop: " << minStack.top() << endl; 
    cout << "Current minimum: " << minStack.getMin() << endl;  

    cout << "Pushing value: -5" << endl;
    minStack.push(-5);
    cout << "Current minimum: " << minStack.getMin() << endl; 

    return 0;
}
