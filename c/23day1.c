#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node*next;
}Node;
Node*crateNode(int val){
    Node*newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        perror("malloc failed");
        exit(1);
    }
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
    Node*insertAtTail(Node*head,int val){
        Node*newNode=crateNode(val);
        if(head==NULL){
            return newNode;
        }
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        return head;
    }
    void printList(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
    void freeList(Node*head){
        Node*temp;
        while(head!=NULL){
                temp=head;
                head=head->next;
                free(temp);
            }
        }
        Node*findNode(Node*head,int target){
            Node*temp=head;
            while(temp!=NULL){
                if(temp->data==target){
                    return temp;
                }
                temp=temp->next;
            }
            return NULL;
        }
        Node*reverseList(Node*head){
            Node*pre=NULL;
            Node*cur=head;
            Node*next=NULL;
            while(cur!=NULL){
                next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=next;
            }
            return pre;
        }
int main(){
Node*head=NULL;
head=insertAtTail(head,1);
head=insertAtTail(head,2);
head=insertAtTail(head,3);
head=insertAtTail(head,4);
printf("原链表：");
printList(head);
int target =3;
Node*found=findNode(head,target);
if(found!=NULL){
    printf("找到节点：%d\n",found->data);
}else{
    printf("未找到节点%d\n",target);
}
head=reverseList(head);
printf("反转后链表：");
printList(head);
freeList(head);
head=NULL;
    return 0;
}