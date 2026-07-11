// The answer is in the depth of five fathoms. Waiting to be retrieved.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

inline void optimizeIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
    Node() : val(), next(nullptr) {};
};
Node *pos[1000005];
int main()
{
    optimizeIO();

    int n;
    cin >> n;

    Node *head = new Node(1);

    
    pos[1] = head;

    while (n--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            // y插入x后面

            Node *newNode = new Node(y);
            // head->next=newNode;

            

            Node *cur = pos[x];

            if (cur->next != nullptr)
            {
                // 有已经指着的人了
                Node *Mid = cur->next;
                newNode->next = Mid;
                cur->next = newNode;

                pos[y] = newNode;
            }
            else
            {
                // 没人被指着

                cur->next = newNode;
                pos[y] = newNode;
            }
        }
        else if (type == 2)
        {
            int x;
            cin >> x;

            Node *cur = pos[x];

            if(cur->next == nullptr){
                cout<<0<<'\n';
            }else{
                cout<<cur->next->val<<'\n';
            }

        }
        else
        {
            int x;
            cin >> x;
            Node *cur = pos[x];
            Node *del = cur->next;
            cur->next = del->next;
            delete del;
        }
    }

    return 0;
}
// The answer is in the depth of five fathoms. And has always been her.