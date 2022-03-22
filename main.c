#include <stdio.h>
#include "InputOutput.h"
#include <wchar.h>
#include <locale.h>
#include <malloc.h>
#include "Testing.h"

int main() {
    setlocale(LC_ALL, "");
    struct RingInfo *ringInfo;
    ringInfo = malloc(sizeof(struct RingInfo));
    ringInfo->ConcatFirst = ConcatFirst;
    ringInfo->ConcatSecond = ConcatSecond;
    ringInfo->SubString = SubString;
    ringInfo->SensSort = SensSort;
    ringInfo->NonSensSort = NonSensSort;
    ringInfo->SensFind = SensFind;
    ringInfo->NonSensFind = NonSensFind;
    String *Str = NULL;
    Str = malloc(sizeof(String));
    int MainPoint = 0;
    int SubPoint = 0;
    int SubSubPoint = 0;
    while (MainPoint != 5) {
        MainMenu();
        wscanf(L"%d", &MainPoint);
        if (MainPoint == 1) {
            Str = Read(Str);
        } else if (MainPoint == 2) {
            Print(Str);
        } else if (MainPoint == 3) {
            StringMenu();
            wscanf(L"%d", &SubPoint);
            if (SubPoint == 1) {
                ConcatecationMenu();
                wscanf(L"%d", &SubSubPoint);
                if (SubSubPoint == 1) {
                    Str = ringInfo->ConcatFirst(Str);
                } else if (SubSubPoint == 2) {
                    Str = ringInfo->ConcatSecond(Str);
                }
            } else if (SubPoint == 2) {
                Str = ringInfo->SubString(Str);
            } else if (SubPoint == 3) {
                Str = ringInfo->SensSort(Str);
            } else if (SubPoint == 4) {
                Str = ringInfo->NonSensSort(Str);
            } else if (SubPoint == 5) {
                Str = ringInfo->SensFind(Str);
            } else if (SubPoint == 6) {
                Str = ringInfo->NonSensFind(Str);
            }
        } else if (MainPoint == 4) {
            TestingMenu();
            wscanf(L"%d", &SubPoint);
            if (SubPoint == 1) {
                ConcatFirstTest(Str);
            } else if (SubPoint == 2) {
                ConcatSecondTest(Str);
            } else if (SubPoint == 3) {
                SubStringTest(Str);
            } else if (SubPoint == 4) {
                SensSortTest(Str);
            } else if (SubPoint == 5) {
                NonSensSortTest(Str);
            } else if (SubPoint == 6) {
                SensFindTest(Str);
            } else if (SubPoint == 7) {
                NonSensFindTest(Str);
            }
        }
    }
    FreeAll(Str, ringInfo);
}
