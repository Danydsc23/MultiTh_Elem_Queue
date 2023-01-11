
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <thread>
#include <condition_variable>
#include <stdlib.h>
#include <unistd.h>

#include "Queue.cpp" 

using namespace std;
using namespace qq;

Queue<int> q(2); //element thread safe queue 
void *readThread(void *args ){
        
    for(int i=1;i<=5;i++){
        q.Pop();
    }
    
    return NULL;
}

void *writeThread(void *args){

        for(int i=1;i<=5;i++){
            q.Push(i);
        }
        return NULL;

}  
int main()
{
    pthread_t thread1,thread2;
    int ret1,ret2;
    ret1=pthread_create(&thread1, NULL, writeThread, NULL);
    ret2=pthread_create(&thread2, NULL, readThread, NULL);

    if (ret1!=0){
        perror("pthread_create writeThread failed\n");
        exit(EXIT_FAILURE);
        
    }
    if (ret2!=0){
        perror("pthread_create readThread failed\n");
        exit(EXIT_FAILURE);
        
    }
    pthread_join(thread1,0);
    pthread_join(thread2,0);
  
    return 0;
}
