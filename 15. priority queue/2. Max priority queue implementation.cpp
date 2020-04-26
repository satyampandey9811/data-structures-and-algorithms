// priority queue
// implementation of Max priority queue

#include <bits/stdc++.h>
using namespace std;

class priorityQueue {
	vector<int> pq;	
	
public:
	
	priorityQueue() {
		
	}
	
	bool isEmpty() {
		return pq.size() == 0;
	}
	
	int getSize() {
		return pq.size();
	}
	
	int getMax() {
		if(isEmpty()) return 0;
		return pq[0];
	}
	
	void insert(int data) {
		pq.push_back(data);
		int cI = pq.size() - 1;
		
		while(cI > 0){
			int pI = (cI - 1) / 2;
			if(pq[cI] > pq[pI]) 
				swap(pq[cI], pq[pI]);
			else 
				break;
			cI = pI;
		}
	}
	
	int removeMax() {
		if(isEmpty()) return 0;
        int ans = pq[0];
		pq[0] = pq[pq.size() - 1];		
		pq.pop_back();
		int pI = 0;
		int lC = pI * 2 + 1, rC = pI * 2 + 2;
		
		while(lC < pq.size() - 1) {
            if(pq[pI] < max(pq[lC], pq[rC])) {
                if(pq[lC] > pq[rC]) {
                    swap(pq[pI], pq[lC]);
                    pI = lC;
                }
                else {
                    swap(pq[pI], pq[rC]);
                    pI = rC;
                }
            }
            else
                break;
			lC = 2 * pI + 1;
			rC = 2 * pI + 2;
		}
		return ans;
	}
};