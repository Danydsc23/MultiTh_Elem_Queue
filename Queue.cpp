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
#include <mutex>
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
}

template<class T>
T Queue<T>::Pop(){
    unique_lock <mutex>lk(m);
    bool result= condVar.wait_for(lk,chrono::seconds(5), [&]{return !isEmpty();});  
    if(result){
        T temp=queue[head];
        //shift all queue
        for(int i=0;i <= tail; i++){
            T elem=queue[i+1];
            queue[i]=elem;
        }
        tail --;
        cout<< "\t\t\t\tPop()->" << temp << "\n";
        printQueue();
        lk.unlock();
        condVar.notify_one();
        return temp;
    }
    else return false;
}

template<class T>
void Queue<T>::Push( T element){
    
    unique_lock <mutex>lk(m);
    bool result=condVar.wait_for(lk,chrono::seconds(5),[&]{return !isFull();});
    if(result){

        cout<< "Push(" << element << ")\n";
        queue[tail++]=element;
        printQueue();
        lk.unlock();
        condVar.notify_one();
    }else return;
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