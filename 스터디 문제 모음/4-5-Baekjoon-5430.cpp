#include<bits/stdc++.h>
using namespace std;

const char REV = 'R', DEL = 'D';
const string ERROR_MSG = "error";

bool reverseFlag = false, errorFlag = false;
int T;
string command = "", arr = "", arrCnt;

void findAns(string& cmd, deque<int>& dq) {
    // cmd 요소 반복문
    // R이 실행되면 flag 토글
    // D가 실행되면 flag에 따라서 앞 또는 뒤에서 pop
    // 만약 deqeue가 비어있는데 d가 실행되면 ERROR_MSG 출력
    reverseFlag = false; // 초기화
    int size = cmd.size();
    for(int i = 0; i < size; i++) {
        switch (cmd[i]) {
            case REV:
                reverseFlag = reverseFlag ? false : true;
            break;
            case DEL:
                if (dq.empty()) {
                    errorFlag = true;
                    break;
                }

                if (reverseFlag) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            break;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 테스트 케이스 입력
    cin >> T;
    while(T--){
        cin >> command >> arrCnt >> arr;

        deque<int> dq;
        for(int i = 1 ; i < arr.size() - 1; i ++) {
            string temp = "";
            while(isdigit(arr[i])) {
                temp += arr[i];
                i++;
            }
            dq.push_back(stoi(temp));
        }

        findAns(command, dq);

        if (errorFlag) {
            cout << ERROR_MSG << "\n";
            errorFlag = false;
            continue;
        }

        // 출력
        cout << "[";
        int size = dq.size();
        if (reverseFlag) {
            for(int i = size - 1; i >= 0; i--) {
                cout << dq[i];
                if (i == 0) break;
                cout << ",";
            }
        } else {
            for(int i = 0; i < size; i++) {
                cout << dq[i];
                if (i == size - 1) break;
                cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}