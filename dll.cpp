#include<iostream>
using namespace std;
class dll
{
private:
struct node
{
    int data;
    node*next;
    node*prev;
};
node* first,*last;
int len;    
public:
    dll(){first=last=nullptr;len=0;}
    bool isempty(){return len==0;}
    void insertfirst(int item){
        node* newnode=new node;
        newnode->data=item;
        newnode->next=newnode->prev=nullptr;
        if(isempty()){
            first=last=newnode;
        }else{
            newnode->next=first;
            first->prev=newnode;
            first=newnode;
        }
        len++;
    }
    void insertlast(int item){
        node* newnode=new node;
        newnode->data=item;
        newnode->next=newnode->prev=nullptr;
        if(isempty()){
            first=last=newnode;
        }else{
            newnode->prev=last;
            last->next=newnode;
            last=newnode;
        }
        len++;
    }
    void insertatpos(int pos,int item){
        if(pos>len||pos<0){
            cout<<"position out of range"<<endl;
        }else{
            if(pos==0){insertfirst(item);}
            else if(pos==len){insertlast(item);}
            else{
                node* cur=first;
                node* newnode=new node;
                newnode->data=item;
                for(int i=0;i<pos;i++){
                    cur=cur->next;
                }
                // Update pointers for the new node
                newnode->next=cur->next;
                newnode->prev=cur;
                 // Update pointers for adjacent nodes
                (cur->next)->prev=newnode;
                cur->next=newnode;
                len++;
            }
        }
    }
    void removefirst(){
        if(isempty()){
            cout<<"list already empty"<<endl;
        }else if(len==1){
            delete first;
            first=last=nullptr;
            len=0;
        }else{
            node* cur=first;
            first=first->next;
            first->prev=nullptr;
            delete cur;
            len--;
        }
    }
    void removelast(){
        if(isempty()){
            cout<<"list already empty"<<endl;
        }else if(len==1){
            delete first;
            first=last=nullptr;
            len=0;
        }else{
            node* cur=last;
            last=last->prev;
            last->next=nullptr;
            delete cur;
            len--;
        }
    }
    void removeatpos(int pos){
        if(isempty()){
            cout<<"list already empty"<<endl;
            return;
        }
        if(pos>=len || pos<0){cout<<"posout of range"<<endl;return;}
        if(pos==0){removefirst();}
        else if(pos==len-1){removelast();}
        else{
            node* cur=first;
            for(int i=0;i<pos;i++){
                cur=cur->next;
            }
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            delete cur;
            len--;
        }
    }
};
