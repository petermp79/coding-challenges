//
// LEETCODE# 146
//
// Implement a LRU cache
//  - fast lookup - use (multi-level) hash table
//  - fast removal of LRU entry - use queue with LRU entry at front of queue
//  - fast insertion - insert hash + insert at back of queue 
//  - fast LRU update - move queue entry from old position to back of queue
//
#include <iostream>
#include <unordered_map>
#include <deque>
#include <string>

using namespace std;

int capacity = 5;

// Queue with LRU entry in front of queue
// Queue entry stores K-V pair
//
deque<pair<int, string>> q;

// Hash table for key search and position of K-V pair in queue
//
// Assumre keys are unique.
//
unordered_map <int, deque<pair<int, string>>::iterator> cache;

//
// Remove LRU item from cache
//
// Return: None
//
void deleteLRU() {

    if (q.empty()) 
        return;

    auto it = q.front();
    q.pop_front();              // remove item from queue

    // remove item from cache
    cache.erase(it.first);     // remove coorresponding cache entry

    return;
}

//
// Insert a new item into cache
//
// Return: 0 - success
//        -1 - failure
//
int put(const int key, const string value) {

  // is it in cache already?
  auto itr = cache.find(key);
  if (itr != cache.end()) {
    // yes, collision
    return -1;
  }
  
  // is cache full?
  if (cache.size() >= capacity) {
    // yes, remove LRU item to make room for new item
    deleteLRU();
  }
  q.push_back(make_pair(key, value));        // add new item to queue 
  //cache.insert(make_pair<key, (q.rbegin()+1).base()>);  // ... and cache 
  cache[key] = (q.rbegin()+1).base();
  return 0;

}

//
// Look up an entry in the cache 
//
// Return: value if found
//         NULL if entry not found
//
string get(int key) {
  
  // is it in cache?
  auto citr = cache.find(key);
  if (citr == cache.end()) {
    // no
    return NULL;
  }

  // yes, get queue item from cache entry
  auto qitr = citr->second;
  string value = qitr->second;  // return value

  // shuffle queue item to end of queue
  q.push_back(make_pair(qitr->first, qitr->second));

  q.erase(qitr);  // ... and remove its prev position in queue 

  citr->second = (q.rbegin()+1).base(); // update new queue entry position in cache

  return value;
}
  

int main() {
  
  put(1, "one");
  put(2, "two");
  put(3, "three");
  put(4, "four");
  put(5, "five");

  // print cache and queue after inserts
  //
  cout << "Cache:\n";
  for (auto &c : cache) {
    auto qe = *c.second;
    cout << c.first << ":" << qe.second << endl; 
  }

  cout << "\nQueue:\n";
  for (auto &qe : q) {
    cout << qe.first << ", " << qe.second << endl;
  } 

  cout << "\n>>> Lookup: 3" << endl;
  get(3);

  // reorder queue after lookup 
  //
  cout << "\nQueue:\n";
  for (auto &qe : q) {
    cout << qe.first << ", " << qe.second << endl;
  } 

  //
  // test insert when queue is full
  //
  cout << "\n>>> Insert 6, 7 ..." << endl;

  put(6, "six");
  put(7, "seven");
  
  cout << "\nCache:\n";
  for (auto &c : cache) {
    auto qe = *c.second;
    cout << c.first << ":" << qe.second << endl; 
  }

  cout << "\n>>> Lookup: 4" << endl;
  get(4);

  cout << "\nQueue:\n";
  for (auto &qe : q) {
    cout << qe.first << ", " << qe.second << endl;
  } 
}





