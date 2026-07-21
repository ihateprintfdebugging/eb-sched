#include "ebsched.h"

void EBScheduler::addTask(EBTask task) {
    taskQueue.push(task);
}

void EBScheduler::processTasks() {
    if(this->taskQueue.empty()) return;

    EBTask task = taskQueue.top();

    std::cout << "Executing function: " << std::endl;
    std::cout << "TaskName : " << task.taskName << std::endl;
    std::cout << "Task Priority: " << task.priority << std::endl;
    // std::cout << "Task address : " + &(task.pFunc) << std::endl;

    if(task.pFunc) {
        task.pFunc();
    }
    
    taskQueue.pop();
}

