小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，
但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含
了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么
告诉她缺了多少珠子。
为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色.
输入格式：
每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想
做的珠串，两串都不超过1000个珠子。
输出格式：
如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一
行中输出“No”以及缺了多少珠子。其间以1个空格分隔。
输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2


m=list(input())
n=list(input())
c=0
for i in range(len(n)):
    if n[i] in m:
        point=m.index(n[i])
        m[point]=None
        c+=1
if c==len(n):
    print('Yes',(len(m)-len(n)))
else:
    print('No',(len(n)-m.count(None)))
    
    
#include <iostream>
#include <map>	
using namespace std;
	
int main()		
{	
	string s1, s2;
	cin >> s1 >> s2;
	map<char, int> mp1, mp2;
	int i, cnt = 0;
	for (i = 0; s1[i]; ++i)
		mp1[s1[i]]++;
	for (i = 0; s2[i]; ++i)
		mp2[s2[i]]++;

	for (auto i:mp2) {
		if (i.second > mp1[i.first])
			cnt += (i.second - mp1[i.first]);
	}
	if (cnt == 0)
		cout << "Yes" << ' ' << s1.size() - s2.size();
	else
		cout << "No" << ' ' << cnt;
}	    

