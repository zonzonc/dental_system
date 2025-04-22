#ifndef PATIENT_H
#define PATIENT_H
#include <stdbool.h>

typedef struct {
    char id_card[8];       /* e.g. "A123"    */
    char name[64];         /* UTF‑8 OK        */
    char birth_date[11];   /* "YYYY-MM-DD"    */
    char gender[8];        /* 男 / 女 / 其他   */
    char treatment_type[16]; /* "急診" 或一般   */
    int  doctor;
    int  shift;
    int  order;            /* 排隊序號         */
} Patient;

/* return <0 if a<b, 0 if equal, >0 if a>b  */
int  patient_compare(const Patient *a, const Patient *b);
bool patient_is_emergency(const Patient *p);

#endif /* PATIENT_H */
