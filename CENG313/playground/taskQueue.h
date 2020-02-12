
struct task_node {
    int task_num;           // starting from 0
    int task_type;          // insert:0, delete:1, search:2
    int value;              // value
    struct task_node* next; // following task
};

typedef struct task_node TaskNode;

TaskNode* generateTaskQueue(int n);                                                 // Generate n random tasks for the task queue
void enqueueTask(TaskNode** taskQueue, int task_num, int task_type, int value);     // Insert a new task into task queue
TaskNode* dequeueTask(TaskNode** taskQueue);                                        // Take a task from task queue