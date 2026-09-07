#include <string>
#include <vector>
#include <sstream>

using namespace std;

// #
string normalize(string melody) {
    string result;

    for(int i=0; i<melody.size(); i++) {
        if(i+1<melody.size() && melody[i+1]=='#') {
            result += tolower(melody[i]);
            i++;
        }
        else {
            result += melody[i];
        }
    }

    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxTime = 0;

    m = normalize(m);

    for (int i = 0; i < musicinfos.size(); i++) {
        stringstream ss(musicinfos[i]);

        string startH, startM;
        string endH, endM;
        string title, melody;

        getline(ss, startH, ':');
        getline(ss, startM, ',');
        getline(ss, endH, ':');
        getline(ss, endM, ',');
        getline(ss, title, ',');
        getline(ss, melody);

        int startTime = stoi(startH)*60 + stoi(startM);
        int endTime = stoi(endH)*60 + stoi(endM);
        int playTime = endTime - startTime;

        melody = normalize(melody);

        string played;

        for (int j=0; j<playTime; j++) {
            played += melody[j%melody.size()];
        }

        if (played.find(m) != string::npos) {
            if (playTime > maxTime) {
                maxTime = playTime;
                answer = title;
            }
        }
    }

    return answer;
}