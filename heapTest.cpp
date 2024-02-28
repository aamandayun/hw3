#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;


int main(int argc, char* argv[])
{
	Heap<int> heap;
	heap.push(3);
	heap.push(10);
	//EXPECT_EQ(3, heap.top());

	heap.pop();

	//EXPECT_EQ(10, heap.top());



    
    return 0;

}
