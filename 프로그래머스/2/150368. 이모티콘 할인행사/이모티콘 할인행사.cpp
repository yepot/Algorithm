#include <string>
#include <vector>

using namespace std;

int maxP = 0;
int maxSales = 0;

int discount[4] = {10, 20, 30, 40};
int use[8];

vector<vector<int>> user;
vector<int> emoticon;

void dfs(int depth) {
    if (depth == emoticon.size()) {
        int p = 0;
        int sales = 0;

        // 현재 할인율 조합으로 사용자별 구매 금액 계산
        for (int i=0; i<user.size(); i++) {
            int totalPrice = 0;

            for (int j=0; j<emoticon.size(); j++) {
                if (use[j] >= user[i][0]) {
                    totalPrice += emoticon[j]*(100-use[j])/100;
                }
            }

            // 가입 기준 금액 이상이면 플러스 가입
            if (totalPrice >= user[i][1]) {
                p++;
            } 
            else {
                sales += totalPrice;
            }
        }

        // 가입자 수를 먼저 비교
        if(p > maxP) {
            maxP = p;
            maxSales = sales;
        } 
        else if(p == maxP && sales > maxSales) {
            maxSales = sales;
        }

        return;
    }

    for (int i=0; i<4; i++) {
        use[depth] = discount[i];
        dfs(depth +1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    user = users;
    emoticon = emoticons;

    maxP = 0;
    maxSales = 0;

    dfs(0);

    return {maxP, maxSales};
}