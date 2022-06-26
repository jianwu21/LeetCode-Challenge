//
// Created by Jian Wu on 23/06/2022.
//

#ifndef LEETCODE_MINSTACK_H
#define LEETCODE_MINSTACK_H

#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> m_stack, min_stack;
public:
    MinStack() {
        min_stack.push(INT32_MAX);
    }

    void push(int x) {
        m_stack.push(x);
        min_stack.push(::min(x, min_stack.top()));
    }

    void pop() {
        m_stack.pop();
        min_stack.pop();
    }

    int top() {
        return m_stack.top();
    }

    int min() {
        return min_stack.top();
    }
};

#endif //LEETCODE_MINSTACK_H

