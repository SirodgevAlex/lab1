#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "RingInfo.h"

void MainMenu() {
    wprintf(L"What do you want to do?\n");
    wprintf(L"1 - read of string\n");
    wprintf(L"2 - printf of string\n");
    wprintf(L"3 - string operations\n");
    wprintf(L"4 - testing of functions\n");
    wprintf(L"5 - stop and exit\n");
}

void StringMenu() {
    wprintf(L"What would you like to do?\n");
    wprintf(L"1 - concatecation\n");
    wprintf(L"2 - receive a substring\n");
    wprintf(L"3 - sort (case sensetive)\n");
    wprintf(L"4 - sort (case non - sensetive)\n");
    wprintf(L"5 - find a substring (case sensetive)\n");
    wprintf(L"6 - find a substring (case non - sensetive)\n");
    wprintf(L"7 - back to main menu\n");
}

void ConcatecationMenu() {
    wprintf(L"how do you want to unite strings?\n");
    wprintf(L"1 - add new string to old\n");
    wprintf(L"2 - add all string to new\n");
}

void TestingMenu() {
    wprintf(L"Which function want you to test?\n");
    wprintf(L"1 - concatecation first (new to old)\n");
    wprintf(L"2 - concatecation second (old to new)\n");
    wprintf(L"3 - receive a substring\n");
    wprintf(L"4 - sort (case sensetive)\n");
    wprintf(L"5 - sort (case non - sensetive)\n");
    wprintf(L"6 - find (case sensetive)\n");
    wprintf(L"7 - find (case non - sensetive)\n");
    wprintf(L"8 - back to main menu\n");
}

void *Read(String *Str) {

    setlocale(LC_ALL, "");
    wprintf(L"Input please\n");
    wchar_t *string1;
    string1 = (wchar_t *) malloc(1000 * sizeof(wchar_t));
    wscanf(L"%ls", string1);
    Str->str = string1;
    Str->length = wcslen(string1);
    return Str;
}

void Print(String *Str) {
    wprintf(L"%ls\n", (wchar_t *) Str->str);
}

