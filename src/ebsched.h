#ifndef EBSCHED_H
#define EBSCHED_H

#include <string>
#include <queue>
#include <iostream>
#include <functional>

struct EBTask {
    std::string taskName;
    unsigned int priority;
    std::function<void()> pFunc;

    bool operator<(const EBTask& other) const {
        return this->priority < other.priority;
    }
};

class EBScheduler {

public:

    EBScheduler() = default;
    ~EBScheduler() = default;

    void addTask(EBTask task);
    void processTasks();

    bool isEmpty() {
        return taskQueue.empty();
    };

private:

    std::priority_queue<EBTask> taskQueue;
    
};

#endif // EBSCHED_H