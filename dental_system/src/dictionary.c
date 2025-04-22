#include "dictionary.h"
#include <stdlib.h>
#include <string.h>

static int hash(const char *s,int mod){
    unsigned h=5381;
    for(;*s;++s) h=((h<<5)+h)+*s;
    return h%mod;
}

Dictionary *dict_create(int cap){
    if(cap<16) cap=16;
    Dictionary *d = malloc(sizeof *d);
    if(!d) return NULL;
    d->table = calloc(cap,sizeof(DictEntry*));
    if(!d->table){ free(d); return NULL;}
    d->capacity = cap;
    return d;
}

void dict_destroy(Dictionary *d){
    if(!d) return;
    for(int i=0;i<d->capacity;i++){
        DictEntry *cur=d->table[i];
        while(cur){ DictEntry *nxt=cur->next; free(cur); cur=nxt;}
    }
    free(d->table); free(d);
}

bool dict_put(Dictionary *d,const char *key,Patient *val){
    if(!d) return false;
    int idx=hash(key,d->capacity);
    for(DictEntry *e=d->table[idx]; e; e=e->next)
        if(strcmp(e->key,key)==0){ e->val=val; return true; }
    DictEntry *e=malloc(sizeof *e);
    strcpy(e->key,key); e->val=val;
    e->next=d->table[idx]; d->table[idx]=e;
    return true;
}

Patient *dict_get(const Dictionary *d,const char *key){
    if(!d) return NULL;
    int idx=hash(key,d->capacity);
    for(DictEntry *e=d->table[idx]; e; e=e->next)
        if(strcmp(e->key,key)==0) return e->val;
    return NULL;
}

bool dict_remove(Dictionary *d,const char *key){
    if(!d) return false;
    int idx=hash(key,d->capacity);
    DictEntry **pp=&d->table[idx];
    while(*pp){
        DictEntry *e=*pp;
        if(strcmp(e->key,key)==0){ *pp=e->next; free(e); return true;}
        pp=&e->next;
    }
    return false;
}
