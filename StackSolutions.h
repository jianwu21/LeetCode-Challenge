//
// Created by Jian Wu on 22/06/2022.
//

#ifndef LEETCODE_STACKSOLUTIONS_H
#define LEETCODE_STACKSOLUTIONS_H

#include <stack>

using namespace std;

class StackSolutions {

};

class CQueue {
private:
    stack<int> m_inStack;
    stack<int> m_outStack;

    void in2out() {
        while (!m_inStack.empty()) {
            m_outStack.push(m_inStack.top());
            m_inStack.pop();
        }
    }
public:
    CQueue() {}

    void appendTail(int value) {
        m_inStack.push(value);
    }

    int deleteHead() {
        if (m_inStack.empty()) return -1;

        while (!m_inStack.empty()){ // 1 -> 2
            int tmp = m_inStack.top();
            m_inStack.pop();
            m_outStack.push(tmp);
        }
        // delete head
        int res = m_outStack.top();
        m_outStack.pop();
        while (!m_outStack.empty()){ // 1 <- 2
            int temp = m_outStack.top();
            m_outStack.pop();
            m_inStack.push(temp);
        }

        return res;
    }
};


#endif //LEETCODE_STACKSOLUTIONS_H
