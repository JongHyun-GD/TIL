#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> has_number(10, false);
    for (int i = 0; i < numbers.size(); ++i) {
        int num = numbers[i];
        has_number[numbers[i]] = true;
    }
    
    for (int i = 0; i < 10; ++i)
        if (has_number[i] == false)
            answer += i;
    
    return answer;
}
