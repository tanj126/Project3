#include "test.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test::test1()
{
	// 测试特殊字符用法
	char newline = '\n';
	char tab = '\t';
	char backspace = '\b';
	char backslash = '\\';
	char nullChar = '\0';
	cout << "Newline character: " << newline << "ending" << endl;
	cout << "Tab character: " << tab << "ending" << endl;
	cout << "Backspace character: " << backspace << "ending" << endl;
	cout << "Backslash character: " << backslash << "ending" << endl;
	cout << "Null character: " << nullChar << "ending" << endl;

	return;
}

void test::test2()
{
	// 进制值的赋值用法
	int i = 157; // 十进制
	int j = 0174; // 0开头的为八进制
	int k = 0365; // 0开头的为八进制
	int m = 36'000'000; // 用单引号可以看的更清楚
	int n = 123'000'000;

	cout << i << "\n";
	cout << j << "\n";
	cout << k << "\n";
	cout << m << "\n";
	cout << n << "\n";
	
	return;
}

void test::test3()
{

	/*
	* 通过 find_if 遍历一个容器的元素
	* 通过 lambda 表达式 求返回值
	* [=](int i) { return i > x && i <y; } 为lambda表达式
	*/

	std::vector<int> v{ 1,2,3,4,5 };
	int x = 2;
	int y = 5;

	auto result = find_if(begin(v), end(v), [=](int i)
		{
			return i > x && i <y;
		}
	);

	for (int i = 0; i < 3; i++)
	{
		std::cout << result[i] << endl;
	}
	return;
}

void test::test4()
{
	// 测试 lambda 函数
	// [&even_count](int val) { if (!(val & 1)) {++even_count; }	} 为lambda表达式
	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
	int even_count = 0;
	for_each(v.begin(), v.end(), [&](int val) { if (!(val & 1)) {++even_count; }	});
	std::cout << "The number of even is " << even_count << std::endl;
	
	/*
	* 0001 & 1 = 1
	* 0010 & 1 = 0
	* 0011 & 1 = 1
	* 0100 & 1 = 0
	* 0101 & 1 = 1
	* 0110 & 1 = 0
	*/

	return;
}

void test::test5()
{
	// 测试 lambda 函数
	std::vector<int> coll = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int count1 = std::count_if(coll.begin(), coll.end(), [](int x) { return x > 10; });
	int count2 = std::count_if(coll.begin(), coll.end(), [](int x) { return x < 10; });
	int count3 = std::count_if(coll.begin(), coll.end(), [](int x) { return x>5 && x < 10; });
	std::cout << count1<<"\n" << count2 <<"\n" << count3 <<"\n" << endl;

	return;
}
