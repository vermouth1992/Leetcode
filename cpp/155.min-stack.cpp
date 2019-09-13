/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (38.64%)
 * Total Accepted:    343.6K
 * Total Submissions: 889.1K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

#include<vector>
#include<iostream>

class MinStack {
private:
    std::vector<std::pair<int, int>> stack;
    int currentMin;

public:
    /** initialize your data structure here. */
    MinStack() {
        currentMin = 0;
    }
    
    void push(int x) {
        if (stack.empty()) {
            currentMin = x;
        } else {
            currentMin = x < currentMin ? x : currentMin;
        }
        stack.emplace_back(std::make_pair(x, currentMin));
    }
    
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
        if (!stack.empty()) {
            currentMin = stack.back().second;
        }
    }
    
    int top() {
        if (!stack.empty()) return stack.back().first;
        else return -1;
    }
    
    int getMin() {
        if (!stack.empty()) return stack.back().second;
        else return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack *stack = new MinStack();
    stack->push(2147483646);
    stack->push(2147483646);
    stack->push(2147483647);
    std::cout << stack->top() << std::endl;
    stack->pop();
    std::cout << stack->getMin() << std::endl;
    stack->pop();
    std::cout << stack->getMin() << std::endl;
    stack->pop();
    stack->push(2147483647);
    std::cout << stack->top() << std::endl;
    std::cout << stack->getMin() << std::endl;
    stack->push(-2147483648);
    std::cout << stack->top() << std::endl;
    std::cout << stack->getMin() << std::endl;
    stack->pop();
    std::cout << stack->getMin() << std::endl;
    delete stack;
    return 0;
}