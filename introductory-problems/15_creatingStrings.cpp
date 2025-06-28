#include <iostream>
#include <set>
using namespace std;

set <string> answer;
void generateAllPermutation(string s, int index){
    if(index == s.size()){
        answer.insert(s);
        return;
    }
    for(int i = index; i < s.size(); i++){
        swap(s[index], s[i]);
        generateAllPermutation(s, index + 1);
    }
}

int main(){
    string s;
    cin >> s;
    generateAllPermutation(s, 0);
    cout << answer.size() << "\n";
    for(string str : answer) cout << str << "\n";
    return 0;
}