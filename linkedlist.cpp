#include<iostream>
using namespace std;
class linkedlist
{
private:
    struct node
    {
        int data;
        node* next;
    };
    node*first;
    node*last;
    int len;
    
public:
    linkedlist(){first=last=nullptr; len=0;}
    ~linkedlist();
    bool isempty(){return len==0;}
    void insertfirst(int item){
        node* newnode=new node;
        newnode->data=item;
        if(isempty()){
            first=last=newnode;
            newnode->next=nullptr;
        }else{
            newnode->next=first;
            first=newnode;
        }
        len++;
    }
    /*node* cur=first;
    node* newnode=new node;
    newnode->data=item;
    for (int i = 0; i < pos; i++)
    {
        cur=cur->next;
    }
    newnode->next=cur->next;
    cur->next=newnode;
    len++;*/
    /*
    void removeatpos(int pos){
    if(pos==0){removefirst();}
    else if(pos==len-1){removelast();}
    else{
    node* cur=first->next;
    node* pre= first;
    for(int i=1;i<pos;i++){
    pre=cur;
    cur=cur->next;
    }
    pre->next=cur->next;
    delete cur;
    len--;
    }
    }
    void print(){
    node* cur=first;
    while(cur!=nullptr){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
   }

    */
   
    
};
int main(){
    cout<<6<<endl;
}