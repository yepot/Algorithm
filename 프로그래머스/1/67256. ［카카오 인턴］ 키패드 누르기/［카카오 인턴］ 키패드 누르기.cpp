#include <string>
#include <vector>
#include <math.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int curR = 12;
    int curL = 10;
        
    for(int i=0; i<numbers.size(); i++) {
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7) {
            answer += 'L';
            curL = numbers[i];
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9) {
            answer += 'R';
            curR = numbers[i];
        }
        else {
            if(numbers[i]==0) numbers[i]=11;
            pair<int, int> tmpN = {(numbers[i]-1)/3, (numbers[i]-1)%3};
            pair<int, int> tmpR = {(curR-1)/3, (curR-1)%3};
            pair<int, int> tmpL = {(curL-1)/3, (curL-1)%3};
            
            int NR_x = abs(tmpN.first - tmpR.first);
            int NR_y = abs(tmpN.second - tmpR.second);
            
            int NL_x = abs(tmpN.first - tmpL.first);
            int NL_y = abs(tmpN.second - tmpL.second);
            
            if(answer=="" || (NR_x+NR_y == NL_x+NL_y)) {
                if(hand=="right") {
                    answer += 'R';
                    curR = numbers[i];
                }
                else {
                    answer += 'L';
                    curL = numbers[i];
                }
            }
            else if(NR_x+NR_y < NL_x+NL_y) {
                answer += 'R';
                curR = numbers[i];
            }
            else if(NR_x+NR_y > NL_x+NL_y) {
                answer += 'L';
                curL = numbers[i];
            }
        }
    }
    
    return answer;
}