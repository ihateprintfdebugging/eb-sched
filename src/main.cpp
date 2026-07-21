#include <ebsched.h>
#include <iostream>
#include <string>

void hello1() {
    std::cout << "Hello world 1" << std::endl;
}

void sayHelloToMe(std::string name) {
    std::cout << "Hello " << name << std::endl;
}

int main() {
    std::cout << "EBSched example is started" << std::endl;

    EBTask task1 = {"task1", 
        1, 
        []() { sayHelloToMe("user1!"); }
    };

    EBTask task2 = {"task2", 
        15, 
        []() { sayHelloToMe("user2!"); }
    };

    EBTask task3 = {"task3", 
        1, 
        []() { sayHelloToMe("user3!"); }
    };

    EBTask task4 = {"task4", 
        5, 
        []() { sayHelloToMe("user4!"); }
    };

    EBScheduler scheduler;
    scheduler.addTask(task1);
    scheduler.addTask(task2);
    scheduler.addTask(task3);
    scheduler.addTask(task4);

    while(!scheduler.isEmpty()) {
        scheduler.processTasks();
    }

    return 0;
}