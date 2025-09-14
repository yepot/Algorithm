#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));

	int num;
	for(int k=0; k<2; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++){
				cin >> num;
				arr[i][j] += num;
			}	
	 	}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}   