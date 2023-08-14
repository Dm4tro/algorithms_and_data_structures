#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <iomanip>
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
#include "Node.h"
#include "List.h"
#include "Iterator.h"
#include "Reverse_Iterator.h"

using namespace std;

int main()
{


	std::string myNum[3] = { "fsd","sadasd","dsad" };
	int x = 3;
	List<std::string> list3(myNum, x);
	list3.print();


	
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

	int nums[3] = { 3,10,1 };
	int xyx =3 ;
	List<int> intList(nums, xyx);
	intList.l_sort(intList.get_start(), intList.get_end());
	return 0;
}
