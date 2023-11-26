#include <iostream>
#include <thread>
#include <mutex>

// Global mutex for synchronization
std::mutex mtx;

// Function to count up to 20
void countUp() {
    std::lock_guard<std::mutex> lock(mtx); // mutex is locked during the execution of this scope
    for(int i = 0; i <= 20; ++i) {
        std::cout << "Counting up: " << i << std::endl;
    }
} // Mutex automatically released when lock_guard goes out of scope

// Function to count down from 20 to 0
void countDown() {
    std::lock_guard<std::mutex> lock(mtx); // mutex is locked during the execution of this scope
    for(int i = 20; i >= 0; --i) {
        std::cout << "Counting down: " << i << std::endl;
    }
} // Mutex automatically released when lock_guard goes out of scope

int main() {
    // Create first thread to count up
    std::thread t1(countUp);
    t1.join(); // Wait for the first thread to finish

    // Create second thread to count down
    std::thread t2(countDown);
    t2.join(); // Wait for the second thread to finish

    return 0;
}
