#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
	vector<vector<char>> A(N, vector<char>(N));
	vector<vector<char>> B(M, vector<char>(M));
	
	for(auto &x : A)
		for(auto &y : x)
			cin >> y;
	for(auto &x : B)
		for(auto &y : x)
			cin >> y;

	bool ans = 0;
	for(int i = 0; i < N - M + 1; i++){
		for(int j = 0; j < N - M + 1; j++){
			bool ok = 1;
			for(int k = 0; k < M; k++){
				for(int l = 0; l < M; l++){
					ok &= (A[i+k][j+l] == B[k][l]);
				}
			}
			ans |= ok;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
