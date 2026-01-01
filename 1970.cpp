#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0;
        int right = row*col;
        
        
        while(left < right){
            int day = (left + right + 1)/2;
            bool reachable = false;
            if(check_day(row, col, cells, day) == true)reachable = true;
            if(reachable){
                left = day;
            }
            else{
                right = day-1;
            }
        }
        return left;
        
    }

    bool check_day(int row, int col,  vector<vector<int>>& cells, int day)
    {
        // Build the current map state for this day
        vector<vector<int>> curMap(col, vector<int>(row, 0));
        vector<vector<bool>> reach(col, vector<bool>(row, false));
        bool reachable = false;
        for(int i = 0 ; i < day ; i++)
        {
            curMap[cells[i][1] - 1][cells[i][0] - 1] = 1;
        }

        // Run BFS from every cell in the first row
        for(int start_x = 0 ; start_x < col ; start_x++)
        {
            if(reach[start_x][0] == false && curMap[start_x][0] == 0){
                reachable = BFS(row, col, curMap, reach, start_x);
                if(reachable)break;
            }
        }
        return reachable;
    }

    bool BFS(int row, int col, vector<vector<int>>& curMap, vector<vector<bool>>& reach, int start_x){
        queue<pair<int, int>> q;
        q.push({start_x, 0});
        reach[start_x][0] = true;
        bool reachable = false;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int cur_x = x + dx[i];
                int cur_y = y + dy[i];

                if(cur_x < 0 || cur_x >= col || cur_y < 0 || cur_y >= row)continue;
                if(curMap[cur_x][cur_y] == 1)continue;
                if(reach[cur_x][cur_y] == true)continue;

                if(cur_y == row-1){
                    reachable = true;
                    break;
                }

                reach[cur_x][cur_y] = true;
                q.push({cur_x, cur_y});
            }
            if(reachable)break;
        }
        return reachable;
    }
};


int main()
{

}
