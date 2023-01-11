/**
 * @file Queue.cpp
 * @author Dany Costa (dany98costa23@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <thread>
#include <condition_variable>
#include <stdlib.h>
#include <unistd.h>
#include "Queue.h" // header in local directory

using namespace std;
using namespace qq;

template<class T>
Queue<T>::Queue (int size_elem){
    
    size = size_elem;
    queue = new T[size_elem];
    head=tail=0;
    pthread_mutex_init(&mutex,0);
}

template<class T>
T Queue<T>::Pop(){
    // wait until queue is not empty
    int count_time=0;
    while(isEmpty())
    {
        // cout << "Queue is empty, waiting...\n";
        sleep(5);
        count_time ++;
    }
    pthread_mutex_lock(&mutex);
    T temp=queue[head];
    //shift all queue
    for(int i=0;i <= tail; i++){
        T elem=queue[i+1];
        queue[i]=elem;
    }
    tail --;
    cout<< "\t\t\t\tPop()->" << temp << "\n";
    printQueue();
    pthread_mutex_unlock(&mutex);
    return temp;
}

template<class T>
void Queue<T>::Push( T element){
    
    while(isFull()){
        sleep(5);
    }
    pthread_mutex_lock(&mutex);
    cout<< "Push(" << element << ")\n";
    queue[tail++]=element;
    printQueue();
    pthread_mutex_unlock(&mutex);            
}
template<class T>
void Queue<T>:: printQueue(){
    cout <<"\t\t";
    for (int i = 0; i <tail; i++) {
        cout << queue[i];
        if(i<tail-1){
            cout << ",";
        }
    }
    cout << "\n";
}
template<class T>
bool Queue<T>::isFull(){
    if(tail == size) return true;
    else return false;
}


