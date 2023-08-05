#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

static std::atomic<int> shared_value = 0;

void shared_value_increment(){
    shared_value++;
}

int main() {

    std::vector<std::thread> threads;

    for (size_t i = 0; i < 100; i++)
    {
        threads.push_back(std::thread(shared_value_increment));
    }

    for (size_t i = 0; i < 100; i++)
    {
        threads[i].join();
    }

    std::cout << "Value: " << shared_value <<std::endl;

}