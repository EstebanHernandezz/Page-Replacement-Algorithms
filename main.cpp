#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <unordered_set>

//function declaration -> extern specifies these functions are in fucntions file
extern void LRU(int pages[], int size, int capacity);
extern void OPT(int pagesp[], int pageNumber, int frameNumber);
extern void FIFO(int pages[], int n, int capacity);

int main()
{
	//try different array values later 
	//array for LRU 
	int LRU_pages[] = { 1, 2, 1, 0, 3, 0, 4, 2, 4 };
	//calculate page requests
	int LRU_size = sizeof(LRU_pages) / sizeof(LRU_pages[0]);
	int LRU_capacity = 3;
	LRU(LRU_pages, LRU_size, LRU_capacity); 

	//array for optimal
	int OPT_pages[] = { 1, 7, 8, 3, 0, 2, 0, 3, 5, 4, 0, 6, 1 };
	//calculate page requests 
	int OPT_size = sizeof(OPT_pages) / sizeof(OPT_pages[0]);
	int OPT_capacity = 3;
	OPT(OPT_pages, OPT_size, OPT_capacity);


	//array for FIFO 
	int FIFO_pages[] = { 1, 3, 0, 3, 5, 6, 3 };
	//calculaiton...
	int FIFO_size = sizeof(FIFO_pages) / sizeof(FIFO_pages[0]);
	int FIFO_capacity = 3;
	FIFO(FIFO_pages, FIFO_size, FIFO_capacity);

	return 0; 

}

