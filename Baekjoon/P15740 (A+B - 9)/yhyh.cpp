#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX(a,b)((a)>(b)?(a):(b))

string A;
string B;
string result;
int Alen;
int Blen;

void add(string A, string B)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	Alen = A.length();
	Blen = B.length();

	int tmp = 0, overflow = 0;
	for (int i = 0; i < MAX(Alen, Blen); i++)
	{
		if (i >= Alen) tmp = overflow + B[i] - '0';
		else if (i >= Blen) tmp = overflow + A[i] - '0';
		else tmp = overflow + A[i] - '0' + B[i] - '0';

		if (tmp >= 10)
		{
			tmp -= 10;
			overflow = 1;
		}
		else overflow = 0;
		result.push_back(tmp + '0');
	}
	if (overflow)result.push_back('1');
	reverse(result.begin(), result.end());
	cout << result << "\n";
}
void sub(string A, string B)//A>B
{
	//A-B
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	Alen = A.length();
	Blen = B.length();

	int tmp = 0, underflow = 0;
	for (int i = 0; i < MAX(Alen, Blen); i++)
	{
		if (i >= Alen) tmp = (B[i] - '0') - underflow;
		else if (i >= Blen) tmp = (A[i] - '0') - underflow;
		else tmp = (A[i] - '0' - (B[i] - '0'))-underflow;

		if (tmp < 0)
		{
			tmp += 10;
			underflow = 1;
		}
		else underflow = 0;
		result.push_back(tmp + '0');
	}
	reverse(result.begin(), result.end());
	int s = 0;
	for(s=0;s<result.length();s++)
	{
		if (result[s] != '0')break;
	}
	result = result.substr(s);
	if (result == "")result = '0';
	cout << result << "\n";
}


int main()
{
	cin >> A >> B;
	
	if(A[0]=='-'&&B[0]=='-') //둘다 음수일때
	{
		A = A.substr(1);
		B = B.substr(1);

		cout << "-";
		add(A, B);
	}
	else if(A[0]=='-')//A가 음수일때
	{
		A = A.substr(1);

		if(A.length()>B.length()||A.length()==B.length()&&A.compare(B)>0) //A의 절댓값이 더 클때
		{
			cout << "-";
			sub(A, B);
		}
		else //B의 절댓값이 더 클때
		{
			sub(B, A);
		}
	}
	else if(B[0]=='-')//B가 음수일때
	{
		B = B.substr(1);
		if (B.length() > A.length() || A.length() == B.length() && B.compare(A) > 0) //B의 절댓값이 더 클때
		{
			cout << "-";
			sub(B, A);
		}
		else {
			sub(A, B);
		}
	}
	else //둘다 아닐때
	{
		add(A, B);
	}	
}
