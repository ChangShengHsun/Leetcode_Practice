#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    vector<int> carry(digits.size(), 0);
    carry[digits.size()-1] = 1;
    vector<int> ans(digits.size(), 0);
    for (int i = digits.size() - 1; i > 0; i--)
    {
        ans[i] = carry[i] + digits[i];
        if (ans[i] >= 10)
        {
            ans[i] -= 10;
            carry[i - 1] += 1;
        }
    }

    ans[0] = carry[0] + digits[0];
    if(ans[0] >= 10){
        vector<int> newans(digits.size() + 1, 0);
        newans[0] = 1;
        newans[1] = ans[0] - 10; 
        for(int i = 1 ; i < digits.size() ; i++){
            newans[i+1] = ans[i];
        }
        return newans;
    }
    return ans;
}