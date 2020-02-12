#include <stdio.h>
#include "taskQueue.h"
#include "linkedList.h"

void operateTask(TaskNode* task, Node** list) {
    printf("task %d-", task->task_num);
    if(task->task_type == 0) {
        printf("add %d: ", task->value);
        add(list, task->value);
    } else if(task->task_type == 1) {
        printf("delete %d: ", task->value);
        delete(list, task->value);
    } else if(task->task_type == 2) {
        printf("search %d: ", task->value);
        search(list, task->value);
    } else {
        printf("unknown type!");
    }
}

int main(int argc, char** argv) {

    printf("Generated %d random list tasks!\n", 40);
    TaskNode* taskQueue = generateTaskQueue(40);
    Node* list = NULL;

    TaskNode* dequeuedTask = dequeueTask(&taskQueue);
    while(dequeuedTask != NULL) {
        operateTask(dequeuedTask, &list);
        dequeuedTask = dequeueTask(&taskQueue);
    }

    printList(list);
    return 0;
}