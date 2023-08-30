#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <functional>
#include <limits>
#include <fstream>
#include <cctype>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> 
#include <cctype> 
#include <map>
#include <stdarg.h>
#include <list>
#include <cstdarg>


#include "list/Node.h"
#include "list/List.h"
#include "list/Iterator.h"
#include "list/Reverse_Iterator.h"
#include "list/Const_Iterator.h"
#include "list/Const_Reverse_Iterator.h"
#include "hash_map/Map_Node.h"
#include "hash_map/Hash_Map.h"

using namespace std;
template<typename T>


bool compare_int(const T &first, const T &secound) {
	if (first <= secound) {//<=
		return 1;
	}
	else {
		return 0;
	}

}
int return_1() {
	return 1;
}
int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }


int invoke(int x, int y, int (*func)(int, int))
{
	return func(x, y);
}

int main()
{

	Hash_Map<int> firstMap;
	firstMap.insert("One", 1);
	firstMap.insert("two", 2);
	firstMap.insert("tree", 3);
	firstMap.insert("four", 4);
	firstMap.print();








	/*std::string myNum[3] = { "fsd","sadasd","dsad" };
	int x = 3;
	List<std::string> list3(myNum, x);
	list3.Print();


	
	std::cout << "--------------- " << endl;

	for (Iterator<std::string> it = list3.beginn();
		it != list3.end();  
		it++)
	{
		std::cout << "f: " << *it << " ";
	}
	std::cout << endl;

	std::cout << "--------------- " << endl;
	string myNumM[3] = { "fsDd","sadaDsd","dsDad" };
	int xY = 3;
	List<string> list33(myNumM, xY);


	for (Reverse_Iterator<string> iter = list33.beginnn();
		iter != list33.endd();
		iter++)
	{
		std::cout << "f: " << *iter << " ";
	}

	std::cout <<endl<< "--------------- " << endl;


	int nums[] = { 65,2,1,1342,33, 657,0,3423 };
	int xyx = 8;
	List<int> intList(nums, xyx);
	intList.Sort(&compare_int);
	intList.Print();


	int numss[] = { 65,0,1,0,33, 657,0,0 };
	int xyxx = 8;
	List<int> intList2(numss, xyxx);
	std::cout << endl << "--------------- " << endl;
	intList2 = intList;
	intList2.Print();

	std::cout << endl << "--------------- " << endl;
	List<int> intListt(intList);
	intListt.Print();*/
	return 0;
}
