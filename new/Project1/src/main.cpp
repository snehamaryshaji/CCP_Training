
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

    Task(const string &taskId,#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <fstream>
#include <chrono>
#include <unordered_map>

using namespace std;

// Abstract base class for User
class User {
public:
    string username;
    virtual void login() = 0; // Pure virtual function
    virtual ~User() {} // Virtual destructor
};

// Buyer class inherits from User
class Buyer : public User {
public:
    void login() override {
        cout << "Buyer " << username << " logged in.\n";
    }
};

// Seller class inherits from User
class Seller : public User {
public:
    void login() override {
        cout << "Seller " << username << " logged in.\n";
    }
};

// Bid class to hold bid details
class Bid {
public:
    string buyerName;
    int amount;
    time_t timestamp;

    // Comparator for max-heap priority queue
    bool operator<(const Bid& other) const {
        return amount < other.amount; // highest bid at the top
    }
};

// Auction class
class Auction {
public:
    string item;        // Item name
    int minPrice;       // Minimum starting price
    bool active = true; // Auction status
    priority_queue<Bid> bids; // Max-heap of bids
    mutex mtx;          // Mutex to protect bid operations

    // Place a bid if auction is active and bid is valid
    void placeBid(const Bid& bid) {
        lock_guard<mutex> lock(mtx);
        if (active && bid.amount >= minPrice) {
            bids.push(bid);
        }
    }

    // Close the auction
    void closeAuction() {
        lock_guard<mutex> lock(mtx);
        active = false;
    }

    // Declare the highest bidder as winner
    Bid declareWinner() {
        if (!bids.empty()) return bids.top();
        return Bid{"None", 0, 0}; // No valid bids
    }
};

// Global storage for all auctions
unordered_map<string, Auction> liveAuctions;
// Set to track active bidders
set<string> activeBidders;
// Mutex for writing to log file
mutex logMutex;

// Background thread to manage auction closing and result logging
void auctionThread(string auctionID) {
    // Wait for 10 seconds to simulate auction duration
    this_thread::sleep_for(chrono::seconds(10));

    // Close auction and declare winner
    liveAuctions[auctionID].closeAuction();
    Bid winner = liveAuctions[auctionID].declareWinner();

    // Write auction result to a log file
    lock_guard<mutex> lock(logMutex);
    ofstream log("auction_logs.txt", ios::app);
    log << "Auction for " << auctionID << " won by " << winner.buyerName
        << " with bid: " << winner.amount << "\n";
}

int main() {
    // Create users
    Seller s1;
    s1.username = "Alice";
    s1.login(); // Seller login

    Buyer b1;
    b1.username = "Bob";
    b1.login(); // Buyer login

    Buyer b2;
    b2.username = "Carol";
    b2.login(); // Buyer login

    // Create auction and add to live list
    Auction a1;
    a1.item = "Laptop";
    a1.minPrice = 10000;
    liveAuctions["A1001"] = a1;

    // Start auction closing in a separate thread
    thread t1(auctionThread, "A1001");

    // Simulate buyers placing bids
    Bid bid1 = {"Bob", 12000, time(0)};
    Bid bid2 = {"Carol", 15000, time(0)};
    liveAuctions["A1001"].placeBid(bid1);
    liveAuctions["A1001"].placeBid(bid2);

    // Wait for auction to close
    t1.join();

    return 0;
}
 int taskLoad) : id(taskId), load(taskLoad) {}
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
