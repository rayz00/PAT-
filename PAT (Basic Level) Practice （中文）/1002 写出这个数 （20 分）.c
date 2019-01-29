读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10的100次方。
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu

//C 字符串，拆整数
#include<stdio.h>	
#include<string.h>
int main()
{
	char s[100];		//scanf输入需要确切的地址，char *s不行。因为指针没有指向有效的内存可能非法，不能开辟内存空间
	scanf("%s", s);
	const char *book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	
	//字符串数组，使用字符串常量初始化，可以定义为char s[][]，也可以加const char s[][]。
	//使用指针的话必须加const才能用字符串常量初始化：const char *s[]	
	//char s[][]不可以用字符串常量修改字符串数组的值，但可以用scanf修改
	//const char *s[]可以用字符串常量修改字符串数组，但不可以用scanf修改了
	//const char s[][]不能做任何修改
	//在这里，const char book[][5]是最准确的。字符串的详情见/algorithm/c/字符串
	int sum = 0;
	for (int i = 0; s[i]; ++i)
		sum += s[i] - '0';
	int t=0,result[10] = { 0 };		//拆数字，存放到数组里，还可以拆成其他进制表示
	while (sum) {
		result[t++] = sum % 10;
		sum /= 10;
	}
	for (int i = t - 1; i >= 0; --i) {	//需要一个辅助量帮忙格式化输出，大部分情况可以利用循环变量i；或者单独输出头尾
		printf("%s", book[result[i]]);  //如果没有循环变量i 也不好单独输出头尾的话，可以定义一个int flag=0帮忙输出
		if (i != 0)
			printf(" ");
	}
}

//C++ 字符串类型和函数
#include<iostream>	
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	int sum = 0;
	for (int i = 0; s[i]; ++i)		//for (auto i : s) sum += i - '0';
		sum += s[i] - '0';					
	string tmp = to_string(sum);		//类型转换函数
	for (int i = 0; tmp[i]; ++i) {
		if (i)
			cout << ' ';
		cout << book[tmp[i] - '0'];
	}
}
