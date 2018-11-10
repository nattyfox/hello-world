#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
	string predictPartyVictory(string senate) {
		vector<char> tp;
		for (char ch : senate) {
			tp.push_back(ch);
		}
		char res = RES(tp);
		return res == 'R' ? "Radiant" : "Dire";
	}

	char RES(vector<char> v) {
		if (v.size() == 1) { return v[0]; }
		unordered_map<char, int> set_tp;

		for (auto ch : v) {
			set_tp.insert(pair<char, int>(ch, 1));
		}
		int label = 0;
		while (set_tp.size()>1) {
			vector<char> tp;

			for (auto ch : v) {
				if (ch == 'R') {
					if (label >= 0) { tp.push_back('R'); }
					label++;
				}
				if (ch == 'D') {
					if (label <= 0) { tp.push_back('D'); }
					label--;
				}
			}
			set_tp.clear();
			v = tp;
			for (auto ch : tp) {
				set_tp.insert(pair<char, int>(ch, 1));
			}
		}
		return set_tp.begin()->first;
	}
};
int main() {
	Solution s;
	string str;
	while (cin >> str) 
	{
		cout << s.predictPartyVictory(str) << endl;
	}
	//system("pause");
	return 0;
}