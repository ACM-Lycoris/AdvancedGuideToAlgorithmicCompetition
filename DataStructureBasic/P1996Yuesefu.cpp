#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *pre;
    Node(int x) : val(x), next(nullptr), pre(nullptr) {}
};

Node *pos[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Node *First = new Node(1);
    pos[1] = First;

    for (int i = 1; i <= n; i++)
    {
        Node *cur = pos[i];
        Node *Next = new Node(i + 1);
        cur->next = Next;
        Next->pre = cur;
        pos[i+1]=Next;
    }

    Node *Last = pos[n];
    Last->next = First;
    First->pre = Last;

    int cnt = 1;
    int id = 1;
    
    Node *cur = First;
    int remain = n;

    while (n)
    {
        if (cnt == m)
        {
            cnt = 1;
            cout << id << ' ';
            Node *del  = cur;
            Node *Next = del->next;
            Node *Pre  = del->pre;
            Pre->next  = Next;
            Next->pre  = Pre;

            cur =Next;
            id=Next->val;
            n--;

            delete del;
            continue;

        }
        cnt++;
        cur=cur->next;//跳到下一个去
        id=cur->val;
    }
    return 0;
}