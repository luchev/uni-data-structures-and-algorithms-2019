#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void sort(string& s)
{
	int count[26] = { 0 };

	for (int i = 0; i < s.size(); i++)
	{
		count[(s[i] - 'a')]++;
	}
	int t = 0;
	while (t < s.size())
	{
		for (int i = 0; i < 26; i++)
		{
		  	if (count[i] > 0)
			{
				s[t++] = ('a' + i);
			}
		}
	}

}

bool isEqual(string a, string b)
{

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;

}
void first(string word1, string word2, int n)
{
	int n1 = word1.length();
	int n2 = word2.length();
	if (n1 == 0)
	{
		cout << "yes";
		return;
	}
	if (n1 != n2 || n1> n || n2 > n)
	{
		cout << "no";
		return;
	}
	if (isEqual(word1, word2))
	{
		cout << "yes";
		return ;
	}
	cout << word1;
	cout << "\n";
	cout << word2;
	cout << "\n";

	sort(word1.begin(), word1.end());
	sort(word2.begin(), word2.end());
	cout << word1;
	cout << "\n";
	cout << word2;
	cout << "\n";
	if (isEqual(word1, word2))
	{
		cout << "yes";
		return ;
	}
	cout << "no";
}
void testFirst()
{
	int n = 5;
	cin >> n;
	cin.ignore();


	string word1 = "";
	getline(cin, word1);
	string word2 = "";
	getline(cin, word2);
	first(word1, word2, n);
}
int main()
{
	testFirst();
	cin.get();
	return 0;
}