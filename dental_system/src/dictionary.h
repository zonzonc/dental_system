#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include "patient.h"

typedef struct DictEntry {
    char key[8];
    Patient *val;
    struct DictEntry *next;
} DictEntry;

typedef struct {
    DictEntry **table;
    int capacity;
} Dictionary;

Dictionary *dict_create(int cap);
void dict_destroy(Dictionary *d);
bool dict_put(Dictionary *d, const char *key, Patient *val);
Patient *dict_get(const Dictionary *d, const char *key);
bool dict_remove(Dictionary *d, const char *key);

#endif /* DICTIONARY_H */
