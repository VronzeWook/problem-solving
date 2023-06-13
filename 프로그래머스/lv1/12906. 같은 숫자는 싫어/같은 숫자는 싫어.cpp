#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> answer;
    int _prev  = arr[0];
    answer.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != _prev){
            answer.push_back({arr[i]});
        }
        _prev = arr[i];
    }
    
    return answer;
}