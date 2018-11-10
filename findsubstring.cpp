#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define maxlenth 2000
void getnext(char p[maxlenth], int next[maxlenth]) 
{
	int j = 0, k = -1, lenthp = strlen(p);
	next[0] = -1;
	while (j < lenthp)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else k = next[k];
	}
}
void findsubstring(char t[maxlenth], char p[maxlenth], int next[maxlenth])
{
	bool flag = 0;
	int posp = 0, post = 0;
	int lenthp = strlen(p);
	int lentht = strlen(t);
	while (post < lentht)
	{
		if (posp == -1 || p[posp] == t[post])
		{
			posp++;
			post++;
		}
		else posp = next[posp];
		if (posp >= lenthp)
		{
			flag = 1;
			cout << post - lenthp << ' ';
			posp = 0;
		}
	}
	if (!flag)cout << -1;
	cout << endl;
}
int main()
{
	int m, n;
	char t[maxlenth] = { '\0' };
	char p[maxlenth] = { '\0' };
	int next[maxlenth] = { 0 };
	while (cin>>m)
	{
		cin >> n;
		cin >> t >> p;
		getnext(p, next);
		findsubstring(t, p, next);
	}
	return 0;
}