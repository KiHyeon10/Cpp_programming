#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(*max_element(wallet.begin(), wallet.end()) < *max_element(bill.begin(), bill.end()) ||
         *min_element(wallet.begin(), wallet.end()) < *min_element(bill.begin(), bill.end())) {
        if(bill[0] >= bill[1]){
            bill[0] /= 2;
        }
        else if(bill[0] < bill[1]){
            bill[1] /= 2;
        }
        answer += 1;
    }
    return answer;
}
