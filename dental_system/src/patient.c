#include "patient.h"
#include <string.h>

bool patient_is_emergency(const Patient *p)
{
    return strcmp(p->treatment_type, "急診") == 0;
}

int patient_compare(const Patient *a, const Patient *b)
{
    if (patient_is_emergency(a) && !patient_is_emergency(b)) return -1;
    if (!patient_is_emergency(a) && patient_is_emergency(b)) return  1;
    return a->order - b->order;
}
