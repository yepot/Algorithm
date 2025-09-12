#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int time[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
	string s;
    cin >> s;
	int t = 0;

	for (int i = 0; i < s.length(); i++) {
		t += time[s[i] - 'A'];
	}
	cout << t << '\n';
}   