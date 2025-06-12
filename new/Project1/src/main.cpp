
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <sstream>

using namespace std;

class Task {
public:
    string id;
    int load;

    Task(const string &taskId, int taskLoad) : id(taskId), load(taskLoad) {}
};

class CPULoadBalancer {
private:
    int cpuCount;
    queue<Task> taskQueue;
    mutex queueMutex;

public:
    bool loadFromFile(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Cannot open " << filename << endl;
            return false;
        }

        string line;
        if (getline(file, line)) {
            if (line.find("CPUs:") != string::npos) {
                cpuCount = stoi(line.substr(line.find(":") + 1));
            }
        }

        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string taskId, temp;
            int load;
            getline(ss, taskId, ':');
            ss >> temp >> load;
            taskQueue.push(Task(taskId, load));
        }

        file.close();
        return true;
    }

    void start() {
        vector<thread> threads;
        for (int i = 1; i <= cpuCount; ++i) {
            threads.emplace_back(&CPULoadBalancer::cpuWorker, this, i);
        }

        for (auto &t : threads) {
            t.join();
        }

        cout << "All tasks completed." << endl;
    }

private:
    void cpuWorker(int cpuId) {
        while (true) {
            Task task("", 0);

            {
                lock_guard<mutex> lock(queueMutex);
                if (taskQueue.empty()) return;
                task = taskQueue.front();
                taskQueue.pop();
                cout << "CPU-" << cpuId << " picked Task " << task.id << " (Load: " << task.load << ")" << endl;
            }

            this_thread::sleep_for(chrono::seconds(task.load));

            cout << "CPU-" << cpuId << " finished Task " << task.id << endl;
        }
    }
};

int main() {
    CPULoadBalancer balancer;
    if (balancer.loadFromFile("input.txt")) {
        balancer.start();
    }
    return 0;
}
