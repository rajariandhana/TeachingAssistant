//made by Ralfazza Rajariandhana with help of google and others
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define INF 2147483647
#define nl cout << endl

struct Node {
    Node *left, *right;
    int key;
};
deque <int> leafValues;

struct MMTree {
    Node *_root;
    unsigned int height;
    void init(int setHeight) {
        _root = __insert(_root,setHeight);
        height = setHeight;
    }
    void traverseInorder() {
        __inorder(_root);
        cout<<endl;
    }
    int Solve(bool usePruning)
    {
        if(usePruning) return __AB_Pruning(_root, height, -INT_MAX, INT_MAX, true);
        else return __MiniMax(_root, height, true);
    }

private:
    Node* __createEmptyNode() {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->key = -INT_MAX;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    Node* __insert(Node *root, int height) {
        root = __createEmptyNode();
        if (height==0)
        {
            root->key = leafValues.front();
            leafValues.pop_front();
            return root;
        }
        root->left = __insert(root->left, height-1);
        root->right = __insert(root->right, height-1);
        return root;
    }
    void __inorder(Node *root) {
        if (root) {
            __inorder(root->left);
            if(root->key!= -INT_MAX) printf("%d ", root->key);
            __inorder(root->right);
        }
    }
    int __AB_Pruning(Node *root, int depth, int alpha, int beta, bool maxing)
    {
        if(depth==0) return root->key;
        if(maxing)
        {
            int maxEval = -INT_MAX;
            for(int i=0; i<2; i++)
            {
                int eval = __AB_Pruning(i==0?root->left:root->right, depth-1, alpha, beta, false);
                maxEval = max(maxEval,eval);
                alpha = max(alpha,eval);
                if(beta<=alpha) break;
            }
            return maxEval;
        }
        else
        {
            int minEval = INT_MAX;
            for(int i=0; i<2; i++)
            {
                int eval = __AB_Pruning(i==0?root->left:root->right, depth-1, alpha, beta, true);
                minEval = min(minEval,eval);
                beta = min(beta,eval);
                if(beta<=alpha) break;
            }
            return minEval;
        }
        return -INT_MAX;
    }
    int __MiniMax(Node *root, int depth, bool maxing)
    {
        if(depth==0) return root->key;
        if(maxing)
        {
            int maxEval = -INT_MAX;
            for(int i=0; i<2; i++)
            {
                int eval = __MiniMax(i==0?root->left:root->right, depth-1, false);
                maxEval = max(maxEval,eval);
            }
            return maxEval;
        }
        else
        {
            int minEval = INT_MAX;
            for(int i=0; i<2; i++)
            {
                int eval = __MiniMax(i==0?root->left:root->right, depth-1, true);
                minEval = min(minEval,eval);
            }
            return minEval;
        }
        return -INT_MAX;
    }
};

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        leafValues.push_back(x);
    }
    // for(int i=0;i<n;i++)cout<<leafValues[i]<<" ";
    // cout<<endl;
    MMTree mm;
    mm.init((int)log2(n));
    // mm.traverseInorder();
    cout<<mm.Solve(true)<<endl;
}
/*
4096 2731
*/