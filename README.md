##Congestion Control

### Algorithm to reduce congestion at loadbalancer ###

  Step1: Visualize the packets
	To visualize the packets I have done socket programming in C.

###### Question - What is socket ? ######
###### Answer - ###### Socket is the combination of IP and port number that is formed on both ends during client/server communication.

#### AIM ####
To reduce congestion on backend server.

I have to make a program which can help in reducing congestion at backend server. Loadbalancer is something which can help me to do this. 
Every request from client goes to a loadbalancer and then from loadbalancer to a backend server. Loadbalancer selects which backend server to 
serve request if we have cluster of servers at data center. 

#### WHAT IS LOAD BALANCER ####
Loadbalncer is used to distribute workload across multiple computing resources. It works at layer 4 (Application layer).
More at: [link][1]
[1]: https://en.wikipedia.org/wiki/Load_balancing_(computing)

STEP1: NOTE DOWN THE PORT OF BACKEND SERVER TO WHICH CLIENT WILL SEND REQUEST. (THE PORT WHICH WILL BE USED IN PASSIVE OPEN).
STEP2: USE A SCHEDULING ALGORITHM TO DETRMINE WHICH BACKEND SERVER TO SERVE. CONSIDER  - 
	2.1: Server's laod
	2.2: Least Response Time
	2.3: Up/Down Status
	2.4: Number of active connections
	2.5: Geographic locations
STEP3: HANDLE THE MULTIPLE REQUESTS FROM A CLIENT.
	3.1: Cached Information
	3.2: Can use a shared database
	3.3: Store request of client
	3.4: Hashing request of same client to same backend node.

Implementing the above 3 steps and after that our loadbalancer is ready.



