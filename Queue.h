

#include <pthread.h>
#include <stdlib.h>

namespace qq{

    template<typename T>
    class Queue{
    public:
            /**
            * @brief Construct a new Queue object
            * 
            * @param size 
            */
            Queue<T>(int size_elem);
            /**
            * @brief Increments an element to the end of the queue
            * 
            * @param element 
            */
            void Push( T element);
            /**
            * @brief Removes and returns the last element of the queue
            * 
            * @return T 
            */
            T Pop();
            /**
            * @brief Max number of elements
            * 
            * @return int 
            */
            int Size(){return size;}
            /**
            * @brief  amount of elements stored now
            * 
            * @return int 
            */
            int Count(){return tail;}
            /**
            * @brief Print the actual state of the queue!
            * 
            */
            void printQueue();

            private:
                int head;       // idx where the first element is stored 
                int tail;       // idx where the last element is stored 
                int size;       // total capacity of the queue 
                T *queue;       // array where T values will be stored 
                pthread_mutex_t mutex; // mutex that handles the access of the queue
                /**
                * @brief check if queue is full 
                * 
                * @return true 
                * @return false 
                */
                bool isFull();
                /**
                * @brief check if queue is empty or not
                * 
                * @return true 
                * @return false 
                */
                bool isEmpty(){return(tail==0)? true: false;}
    };    
}
