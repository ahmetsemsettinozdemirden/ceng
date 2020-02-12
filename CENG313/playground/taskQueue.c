#include <stdlib.h>
#include <time.h>
#include "taskQueue.h"

TaskNode* createTaskNode(int task_num, int task_type, int value) {
    TaskNode* newNode = malloc(sizeof(TaskNode));
    newNode->task_num = task_num;
    newNode->task_type = task_type;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Generate n random tasks for the task queue
TaskNode* generateTaskQueue(int n) {
    srand(time(NULL)); // randomize the number generator
    TaskNode* taskQueue = createTaskNode(0, rand() % 3, rand() % 20);
    TaskNode* prevTaskNode = taskQueue;
    for (int i = 1; i < n; ++i) {
        TaskNode* nextNode = createTaskNode(i, rand() % 3, rand() % 20);
        prevTaskNode->next = nextNode;
        prevTaskNode = nextNode;
    }
    return taskQueue;
}

// Insert a new task into task queue
void enqueueTask(TaskNode** taskQueue, int task_num, int task_type, int value) {
    TaskNode *prevNode = *taskQueue;
    while (prevNode->next != NULL) {
        prevNode = prevNode->next;
    }
    prevNode->next = createTaskNode(task_num, task_type, value);
}

// Take a task from task queue
TaskNode* dequeueTask(TaskNode** taskQueue) {
    if(*taskQueue == NULL)
        return NULL;
    TaskNode* dequeuedTask = *taskQueue;
    *taskQueue = (*taskQueue)->next;
    dequeuedTask->next = NULL;
    return dequeuedTask;
}
