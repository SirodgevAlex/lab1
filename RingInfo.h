#include <stdio.h>
#include <wchar.h>
#pragma once

typedef struct String {
    void *str;
    int length;
    struct RingInfo *ringInfo;
} String;

struct RingInfo {
    void *(*ConcatFirst)(String *);

    void *(*ConcatSecond)(String *);

    void *(*SubString)(String *);

    void *(*SensSort)(String *);

    void *(*NonSensSort)(String *);

    void *(*SensFind)(String *);

    void *(*NonSensFind)(String *);
};

void FreeAll(String *, struct RingInfo*);

struct RingInfo *
CreateRingInfo(void *(*ConcatFirst)(String *), void *(*ConcatSecond)(String *), void *(*SubString)(String *),
               void *(*SensSort)(String *), void *(*NonSensSort)(String *), void *(*SensFind)(String *), void *(*NonSensFind)(String *));

void *ConcatFirst(String *);

void *ConcatSecond(String *);

void *SubString(String *);

void *SensSort(String *);

void *NonSensSort(String *);

void *SensFind(String *);

void *NonSensFind(String *);
