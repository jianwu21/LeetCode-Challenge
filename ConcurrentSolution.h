//
// Created by Jian Wu on 30/04/2020.
//

#ifndef LEETCODE__CONCURRENTSOLUTION_H
#define LEETCODE__CONCURRENTSOLUTION_H

#include <functional>
#include <semaphore.h>

using namespace std;

class Foo
{
protected:
	sem_t firstJobDone;
	sem_t secondJobDone;

public:
	Foo()
	{
		sem_init(&firstJobDone, 0, 0);
		sem_init(&secondJobDone, 0, 0);
	}

	void first(function<void()> printFirst)
	{
		printFirst();
		sem_post(&firstJobDone);
	}

	void second(function<void()> printSecond)
	{
		sem_wait(&firstJobDone);
		printSecond();
		sem_post(&secondJobDone);
	}

	void third(function<void()> printThird)
	{
		sem_wait(&secondJobDone);
		printThird();
	}
};


#endif //LEETCODE__CONCURRENTSOLUTION_H
