#include <stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#define NULL 0

int size=0;

struct t_time{
int h;
int m;
int s;
};

struct t_timetable{
    struct t_time key;
    char *val;
    struct t_timetable *next;
    };
struct t_timetable *first,*last;



void main(){
}

int time_cmp(struct t_time h1, struct t_time h2){

    if ((h1.h) > (h2.h)){
        return 1;
    }else if ((h2.h) > (h1.h)){
        return -1;
    }else if((h1.h) == (h2.h)){
        if(h1.m > h2.m){
            return 1;
        }else if(h2.m > h1.m){
            return -1;
        }else if(h1.m == h2.m){
            if(h1.s > h2.s){
                return 1;
            }else if(h2.s > h1.s){
                return -1;
            }else{return 0;}
        }
    }
}

void put(struct t_time key, char * val){

    int n = contains(key);
    if(n==1){
        struct t_timetable *p;
        p = malloc(sizeof(struct t_timetable));
        p->key = key;
        p->val = val;
        p->next = NULL;

        if(size == 0){
            first=p;
            last=p;
        }
        else{
            last->next = p;
            last = p;
        }
        size++;
    }
}

int contains(struct t_time key){
    int i,flag = 0;
    struct t_timetable *p;
    p = first;
    for(i=0;i<size;i++){
        if (time_cmp(p->key, key) != 0){
        flag = 1;
        p = p->next;
        }
        if(flag == 0){
            return 0;
        }else{return 1;}
    }
}

void Delete(struct t_time key){
    int a;
    struct t_timetable *p,*q;
    p=first;
    a=contains(key);
    if(a==0)
        printf("\n\tLabel not found\n");
    else{
        if(time_cmp(first->key,key)==0)
        first=first->next;
    else if(time_cmp(last->key,key)==0){
        q = p->next;
        while(time_cmp(q->key,key)!=0){
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        last = p;
    }else{
        q = p->next;
        while(time_cmp(q->key,key)!=0){
        p = p->next;
        q = q->next;
        }
        p->next = q->next;
    }
    size--;
    }
}
