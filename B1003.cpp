1003 我要通过！ （20 分）
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1.字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
2.任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3.如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

解题思路： 注意到这题是有点难度的对于初学者，可能甚至读不懂这3个什么要求,并且只能是这三个要求，超出这三个要求的都不成立 
	很明显第一个要求：仅含有P、A、T
	第二个要求：任意类似xPATx是对的，其中x为空串或者A
	第三个要求很多人看不懂，如果aPbTc对，则aPbATca也对，其中a,b,c三个字母要么均是空串，要么均是A，注意题目的均 
	啥意思？举个例子， APATA 和  APAATA  这两个是对的  而APAAATA是错的因为中间有三个A，而 aPbATca的P和T中有顶多一个A或者两个A
	总结下：
	PAT   中间1个A，前面0个A   T后面1*0=0个A 
	PAAT   中间2个A，前面0个A   T后面2*0=0个A
	AAPATAA   中间1个A，前面2个A   T后面1*2=2个A
	AAPAATAAAA  中间2个A，前面2个A   T后面2*2=4个A
	思路分析好，该如何下笔？ 
	这里我们用map函数（不了解的需要了解下stl的map原理）因为我只需要出现一次P和一次T，至少也会出现一次A，那我们把
	P和T先单独列出来，出现一次对应的<char,int> int为出现次数+1；
	最核心的地方在这里：我这里用公式来判断两个简单的，如APATA, APAATAA, PAT, _P_ATAA(下划线表示空格)
	长度分别为5,7, 3, 7  为了使得PT中间只有一个A或者两个A或一个空格或者一个空格一个A，总而言之中间要么一个字母要么两个字母
	找规律公式是s.length()-1-t==p*(t-p-1)    下标 t是T的下标，p是P的下标 
	s.length()-1-t是指T后面的A个数； 如 5-1-3==1*(3-1-1) 接下来就是上代码的地方了 

# include<iostream>
# include<string.h>
# include<map>
using namespace std;

int main(void){
	freopen("in.txt","r",stdin);
	int n;
	string s;
	cin>>n;
	for(int j=0;j<n;++j){
		int p=0, t=0;
		cin>>s;
		map<char,int> mp;
		for(int i=0;i<s.length();++i){
			mp[s[i]]++;
			if(s[i]=='P')//记录P个T的位置 
				p=i;
			if(s[i]=='T')
				t=i;
		}
		if(mp.size()==3&&mp['A']!=0&&mp['P']==1&&mp['T']==1&&p*(t-p-1)==s.length()-t-1)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
} 

