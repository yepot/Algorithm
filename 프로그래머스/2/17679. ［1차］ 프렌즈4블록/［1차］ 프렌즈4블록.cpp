#include <string>
#include <vector>

using namespace std;

// R M A F N T J C
// -
int answer = 0;

// 재배열
vector<string> func(vector<string> board) {
    int h = board.size();
    int w = board[0].size();

    vector<vector<char>> v(w);

    // 각 열의 살아 있는 블록을 아래부터 저장
    for(int c=0; c<w; c++) {
        for(int r=h-1; r>= 0; r--) {
            if(board[r][c] == '-') continue;
            v[c].push_back(board[r][c]);
        }
    }

    // 저장한 블록을 각 열의 아래부터 배치
    for(int c=0; c<w; c++) {
        int r = h-1;

        for(char ch : v[c]) {
            board[r][c] = ch;
            r--;
        }

        while(r >= 0) {
            board[r][c] = '-';
            r--;
        }
    }

    return board;
}

// 확인 -> 제거
bool check(vector<string>& board) {
    int h = board.size();
    int w = board[0].size();

    vector<vector<bool>> removed(h, vector<bool>(w, false));
    bool block = 0;

    // 제거 대상만 표시만!
    for (int i=0; i<h-1; i++) {
        for (int j=0; j<w-1; j++) {
            char tmp = board[i][j];
            if(tmp == '-') continue;

            if(board[i+1][j] == tmp && board[i][j+1] == tmp && board[i+1][j + 1] == tmp) {

                removed[i][j] = 1;
                removed[i+1][j] = 1;
                removed[i][j+1] = 1;
                removed[i+1][j+1] = 1;
                block = 1;
            }
        }
    }

    // 탐색이 끝난 뒤 한꺼번에 제거
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(removed[i][j]) {
                board[i][j] = '-';
                answer++;
            }
        }
    }

    return block;
}

int solution(int m, int n, vector<string> board) {
    
    while(check(board)) {
        board = func(board);
    }
    
    return answer;
}