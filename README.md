# DISTRIBUTED-STORAGE-SYSTEM
Developed a Distributed Storage System in C++ implementing Consistent Hashing, B+ Tree indexing, Greedy load balancing, and Dijkstra-based routing. Supports efficient file storage, replication, distributed range queries, and network-based shortest path file transfer simulation.

##  Project Overview

This project implements a Distributed Storage System simulation using advanced Data Structures and Algorithms in C++. The system is designed to store and manage files across multiple servers efficiently while ensuring fast search, load balancing, fault tolerance, and optimized data transfer.

The system uses Consistent Hashing to distribute files across servers, B+ Trees to store and index files efficiently, Greedy algorithms to balance server load, and Dijkstra’s algorithm to simulate shortest-path routing between servers.

This project simulates how real-world distributed storage systems such as cloud storage platforms and distributed databases manage large volumes of data across multiple machines.

---

##  Problem Statement

Modern applications generate large volumes of data that cannot be stored on a single server. To handle such large-scale data efficiently, distributed storage systems divide data across multiple servers.

However, distributed storage introduces several challenges:

- Efficient data distribution across servers
- Fast file storage and retrieval
- Load balancing between servers
- Fault tolerance during server failure
- Efficient routing of data across networks
- Support for range-based queries

This project addresses these challenges using efficient data structures and algorithms.

---

##  System Description

The system simulates a distributed environment where multiple servers store files. Each server internally uses a B+ Tree structure to organize stored files efficiently.

When a file is inserted:

1. The system selects an appropriate server using Consistent Hashing.
2. A Greedy algorithm selects the least-loaded server.
3. The file is stored inside a B+ Tree within the selected server.
4. A backup copy is stored on another server for reliability.

The system also supports:

- Fast searching of files
- Distributed range queries
- Server failure simulation
- Shortest path-based file transfer using graph routing

---

##  System Architecture


User Request
↓
Consistent Hash Ring
↓
Greedy Load Balancer
↓
Selected Server
↓
B+ Tree Storage
↓
Replication to Backup Server
↓
Graph Network Routing
↓
Shortest Path File Transfer


---

##  Data Structures Used

### 1️ B+ Tree

Used for efficient file storage inside each server.

Features:

- Stores data in sorted order
- Supports fast insertion
- Supports fast searching
- Supports efficient range queries
- Maintains balanced structure

Time Complexity:

- Insert → O(log n)
- Search → O(log n)
- Range Search → O(log n + k)

---

### 2️ Consistent Hashing (Hash Ring)

Used to distribute servers and files across a circular hash space.

Features:

- Even distribution of data
- Supports dynamic server addition/removal
- Uses virtual nodes for better load balancing
- Minimizes data movement during failures

---

### 3️ Graph (Adjacency List)

Used to represent network connections between servers.

Features:

- Models server-to-server communication
- Stores network latency weights
- Supports shortest path routing

---

##  Algorithms Used

###  Greedy Algorithm

Used to select the least-loaded server during file storage.

Purpose:

- Prevent server overload
- Maintain balanced distribution
- Improve overall performance

---

###  Dijkstra’s Algorithm

Used to calculate shortest path between servers during file transfer.

Features:

- Uses priority queue (min-heap)
- Computes minimum latency path
- Simulates efficient network routing

Time Complexity:


O(E log V)


Where:

- V = Number of servers
- E = Number of connections

---

##  Key Features

✔ Distributed File Storage  
✔ Consistent Hashing with Virtual Nodes  
✔ B+ Tree-Based Indexing  
✔ Greedy Load Balancing  
✔ File Replication (Primary + Backup)  
✔ Distributed Range Search  
✔ Network Routing using Dijkstra Algorithm  
✔ Server Failure Simulation  
✔ Fault-Tolerant Data Distribution  

---

##  Range Query Support

The system supports range-based file queries using linked leaf nodes in B+ Trees.

Example:


Search files between:
file2.txt → file6.txt

Output:
file2.txt
file3.txt
file4.txt
file5.txt
file6.txt


---

##  Network Simulation

Servers are connected as a weighted graph.

Each connection represents network latency.

Example:


ServerA --10ms-- ServerB
ServerB --5ms--- ServerC
ServerC --10ms-- ServerD


The shortest path between servers is computed using Dijkstra’s algorithm.

---

##  Server Failure Handling

The system simulates server failure by removing servers from the hash ring.

Features:

- Virtual nodes removed
- Hash ring updated
- Load redistributed automatically
- System continues functioning

---

##  Real-World Applications

This system models real distributed storage environments used in:

- Cloud Storage Systems
- Distributed Databases
- File Systems
- Big Data Platforms
- Microservice Storage Systems

Examples:

- Google Drive
- Amazon S3
- Hadoop Distributed File System (HDFS)
- Apache Cassandra
- MongoDB

---

##  Performance Benefits

Using advanced data structures improves system performance:

| Operation | Complexity |
|----------|------------|
| File Insert | O(log n) |
| File Search | O(log n) |
| Range Search | O(log n + k) |
| Load Selection | O(n) |
| Shortest Path | O(E log V) |

---

##  Sample Output


Distributed Storage System Started

--- Storing Files ---

File stored: file1.txt
Primary Server ID: 104
Backup Server ID: 585

--- Distributed Range Search ---

Files between file2.txt and file6.txt:
file2.txt
file3.txt
file4.txt
file5.txt
file6.txt

--- Server Network Simulation ---

Shortest Paths from ServerA:
ServerA -> ServerB = 10
ServerA -> ServerC = 15
ServerA -> ServerD = 25

Transferring file from ServerA to ServerD:
Shortest route:
ServerA → ServerB → ServerD
Total latency: 25 ms


---

##  Technologies Used

- C++
- Standard Template Library (STL)
- Object-Oriented Programming
- Graph Algorithms
- Tree Data Structures
- Hashing Techniques

---

##  Future Enhancements

- Graphical User Interface (GUI)
- Real file storage simulation
- Dynamic network latency updates
- Distributed caching
- Performance monitoring dashboard

---

##  Conclusion

This project demonstrates how advanced data structures and algorithms can be combined to desi
