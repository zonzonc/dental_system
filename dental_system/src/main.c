#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "heap.h"
#include "queue.h"
#include "avl.h"
#include "dictionary.h"

static void trim_newline(char *s){
    size_t len=strlen(s);
    if(len && s[len-1]=='\n') s[len-1]='\0';
}

int main(void)
{
    printf("系統啟動 (C 版)\n");

    MinHeap *waiting = heap_create(16);
    AVLTree *patient_query = avl_create();
    Dictionary *billing = dict_create(32);

    char cmd[64];
    while (1) {
        puts("\n=== 牙醫掛號系統 ===");
        puts("1) 病人掛號");
        puts("2) 查看最緊急病人");
        puts("3) 離開");
        printf("選擇: ");
        if (!fgets(cmd, sizeof cmd, stdin)) break;
        trim_newline(cmd);

        if (strcmp(cmd, "1") == 0) {
            Patient *p = calloc(1, sizeof *p);
            printf("健保卡號(A123): "); fgets(p->id_card, sizeof p->id_card, stdin); trim_newline(p->id_card);
            printf("姓名: "); fgets(p->name, sizeof p->name, stdin); trim_newline(p->name);
            printf("出生日期(YYYY-MM-DD): "); fgets(p->birth_date, sizeof p->birth_date, stdin); trim_newline(p->birth_date);
            printf("性別: "); fgets(p->gender, sizeof p->gender, stdin); trim_newline(p->gender);
            printf("看診類型(急診/一般): "); fgets(p->treatment_type, sizeof p->treatment_type, stdin); trim_newline(p->treatment_type);
            p->order = heap_size(waiting) + 1;
            heap_insert(waiting, p);
            avl_insert(patient_query, p);
            dict_put(billing, p->id_card, p);
            puts("掛號完成！");
        }
        else if (strcmp(cmd, "2") == 0) {
            Patient *p=NULL;
            if (heap_top(waiting, &p)) {
                printf("最緊急病人: %s %s (類型:%s, order:%d)\n", p->id_card, p->name, p->treatment_type, p->order);
            } else {
                puts("目前無病人。");
            }
        }
        else if (strcmp(cmd, "3") == 0) {
            break;
        }
        else {
            puts("無效指令。");
        }
    }

    /* TODO: free all patients properly */
    heap_destroy(waiting);
    avl_destroy(patient_query);
    dict_destroy(billing);

    puts("系統結束，再見！");
    return 0;
}
