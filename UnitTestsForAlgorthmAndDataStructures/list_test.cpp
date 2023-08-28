#include "pch.h"

#include "\Development\repos\algorithms_and_data_structures\AlgorithmsAndDataStructures\list\List.h"

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
    intList.Print();

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
    intList.Print();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,"List is:\n300 -1 1 2 3 21 333333 \n");
}

TEST(LIstSort, printTest3) {
    testing::internal::CaptureStdout();

    
    List<int> intList2;
    intList2.Sort(&compare_int);
    intList2.Print();

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

TEST(deleteAtTest, BasicTest1) {
    

    int nums[] = { 0, 1, 2 };
    int xyx = 3;
    List<int> intList3(nums, xyx);

    try {
        intList3.DeleteAt(0);
        FAIL() << "Expected exception not thrown";
    }
    catch (const invalid_argument& e) {
        
        EXPECT_STREQ(e.what(), "You can't delete at index 0 or lower!!!");
    }

    // Other assertions or checks if needed
}

TEST(deleteAtTest, BasicTest2) {
    testing::internal::CaptureStdout();


    int nums[] = { 0, 1, 2 };
    int xyx = 3;
    List<int> intList3(nums, xyx);
    intList3.DeleteAt(1);
    cout << intList3;

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n1 2 \n");
}

TEST(add_front, BasicTest0) {
    testing::internal::CaptureStdout();


    int nums[] = { 0, 1, 2 };
    int xyx = 3;
    List<int> intList3(nums, xyx);
    intList3.AddFront(999);
    cout << intList3;

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n999 0 1 2 \n");
}

TEST(add_front, BasicTest1) {
    testing::internal::CaptureStdout();


    int nums[] = { 0, 1, 2 };
    int xyx = 3;
    List<int> intList3;
    intList3.AddFront(999);
    cout << intList3;

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n999 \n");
}

//TEST(equalOperator, BasicTest0) {
//    testing::internal::CaptureStdout();
//
//    int nums[] = { 0, 1, 2 };
//    int size1 = sizeof(nums) / sizeof(nums[0]);
//    List<int> intList3(nums, size1);
//
//    int num[] = { 0, 999, 2 };
//    int size2 = sizeof(num) / sizeof(num[0]);
//    List<int> intList2(num, size2);
//
//    intList2 = intList3;
//
//    cout << intList2;
//    std::string output = testing::internal::GetCapturedStdout();
//    EXPECT_EQ(output, "List is:\n0 1 2 \n");
//
//}
TEST(CopyClasstest, BasicTest0) {
    testing::internal::CaptureStdout();


    int nums[] = { 0, 1, 2 };
    int xyx = 3;
    List<int> intList6(nums, xyx);
    
    
    List<int> intList(intList6);

    
    cout << intList;

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n0 1 2 \n");
}



TEST(IteratorTest, BasicTest0) {
    testing::internal::CaptureStdout();


    std::string myNum[3] = { "fsd","sadasd","dsad" };
    int x = 3;
    List<std::string> list3(myNum, x);
   
    cout << "List is:";
    for (Iterator<std::string> it = list3.beginn();
        it != list3.end();
        it++)
    {
        std::cout << " " << *it ;
    }

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is: fsd sadasd dsad");
}

TEST(ReverseIteratorTest, BasicTest0) {
    testing::internal::CaptureStdout();


    std::string myNum[3] = { "fsd","sadasd","dsad" };
    int x = 3;
    List<std::string> list3(myNum, x);

    cout << "List is:";

    for (Reverse_Iterator<string> iter = list3.beginnn();
        iter != list3.endd();
        iter++)
    {
        std::cout << " " << *iter;
    }

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is: dsad sadasd fsd");
}

TEST(ConstReverseIteratorTest, BasicTest0) {
    testing::internal::CaptureStdout();


    std::string myNum[3] = { "fsd","sadasd","dsad" };
    int x = 3;
    List<std::string> list3(myNum, x);

    cout << "List is:";

    for (Const_Reverse_Iterator<string> iter = list3.cbeginnn();
        iter != list3.cendd();
        iter++)
    {
        std::cout << " " << *iter;
    }

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is: dsad sadasd fsd");
}

TEST(ConstIteratorTest, BasicTest0) {
    testing::internal::CaptureStdout();


    std::string myNum[3] = { "fsd","sadasd","dsad" };
    int x = 3;
    List<std::string> list3(myNum, x);

    cout << "List is:";
    for (Const_Iterator<std::string> it = list3.cbeginn();
        it != list3.cend();
        it++)
    {
        std::cout << " " << *it;
    }

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is: fsd sadasd dsad");
}

TEST(SizeTest, BasicTest0) {
    testing::internal::CaptureStdout();

    int nums[] = { 3,2,1 };
    int xyx = 3;
    List<int> intList(nums, xyx);

    intList.Print();
    cout << intList.get_size() << endl;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n3 2 1 \n3\n");
}

TEST(InputOperator, BasicTest1) {
    testing::internal::CaptureStdout();
    

   
    List<int> intList3;

    
    cin >> intList3;
    cout << intList3;

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "List is:\n5 \n");
}