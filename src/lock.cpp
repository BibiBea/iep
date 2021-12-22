#include <iostream>
#include <memory>
#include <mutex>
#include "uncopyable.cpp"

class Lock:private Uncopyable{
    private:
    std::mutex mutexPtr;

    public:
    explicit Lock(){
        mutexPtr.lock();
        std::cout << "Lock!" << "\n";
    }

    ~Lock(){
        mutexPtr.unlock();
        std::cout << "Unlock!" <<"\n";
    }

    void someFunction(){
        std::cout << "Mutex" <<"\n";
    }
};