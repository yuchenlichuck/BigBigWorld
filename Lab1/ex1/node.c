// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h> // includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:
int sum=0;

// implementation
void insert_node_before(list *lst, int index, char *word)
{
    if (sum==0){
        node * n =(node*)malloc(sizeof(node));
//        printf("chenggong\n");
        
        //n = lst-> head;
//        printf("chenggong1\n");
        
        n->next=n;
//        printf("chenggong2\n");
        
        n->prev=n;
        n->word=word;
        //        node * head = (node*)malloc(sizeof(node));
        //        head->next=n;
        //        head->prev=NULL;
        //        head->word=NULL;
        lst->head=n;
        sum++;
        //printf("chenggong\n");
        //printf(",%s\n" , n->word);
    }
    else {
        int temp;
        if(index>0){
            temp=(index-1)/sum;
        }else{
            temp=(index-1)/sum-1;
        }
        int ind=(index-1)-temp*sum;

        node * p = (node*)malloc(sizeof(node));
        p=lst->head;
        node * n = (node*)malloc(sizeof(node));
        
        for(int i=0;i<ind;i++)
        {
            p=p->next;
        }
        n->word=word;
        n->next=p->next;
        p->next->prev=n;
        p->next=n;
        n->prev=p;
        sum++;
    }

    
}

void insert_node_after(list *lst, int index, char *word)
{
    // TODO
    if (sum==0){
        node * n = lst->head;
        n->next=n;
        n->prev=n;
        n->word=word;
        //        node * head = (node*)malloc(sizeof(node));
        //        head->next=n;
        //        head->prev=NULL;
        //        head->word=NULL;
        //lst->head=n;
        sum++;
    }else{
//        int ind=(index) % sum ;
        int temp;
        if(index>0){
            temp=(index)/sum;
        }else{
            temp=(index)/sum-1;
        }
        int ind=(index)-temp*sum;
    
        node * p = (node*)malloc(sizeof(node));
        p=lst->head;
        node * n = (node*)malloc(sizeof(node));
        for(int i=0;i<ind;i++)
        {
            p=p->next;
        }
        n->word=word;
        n->next=p->next;
        p->next->prev=n;
        p->next=n;
        n->prev=p;
        sum++;
    }
    
}

char *list_to_sentence(list *lst)
{
    if(lst->head==NULL)
        return " ";
    //char * string="china";
    node * p= lst->head;
    char * start=(char*)malloc(sizeof(start));
    memcpy(start,p->word,strlen(p->word)+1);
    start[0]=toupper(start[0]);
    node * head = (node*)malloc(sizeof(node));
    head = p;
    for (int i=1;i<(int)strlen(start);i++){
        start[i]=tolower(start[i]);
    }
    char * string=(char*)malloc(sizeof(start));
    memcpy(string,start,strlen(start)+1);
    p=p->next;
    while(p!=head)
    {
        //start =p->word;
        memcpy(start,p->word,strlen(p->word)+1);
        for (int i=0;i<(int)strlen(start);i++){
            start[i]=tolower(start[i]);
        }
        string=strcat(string," ");
        string=strcat(string,start);
        p=p->next;
    }
    string=strcat(string,".");
    return string;
}

void delete_node(list *lst, int index)
{
    node * pf= lst->head;
    node * pd=NULL;
    int temp;
    if(index>0){
        temp=(index)/sum;
    }else{
        temp=(index)/sum-1;
    }
    int ind=(index)-temp*sum;
    if(ind==0){
        if(sum==1){
            lst->head = NULL;
        }else{
            pf=pf->prev;//last one
            pd=lst->head;
            lst->head=pd->next;
            pf->next=lst->head;
            lst->head->prev=pf;
            printf(",%s",pd->word);
            free(pd);
        }
    }else{
        
        for(int i=0;i<ind-1;i++)
        {
            pf=pf->next;
        }

        pd=pf->next;// need to delete
        pf->next=pd->next;
        pd->prev=NULL;
        pd->next->prev=pf;
        free(pd);
        
    }
    sum--;
}

void delete_list(list *lst)
{
    node* r = lst->head->next;
    int c = 1;
    while (r != lst->head) {
        r = r->next;
        c++;
    }
    
    node * p = lst->head;
    node * n = NULL;
    printf("%d\n", c);
    
    int i;
    for (i = 0; i < c; i++) {
        if (i != c - 1) n = p->next;
        free(p);
        p = n;
    }

    lst->head=NULL;
    free(lst);
}
