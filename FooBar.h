//
// Created by Jian Wu on 08/06/2022.
//

#ifndef LEETCODE_FOOBAR_H
#define LEETCODE_FOOBAR_H

#endif //LEETCODE_FOOBAR_H

#include <atomic>
#include <functional>
#include <thread>

using namespace std;

class FooBar {
private:
    int n;
    atomic<bool> fooDone;
public:
    FooBar(int n) {
        this->n = n;
        fooDone = false;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            while (fooDone) {
                this_thread::yield();
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            fooDone = true;
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            while (!fooDone) {
                this_thread::yield();
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            fooDone = false;
        }
    }
};