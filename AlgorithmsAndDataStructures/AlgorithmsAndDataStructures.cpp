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
#include "List.h"
#include "Iterator.h"
#include "Node.h"
#include "reverse_iteratorr.h"
using namespace std;

int main()
{


	string myNum[3] = { "fsd","sadasd","dsad" };
	int x = 3;
	List<string> list3(myNum, x);
	list3.print();


	/*int i1=0, i2 = 0;
	cout <<"i1= "<< ++i1<<endl;
	cout << "i1= "<< i2++<<endl;
	cout << "--------------- " << endl;
	cout << "i1= " << i1 << endl;
	cout << "i1= " << i2 << endl;*/
	cout << "--------------- " << endl;

	for (Iterator<string> it = list3.beginn();
		it != list3.end();
		it++)
	{
		cout << "f: " << *it << " ";
	}
	cout << endl;

	cout << "--------------- " << endl;
	string myNumM[3] = { "fsDd","sadaDsd","dsDad" };
	int xY = 3;
	List<string> list33(myNumM, xY);


	for (reverse_iteratorr<string> iter = list33.beginnn();
		iter != list33.endd();
		iter++)
	{
		cout << *iter << " ";
	}

	return 0;
}
