#include<iostream>
using namespace std;

int a[20], n=0, st[20], top=-1, q[20], f=0, r=-1;

struct Node{
    int d;
    Node *l,*r;
    Node(int x){ d=x; l=r=NULL; }
}*root=NULL;

Node* insert(Node* t,int x){
    if(!t) return new Node(x);
    if(x<t->d) t->l=insert(t->l,x);
    else t->r=insert(t->r,x);
    return t;
}

void inorder(Node* t){
    if(t){
        inorder(t->l);
        cout<<t->d<<" ";
        inorder(t->r);
    }
}

int main(){
    int ch,x,l,h,m;
    do{
        cout<<"\n1.Add\n2.Display\n3.Sort\n4.Linear\n5.Binary\n6.Push\n7.Pop\n8.Enqueue\n9.Dequeue\n10.BST\n0.Exit\nChoice: ";
        cin>>ch;

        switch(ch){
        case 1:
            cin>>a[n];
            root=insert(root,a[n]);
            n++;
            break;

        case 2:
            for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
            break;

        case 3:
            for(int i=0;i<n-1;i++)
                for(int j=0;j<n-i-1;j++)
                    if(a[j]>a[j+1]) swap(a[j],a[j+1]);
            cout<<"Sorted\n";
            break;

        case 4:
            cin>>x;
            for(int i=0;i<n;i++)
                if(a[i]==x){ cout<<"Found\n"; goto A; }
            cout<<"Not Found\n";
            A: break;

        case 5:
            cin>>x;
            l=0; h=n-1;
            while(l<=h){
                m=(l+h)/2;
                if(a[m]==x){ cout<<"Found\n"; goto B; }
                if(a[m]<x) l=m+1;
                else h=m-1;
            }
            cout<<"Not Found\n";
            B: break;

        case 6:
            cin>>st[++top];
            break;

        case 7:
            if(top==-1) cout<<"Empty\n";
            else cout<<st[top--]<<endl;
            break;

        case 8:
            cin>>q[++r];
            break;

        case 9:
            if(f>r) cout<<"Empty\n";
            else cout<<q[f++]<<endl;
            break;

        case 10:
            inorder(root);
            cout<<endl;
            break;
        }

    }while(ch!=0);
}
