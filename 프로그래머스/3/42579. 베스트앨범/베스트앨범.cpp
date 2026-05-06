#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first)
        return a.second<b.second;
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르별 노래 목록: 장르 -> {재생수, 고유번호}
    unordered_map<string, vector<pair<int, int>>> songs;

    // 장르별 총 재생 수
    unordered_map<string, int> totalPlay;

    for (int i = 0; i < genres.size(); i++) {
        songs[genres[i]].push_back({plays[i], i});
        totalPlay[genres[i]] += plays[i];
    }

    // 장르 정렬용 vector
    vector<pair<int, string>> genreOrder;

    for (auto g : totalPlay) {
        genreOrder.push_back({g.second, g.first});
    }

    sort(genreOrder.begin(), genreOrder.end(), greater<>());

    // 각 장르 안에서 노래 정렬
    for (auto &s : songs) {
        sort(s.second.begin(), s.second.end(), cmp);
    }

    // 장르별 최대 2곡씩 answer에 추가
    for (int i=0; i<genreOrder.size(); i++) {
        string genre = genreOrder[i].second;

        for (int j=0; j<songs[genre].size() && j<2; j++) {
            answer.push_back(songs[genre][j].second);
        }
    }

    return answer;
}