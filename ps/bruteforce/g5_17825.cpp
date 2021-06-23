#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> noon;
//vector<int> pos;

int board[50] = {2,4,6,8,10,12,14,16,18,20,
                22,24,26,28,30,32,34,36,38,40
                ,10,13,16,19,25,30,35,40,0,0
                ,20,22,24,25,30,35,40,0,0,0
                ,30,28,27,26,25,30,35,40,0,0};

int move(int idx, int movement, vector<int> *pos)
{
    if ((*pos)[idx] == -2) return -1;
    int score;
    int respos;
    // 도착 지점에 가버릴 때
    if (((*pos)[idx] == 19) || ((*pos)[idx]+1)%5 != 0 && (*pos)[idx] < 20 && (*pos)[idx] + movement >= 20) {(*pos)[idx] = -2; return 0;}
    if ((*pos)[idx] >= 20 && (*pos)[idx] / 10 != ((*pos)[idx] + movement) / 10) {(*pos)[idx] = -2; return 0;};
    if ((*pos)[idx] + movement >= 20 && board[(*pos)[idx] + movement] == 0) {(*pos)[idx] = -2; return 0;};
    // 꺾는 부분일 때
    if ((*pos)[idx]+1 < 20 && ((*pos)[idx]+1)%5 == 0 && (*pos)[idx] != -1)
        respos = ((((*pos)[idx]+1)/5 +1) * 10) + movement;
    else
        respos = (*pos)[idx] + movement;
    // 다른 말과 겹치면 갈 수 없다.
    for (int i =0;i<4;++i)
        if ((*pos)[i] == respos ||
        ((*pos)[i] >= 20 && respos >= 20 && board[(*pos)[i]] == board[respos]) ||
        (board[(*pos)[i]] == 40 && board[respos] == 40))
            return -1;
    (*pos)[idx] = respos;

    return board[respos];
}

int dfs(int t, int sum, vector<int> pos)
{
    int score;
    int res = -1;
    vector<int> o_pos(4);
    for (int i =0;i<4;++i)
        o_pos[i] = pos[i];
    if (t == 10) {
        // if (sum == 201)
        // {
        // for (int j=0;j<4;++j)
        //     cout << pos[j] << ' ';
        // cout << sum;
        // cout << endl;
        // }
        return sum;
    }
    for (int i=0;i<4;++i)
    {
        score = move(i,noon[t],&pos);
        if (score != -1)
        {
            res = max(res, dfs(t+1, sum+score,pos));
            for (int i=0;i<4;++i)
                pos[i] = o_pos[i];
        }
    }
    // if (res == 202)
    // {
    // cout << t << " ";
    // for (int j=0;j<4;++j)
    //     cout  <<  pos[j] << ' ';
    // cout << sum;
    // cout << endl;
    // }
    return (res);
}

int main(void)
{
    noon = vector<int>(10);
    vector<int> pos = vector<int>(4,-1);
    for (int i=0;i<10;++i)
        cin >> noon[i];
    cout << dfs(0, 0, pos) << "\n";
    
}
