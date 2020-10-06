//
//  circularqueue.hpp
//  leetcode
//
//  Created by chentao on 2020/10/7.
//

#ifndef circularqueue_hpp
#define circularqueue_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class MyCircularQueue
{
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /* Initialize your data structure here. Set the size of the queue to be k.*/
    MyCircularQueue(int k);
    /* Insert an element into the circular queue. Return true if opearation is successful. */
    bool enQueue(int value);
    /* Delete the element from the circular queue. Return true if opearation is successful. */
    bool deQueue();
    /* Get the front item from queue. */
    int Front();
    /* Get the last item from the queue. */
    int Rear();
    /* Checks wheater the circular queue is empty or not. */
    bool isEmpty();
    /* Checks wheater the circular queue is full or not. */
    bool isFull();
};


#endif /* circularqueue_hpp */

