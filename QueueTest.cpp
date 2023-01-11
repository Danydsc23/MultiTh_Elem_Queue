#include <gtest/gtest.h>
#include "Queue.h"


class QueueTest : public ::testing::Test {
protected:
    Queue<int> queue;
};

TEST_F(QueueTest, TestPush) {
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    EXPECT_EQ(queue.size(), 3);
}

TEST_F(QueueTest, TestPop) {
    queue.push(1);
    queue.push(2);
    queue.push(3);
    EXPECT_EQ(queue.Pop(), 1);
    EXPECT_EQ(queue.Pop(), 2);
    EXPECT_EQ(queue.Pop(), 3);
    EXPECT_EQ(queue.size(), 0);
}

TEST_F(QueueTest, TestPush) {
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    EXPECT_EQ(queue.size(), 3);
}
