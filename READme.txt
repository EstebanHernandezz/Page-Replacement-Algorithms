
# Programming Assignment 4

## Description

This project simulated three replacement algorithms used within operating systems for efficient memory utilization. The three algorithms are Least Recently Used (LRU), Optimal, and First in First Out (FIFO). The LRU algorithm keeps track of page usage during its execution and keeps track of the frame that was last used and is replaced by another. Using a list you can keep track of most recently accessed page, keeping it at the front and keeping the least used at the back of the list. In the Optimal algorithm used a prediction function to find the page that will not be needed for the longest period of time. This can be done using the refrence page, when a the page needs to be replaced the algoirhtm looks to the refrence string. After determining the page that will not be used for the longest period of time from the refrence string, it can be selected to be replaced. FIFO maintains its original order, when a page fault occurs, the page that has been in the memory for the longest period of time (the first in) will be removed and a new page will be added. 

## Installation

Install Microsoft Visual Studio 2022 (if not already installed)

### Prerequisites
- Microsoft Visual Studio 2022

### Installation Steps
(For VS2022)
1. Navigate to the Microsoft.com
2. Navigate to the Microsoft Visual Studio 2022 download link
3. Select the correct download version for your machine
4. Wait for download to finsh then open VS2022
