//move all 3 functions here
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <unordered_set>

//LRU
void LRU(int pages[], int size, int capacity) 
{
	//list of pages, map, counter  
	std::list<int> dq;
	std::unordered_map<int, std::list<int>::iterator> ma;
	int page_faults = 0;

	//keep samplr output form
	std::cout << "For LRU Algorithm:\n";
	for (int i = 0; i < size; i++) {
		int page = pages[i];
		std::cout << "Step " << i + 1 << ": ";
		//fault check
		if (ma.find(page) == ma.end()) 
		{
			if (dq.size() == capacity) 
			{
				int last = dq.back();
				dq.pop_back();
				ma.erase(last);
			}
			//add new page and iterator, fault message 
			dq.push_front(page);
			ma[page] = dq.begin();
			page_faults++;
			std::cout << "Page fault (" << page << ") - Page Table: {";
		}
		else 
		{
			//update map, hit message here 
			dq.erase(ma[page]);
			dq.push_front(page);
			ma[page] = dq.begin();
			std::cout << "Hit (" << page << ") - Page Table: {";
		}
		for (auto it = dq.begin(); it != dq.end(); ++it) 
		{
			if (it != dq.begin()) std::cout << ", ";
			std::cout << *it;
		}
		//frames: here 
		std::cout << "}, Frames: [";
		for (auto it = dq.begin(); it != dq.end(); ++it) 
		{
			if (it != dq.begin()) std::cout << ", ";
			std::cout << *it;
		}
		std::cout << "], Faults: " << page_faults << "\n";
	}
	std::cout << "Total Page Faults: " << page_faults << "\n";
}


//OPT 
void OPT(int pages[], int pageNumber, int frameNumber) 
{
	//vector to store frames, hits
	std::vector<int> frames;
	int hits = 0;

	std::cout << "For Optimal Algorithm:\n";
	//prediction function, which page within the frame will be used
	auto predict = [&](int pageIndex) -> int 
		{
			//result and farthest varibles 
		int res = -1, farthest = pageIndex;
		//next frame loop 
		for (int i = 0; i < frames.size(); i++) 
		{
			int j;
			for (j = pageIndex; j < pageNumber; j++) 
			{
				if (frames[i] == pages[j]) 
				{
					if (j > farthest) 
					{
						farthest = j;
						res = i;
					}
					break;
				}
			}
			if (j == pageNumber) return i;
		}
		//return pages that wont be used
		return (res == -1) ? 0 : res;
		};

	for (int i = 0; i < pageNumber; i++) 
	{
		std::cout << "Step " << i + 1 << ": ";
		//find the current page within frame
		auto it = find(frames.begin(), frames.end(), pages[i]);
		if (it == frames.end()) 
		{
			if (frames.size() < frameNumber)
				frames.push_back(pages[i]);
			else 
			{
				int j = predict(i + 1);
				frames[j] = pages[i];
			}
			hits++;
			std::cout << "Page fault (" << pages[i] << ") - Page Table: {";
		}
		else 
		{
			std::cout << "Hit (" << pages[i] << ") - Page Table: {";
		}
		for (auto x : frames) std::cout << x << " ";
		std::cout << "}, Frames: [";
		for (auto x : frames) std::cout << x << " ";
		std::cout << "], Faults: " << pageNumber - hits << "\n";
	}
	std::cout << "Total Page Faults: " << pageNumber - hits << "\n";
}


//FIFO
void FIFO(int pages[], int n, int capacity) 
{
	//queue declaration, set, fault counter 
	std::queue<int> pageQueue;
	std::unordered_set<int> pageSet;
	int page_faults = 0;

	std::cout << "For FIFO Algorithm:\n";
	//page loop
	for (int i = 0; i < n; i++) 
	{
		std::cout << "Step " << i + 1 << ": ";
		//check for space 
		if (pageSet.size() < capacity) 
		{
			if (pageSet.find(pages[i]) == pageSet.end()) 
			{
				//this handles the fault, check
				pageSet.insert(pages[i]);
				pageQueue.push(pages[i]);
				page_faults++;
				std::cout << "Page fault (" << pages[i] << ") - Page Table: {";
			}
			else 
			{
				std::cout << "Hit (" << pages[i] << ") - Page Table: {";
			}
		}
		else 
		{
			if (pageSet.find(pages[i]) == pageSet.end()) 
			{
				//pop and push pages 
				int val = pageQueue.front();
				pageQueue.pop();
				pageSet.erase(val);
				pageSet.insert(pages[i]);
				pageQueue.push(pages[i]);
				page_faults++;
				std::cout << "Page fault (" << pages[i] << ") - Page Table: {";
			}
			else 
			{
				//ping page hit
				std::cout << "Hit (" << pages[i] << ") - Page Table: {";
			}
		}
		//iterate through the page hits 
		for (auto x : pageSet) std::cout << x << " ";
		std::cout << "}, Frames: [";
		//reiteration for faults
		for (auto x : pageSet) std::cout << x << " ";
		std::cout << "], Faults: " << page_faults << "\n";
	}
	std::cout << "Total Page Faults : " << page_faults << "\n";
}
