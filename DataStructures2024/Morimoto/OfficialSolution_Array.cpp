//made by Ralfazza Rajariandhana with help of google and others
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define INF 2147483647
#define nl cout << endl

int AB_Pruning(int cur, int arr[], int depth, int alpha, int beta, int maxing)
{
    if(depth==0) return arr[cur];

    if(maxing)
    {
        int maxEval = -INT_MAX;
        for(int i=1; i<=2; i++)
        {
            int eval = AB_Pruning((cur*2)+i,arr,depth-1,alpha,beta, false);
            maxEval = max(maxEval,eval);
            alpha = max(alpha,eval);
            if(beta <= alpha) break;
        }
        return maxEval;
    }
    else
    {
        int minEval = INT_MAX;
        for(int i=1; i<=2; i++)
        {
            int eval = AB_Pruning((cur*2)+i,arr,depth-1,alpha,beta, true);
            minEval = min(minEval,eval);
            beta = min(beta,eval);
            if(beta <= alpha) break;
        }
        return minEval;
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int size=(n*2)-1;
    int arr[size];
    for(int i=n-1; i<size; i++) cin>>arr[i];
    cout<<AB_Pruning(0,arr,(int)log2(n),-INT_MAX,INT_MAX,true)<<endl;
}