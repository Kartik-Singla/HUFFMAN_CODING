#include<bits/stdc++.h>
using namespace std;
/*
DATA STRUCTURES USED:
    ARRAYS
    MAPS
    PRIORITY QUEUES
    BINARY TREES
*/
// A structure to create nodes of priority queue;
class node
{
    public:
    char ch;
    int val;
    node *left;
    node*right;
    node(char c, int num, node* l=nullptr, node* r=nullptr)
    {
        ch=c;
        val=num;
        left=l;
        right=r;
    }
};
map<string,char> m;
// A comparator function to insert elements in priority queue according
// the frequency of letters
bool operator<(const node &n1,const node &n2)
{
    return n2.val < n1.val;
}

void makecodes(node* root,string str)
{
    if(root->left==nullptr && root->right==nullptr)
    {
        m[str]=root->ch;
        return;
    }
    makecodes(root->left,str+'0');//Adding '0' to the nodes left to root
    makecodes(root->right,str+'1');// Adding '1' to the nodes right to root
}
//Printing codes
void print()
{
    cout<<"\n\n";
    cout<<"The corresponding table is "<<"\n\n";
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<setw(5)<<" "<<it->first<<"\n";
    }
}
// Making a Binary Tree
void makehuffmantree(priority_queue<node> &pq)
{
    while(pq.size()!=1)
    {
        node l=pq.top();
        int sum=l.val;
        node * l1=new node(l.ch,l.val,l.left,l.right);
        pq.pop();
        node r=pq.top();
        sum+=r.val;
        node* r1=new node(r.ch,r.val,r.left,r.right);
        pq.pop();
        pq.push(node('#',sum,l1,r1));
    }
    //Contents of the top of the queue is copied in a pointer
    node * temp=new node(pq.top().ch,pq.top().val,pq.top().left,pq.top().right);
    vector<int> vec;
    string str="";
    //Root pointer passed to makecodes function to make the corresponding codes
    makecodes(temp,str);
    print(); // Printing the corresponding codes
}
// A function to create initial minimum priority queue
void makeheap(char arr[], int freq[], int n)
{
    priority_queue<node> pq;
    for(int i=0;i<n;i++)
        pq.push(node(arr[i],freq[i]));
        makehuffmantree(pq);
}
//Driver Program
int main()
{
    int n;
    cout<<"Enter number of characters ";
    cin>>n;
    cout<<"Enter characters"<<"\n";
    char *arr=new char[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int *freq=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter frequency of character "<<arr[i]<<" ";
        cin>>freq[i];
    }
    makeheap(arr,freq,n);

}
