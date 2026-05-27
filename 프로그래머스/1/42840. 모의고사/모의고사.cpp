#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1번: 1,2,3,4,5
// 2번: 2,1,2,3,2,4,2,5
// 3번: 3,3,1,1,2,2,4,4,5,5
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<pair<int, int>> V;
    V.push_back({0, 1});
    V.push_back({0, 2});
    V.push_back({0, 3});
    
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == a[i%5]) V[0].first++;
        if(answers[i] == b[i%8]) V[1].first++;
        if(answers[i] == c[i%10]) V[2].first++;
    }
    
    sort(V.begin(), V.end(), greater<>());
    answer.push_back(V[0].second);
    
    for(int i=1; i<3; i++) {
        if(V[i].first==V[i-1].first) answer.push_back(V[i].second);
        else break;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}