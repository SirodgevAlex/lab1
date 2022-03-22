#include "RingInfo.h"
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>


void FreeAll(String *Str, struct RingInfo *ringInfo) {
    free(Str->str);
    free(Str);
    free(ringInfo);
}

struct RingInfo *
CreateRingInfo(void *(*ConcatFirst)(String *), void *(*ConcatSecond)(String *), void *(*SubString)(String *),
               void *(*SensSort)(String *), void *(*NonSensSort)(String *), void *(*SensFind)(String *),
               void *(*NonSensFind)(String *)) {
    struct RingInfo *RI = malloc(sizeof(struct RingInfo));
    RI->ConcatFirst = ConcatFirst;
    RI->ConcatSecond = ConcatSecond;
    RI->SubString = SubString;
    RI->SensSort = SensSort;
    RI->NonSensSort = NonSensSort;
    RI->SensFind = SensFind;
    RI->NonSensFind = NonSensFind;
    return RI;
}

void *ConcatFirst(String *Str) {
    wchar_t *OldString;
    OldString = Str->str;
    setlocale(LC_ALL, "");
    wprintf(L"Input please\n");
    wchar_t *NewString;
    NewString = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wscanf(L"%ls", NewString);
    wchar_t *ConcatString;
    ConcatString = (wchar_t *) malloc((wcslen(NewString) + Str->length) * sizeof(wchar_t));
    wmemcpy(ConcatString, OldString, Str->length);
    *(wchar_t *) (ConcatString + Str->length) = L'\0';
    wmemcpy(ConcatString + Str->length, NewString, wcslen(NewString));
    *(wchar_t *) (ConcatString + (wcslen(NewString) + Str->length)) = L'\0';
    int n, m;
    n = wcslen(OldString);
    m = wcslen(NewString);
    Str->str = (void *) ConcatString;
    Str->length = n + m;
    return Str;
}

void *ConcatSecond(String *Str) {
    wchar_t *OldString;
    OldString = (wchar_t *) Str->str;
    setlocale(LC_ALL, "");
    wprintf(L"Input please\n");
    wchar_t *NewString;
    NewString = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wscanf(L"%ls", NewString);
    wchar_t *ConcatString;
    ConcatString = (wchar_t *) malloc((wcslen(NewString) + Str->length) * sizeof(wchar_t));
    wcsncpy(ConcatString, NewString, wcslen(NewString));
    *(wchar_t *) (ConcatString + wcslen(NewString)) = L'\0';
    wcsncpy(ConcatString + wcslen(NewString), OldString, Str->length);
    *(wchar_t *) (ConcatString + (wcslen(NewString) + Str->length)) = L'\0';
    int n, m;
    n = wcslen(OldString);
    m = wcslen(NewString);
    Str->str = (void *) ConcatString;
    Str->length = n + m;
    return Str;
}

void *SubString(String *Str) {
    wchar_t *String;
    String = (void *) Str->str;
    setlocale(LC_ALL, "");
    wprintf(L"Input first and last positions of substring\n");
    int l, r;
    wscanf(L"%d", &l);
    wscanf(L"%d", &r);
    wchar_t *SubString;
    SubString = (wchar_t *) malloc((r - l + 1) * sizeof(wchar_t));
    wmemcpy(SubString, String + l, (r - l + 1));
    String = (wchar_t *) malloc((r - l + 1) * sizeof(wchar_t));
    wmemcpy(String, SubString, (r - l + 1));
    Str->str = String;
    Str->length = r - l + 1;
    return Str;
}

void *SensSort(String *Str) {
    wchar_t *string;
    string = (wchar_t *) Str->str;
    setlocale(LC_ALL, "");
    double factor = 1.2473309; // фактор уменьшения
    int step = (Str->length) - 1; // шаг сортировки
    //Последняя итерация цикла, когда step == 1 эквивалентна одному проходу сортировки пузырьком.
    while (step >= 1) {
        for (int i = 0; i + step < Str->length; i++) {
            if (string[i] > string[i + step]) {
                wchar_t c = string[i];
                string[i] = string[i + step];
                string[i + step] = c;
            }
        }
        step /= factor;
    }
    Str->str = string;
    return Str;
}

void *NonSensSort(String *Str) {
    setlocale(LC_ALL, "");
    wchar_t *string;
    string = (wchar_t *) Str->str;
    double factor = 1.2473309; // фактор уменьшения
    int step = (Str->length) - 1; // шаг сортировки
    //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1) {
        for (int i = 0; i + step < Str->length; i++) {
            if (towlower(string[i]) > towlower(string[i + step])) {
                wchar_t c = string[i];
                string[i] = string[i + step];
                string[i + step] = c;
            }
        }
        step /= factor;
    }
    Str->str = string;
    return Str;
}

void *SensFind(String *Str) {
    setlocale(LC_ALL, "");
    wchar_t *string;
    string = (wchar_t *) Str->str;
    wchar_t *SubStr;
    SubStr = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wprintf(L"Input string you want to find\n");
    wscanf(L"%ls", SubStr);
    int dp[wcslen(SubStr)];
    int i;
    int flag = -1;
    if (string[0] == SubStr[0]) {
        dp[0] = 1;
        flag = 0;
    } else {
        dp[0] = 0;
    }
    for (i = 1; i < Str->length; i++) {
        dp[i] = 0;
        if (dp[i - 1] != wcslen(SubStr)) {
            if (string[i] == SubStr[dp[i - 1]]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        if ((dp[i] == wcslen(SubStr)) && (flag == -1)) {
            flag = i;
        }
    }
    if (flag > -1) {
        Str->str = SubStr;
        Str->length = wcslen(SubStr);
        wprintf(L"substring successfully found\n");
    } else {
        Str->str = NULL;
        Str->length = 0;
        wprintf(L"substring not found\n");
    }
    return Str;
}

void *NonSensFind(String *Str) {
    setlocale(LC_ALL, "");
    wchar_t *string;
    string = (wchar_t *) Str->str;
    wchar_t *SubStr;
    SubStr = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wprintf(L"Input string you want to find\n");
    wscanf(L"%ls", SubStr);
    int dp[wcslen(SubStr)];
    int i;
    int flag = -1;
    if (towlower(string[0]) == towlower(SubStr[0])) {
        dp[0] = 1;
    } else {
        dp[0] = 0;
    }
    if (wcslen(SubStr) == 1) {
        flag = 0;
    }
    for (i = 1; i < Str->length; i++) {
        dp[i] = 0;
        if (dp[i - 1] != wcslen(SubStr)) {
            if (towlower(string[i]) == towlower(SubStr[dp[i - 1]])) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        if ((dp[i] == wcslen(SubStr)) && (flag == -1)) {
            flag = i;
        }
    }
    if (flag > -1) {
        wchar_t *ResString;
        ResString = (wchar_t *) malloc((wcslen(SubStr) + 1) * sizeof(wchar_t));
        wmemcpy(ResString, string + flag - wcslen(SubStr) + 1, wcslen(SubStr));
        ResString[wcslen(SubStr)] = L'\0';
        Str->str = ResString;
        Str->length = wcslen(SubStr);
        wprintf(L"substring successfully found\n");
    } else {
        Str->str = NULL;
        Str->length = 0;
        wprintf(L"substring not found\n");
    }
    return Str;
}
