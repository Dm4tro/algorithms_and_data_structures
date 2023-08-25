#include "pch.h"
#include "..\AlgorithmsAndDataStructures\List.h"

#include "gtest/gtest.h"
#include <string>

using namespace std;
template <typename T>
bool compare_int(const T& first, const T& secound) {
    if (first <= secound) {//<=
        return 1;
    }
    else {
        return 0;
    }

}

TEST(LIstSort, firstTest) {
//	EXPECT_EQ(1, return_1());
	ASSERT_EQ(2 + 2, 4);
    
}

TEST(LIstSort, printTest) {
    testing::internal::CaptureStdout();

    int nums[] = { 3,2,1 };
    int xyx = 3;
    List<int> intList(nums, xyx);
    intList.Sort(&compare_int);
    intList.print();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n1 2 3 \n");
}

TEST(LIstSort, printTest2) {
    testing::internal::CaptureStdout();

    int nums[] = { 3,2,1,-1,333333,21 };
    int xyx = 6;
    List<int> intList(nums, xyx);
    intList.Sort(&compare_int);
    intList.AddFront(300);
    intList.print();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,"List is:\n300 -1 1 2 3 21 333333 \n");
}

TEST(LIstSort, printTest3) {
    testing::internal::CaptureStdout();

    
    List<int> intList2;
    intList2.Sort(&compare_int);
    intList2.print();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Error, can't compare empty list!!!\nList is empty\n");
}

TEST(LIstSort, printTest4) {
    testing::internal::CaptureStdout();


    int nums[] = { 3 };
    int xyx = 1;
    List<int> intList3(nums, xyx);
    intList3.Sort(&compare_int);
    cout << intList3;
    
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n3 \n");
}

TEST(deleteAtTest, BasicTest) {
    testing::internal::CaptureStdout();


    int nums[] = { 0,1,2 };
    int xyx = 3;
    List<int> intList3(nums, xyx);
    try {
        intList3.DeleteAt(1);
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
   
    /*cout << intList3;*/

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "You can't delete at index 0 or lower!!!");
}

