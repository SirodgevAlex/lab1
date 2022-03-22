#include <wchar.h>
#include "Testing.h"
#include <locale.h>
#include <stdlib.h>
#include <wctype.h>

void ConcatFirstTest(String *Str) {
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
    ConcatString[Str->length] = L'\0';
    wmemcpy(ConcatString + Str->length, NewString, wcslen(NewString));
    ConcatString[wcslen(NewString) + Str->length] = L'\0';
    wchar_t *ConcatStringNew;
    ConcatStringNew = (wchar_t *) malloc((wcslen(NewString) + Str->length) * sizeof(wchar_t));
    int i;
    wprintf(L"answer ConcatFirst function\n");
    wprintf(L"%ls\n", ConcatString);
    wprintf(L"elementary implementation\n");
    for (i = 0; i < (wcslen(NewString) + Str->length); i++) {
        if (i < Str->length) {
            ConcatStringNew[i] = OldString[i];
        } else {
            ConcatStringNew[i] = NewString[i - Str->length];
        }
        if (i == wcslen(NewString) + Str->length - 1) {
            ConcatStringNew[wcslen(NewString) + Str->length] = L'\0';
        }
        wprintf(L"%ls\n", ConcatStringNew);
    }
}

void ConcatSecondTest(String *Str) {
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
    wchar_t *ConcatStringNew;
    ConcatStringNew = (wchar_t *) malloc((wcslen(NewString) + Str->length) * sizeof(wchar_t));
    int i;
    wprintf(L"answer ConcatSecond function\n");
    wprintf(L"%ls\n", ConcatString);
    wprintf(L"elementary implementation\n");
    for (i = 0; i < (wcslen(NewString) + Str->length); i++) {
        if (i < wcslen(NewString)) {
            ConcatStringNew[i] = NewString[i];
        } else {
            ConcatStringNew[i] = OldString[i - wcslen(NewString)];
        }
        if (i == wcslen(NewString) + Str->length - 1) {
            ConcatStringNew[wcslen(NewString) + Str->length] = L'\0';
        }
        wprintf(L"%ls\n", ConcatStringNew);
    }
}

void SubStringTest(String *Str) {
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
    wprintf(L"answer SubString function\n");
    wprintf(L"%ls\n", SubString);
    wprintf(L"elementary implementation\n");
    int i;
    for (i = 0; i < wcslen(String); i++) {
        if ((i >= l) && (i <= r)) {
            wprintf(L"%lc", String[i]);
        }
    }
    wprintf(L"\n");
}

void SensSortTest(String *Str) {
    wchar_t *string;
    string = (wchar_t *) Str->str;
    setlocale(LC_ALL, "");
    double factor = 1.2473309; // фактор уменьшения
    int step = (Str->length) - 1; // шаг сортировки
    //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
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
    wprintf(L"answer SensSort function\n");
    wprintf(L"%ls\n", string);
    wprintf(L"elementary check\n");
    int i;
    for (i = 0; i < Str->length - 1; i++) {
        wprintf(L"%ld %ld ", i, i + 1);
        wprintf(L"%lc ", string[i]);
        if (string[i] > string[i + 1]) {
            wprintf(L"> %lc", string[i + 1]);
        } else if (string[i] < string[i + 1]) {
            wprintf(L"< %lc", string[i + 1]);
        } else {
            wprintf(L"= %lc", string[i + 1]);
        }
        wprintf(L"\n");
    }
}

void NonSensSortTest(String *Str) {
    setlocale(LC_ALL, "");
    wchar_t *string;
    string = (wchar_t *) Str->str;
    wchar_t c;
    c = string[0];
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
    wprintf(L"answer NonSensSort function\n");
    wprintf(L"%ls\n", string);
    wprintf(L"elementary check\n");
    int i;
    for (i = 0; i < Str->length - 1; i++) {
        wprintf(L"%ld %ld ", i, i + 1);
        wprintf(L"%lc ", string[i]);
        if (towlower(string[i]) > towlower(string[i + 1])) {
            wprintf(L"> %lc", string[i + 1]);
        } else if (towlower(string[i]) < towlower(string[i + 1])) {
            wprintf(L"< %lc", string[i + 1]);
        } else {
            wprintf(L"= %lc", string[i + 1]);
        }
        wprintf(L"\n");
    }
}

void SensFindTest(String *Str) {
    setlocale(LC_ALL, "");
    wchar_t *string;
    string = (wchar_t *) Str->str;
    wchar_t *SubStr;
    SubStr = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wprintf(L"Input string you want to find\n");
    wscanf(L"%ls", SubStr);
    wprintf(L"%ls\n", string);

    int dp[wcslen(SubStr)];
    int i;
    int flag = -1;
    if (string[0] == SubStr[0]) {
        dp[0] = 1;
    } else {
        dp[0] = 0;
    }
    if (wcslen(SubStr) == 1) {
        flag = 0;
    }
    wprintf(L"0");
    for (i = 1; i < Str->length; i++) {
        wprintf(L"%d", i);
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
        wprintf(L"\nsubstring successfully found\n");
        wprintf(L"%ls\n", SubStr);
        wprintf(L"look at %d left position and %d right position of main string\n", flag - wcslen(SubStr) + 1, flag);
    } else {
        wprintf(L"\nsubstring not found\n");
    }
}

void NonSensFindTest(String *Str) {
    setlocale(LC_ALL, "");
    wchar_t *string;
    string = (wchar_t *) Str->str;
    wchar_t *SubStr;
    SubStr = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wprintf(L"Input string you want to find\n");
    wscanf(L"%ls", SubStr);
    wprintf(L"%ls\n", string);
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
    wprintf(L"0");
    for (i = 1; i < Str->length; i++) {
        wprintf(L"%d", i);
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
        wprintf(L"\nsubstring successfully found\n");
        wprintf(L"%ls\n", ResString);
        wprintf(L"look at %d (left) position and %d (right) position of main string\n", flag - wcslen(SubStr) + 1, flag);
    } else {
        Str->str = NULL;
        Str->length = 0;
        wprintf(L"\nsubstring not found\n");
    }
}