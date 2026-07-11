#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *pre;
    Node(int x) : val(x), next(nullptr), pre(nullptr) {}
};

const int MAXN = 100005;
Node *pos[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Node *newNode = new Node(1);
    pos[1] = newNode;

    Node* Left = newNode;

    for (int i = 2; i <= N; i++)
    {
        int k, p;
        cin >> k >> p;
        // 将 i 插入 k 的 p侧
        Node *curK = pos[k];
        Node *curI = new Node(i);

        if (p == 0)
        {
            // 左
            if (curK->pre != nullptr)
            {
                Node *curPre = curK->pre;
                curPre->next = curI;
                curI->pre = curPre;
            }else{
                //最左端节点被置换
                Left=curI;
            }

            pos[i] = curI;

            curI->next = curK;
            curK->pre = curI;

        }
        else
        {
            // 右
            if (curK->next != nullptr)
            {
                Node *curNext = curK->next;
                curNext->pre = curI;
                curI->next = curNext;
            }

            pos[i] = curI;

            curI->pre = curK;
            curK->next = curI;
        }
    } // 插入结束


    // 删除
    int M;
    cin >> M;
    while (M--)
    {

        int x;
        cin >> x;
        // 待删除目标
        if (pos[x] == nullptr)
        {
            continue;
        }

        Node *cur = pos[x];
        if (cur->pre != nullptr)
        {
            // 左边有东西
            Node *curLeft = cur->pre;
            if (cur->next != nullptr)
            {
                // 右边也有

                Node *curRight = cur->next;

                curLeft->next = curRight;
                curRight->pre = curLeft;

                delete cur;
            }
            else
            {
                // 右边没东西
                curLeft->next = nullptr;
                delete cur;
            }
        }
        else
        {
            // 左边没东西，最左端节点被置换
            if (cur->next != nullptr)
            {
                // 右边有东西
                Node* curRight = cur->next;
                curRight->pre = nullptr;
                Left=curRight;
                delete cur;
            }
            else
            {
                // 左右都没东西
                Left=nullptr;
                delete cur;
            }
        }
        pos[x] = nullptr;
    }

    for(Node* I = Left; I != nullptr; I = I->next){
        cout<<I->val<<' ';
    }
    cout<<'\n';

    return 0;
}