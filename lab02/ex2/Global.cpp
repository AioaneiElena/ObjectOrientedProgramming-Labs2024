#include "Global.h"
#include "Student.h"
#include <stdio.h>

void CmpMate(Student s1, Student s2) {
    if (s1.getMate() < s2.getMate())
        printf("%s are nota mai mica la matematica (%.2f) decat %s (%.2f).\n", s1.getNume(), s1.getMate(), s2.getNume(), s2.getMate());
    else if (s1.getMate() > s2.getMate())
        printf("%s are nota mai mica la matematica (%.2f) decat %s (%.2f).\n", s2.getNume(), s2.getMate(), s1.getNume(), s1.getMate());
    else
        printf("Cei doi studenti au aceeasi nota la matematica.\n");

    printf("\n");
}

void CmpIst(Student s1, Student s2) {
    if (s1.getIstorie() < s2.getIstorie())
        printf("%s are nota mai mica la istorie (%.2f) decat %s (%.2f).\n", s1.getNume(), s1.getIstorie(), s2.getNume(), s2.getIstorie());
    else if (s1.getIstorie() > s2.getIstorie())
        printf(
            "%s are nota mai mica la istorie (%.2f) decat %s (%.2f).\n", s2.getNume(), s2.getIstorie(), s1.getNume(), s1.getIstorie());
    else
        printf("Cei doi studenti au aceeasi nota la istorie.\n");

    printf("\n");
}

void CmpEng(Student s1, Student s2) {
    if (s1.getEngleza() < s2.getEngleza())
        printf("%s are nota mai mica la engleza (%.2f) decat %s (%.2f).\n", s1.getNume(), s1.getEngleza(), s2.getNume(), s2.getEngleza());
    else if (s1.getEngleza() > s2.getEngleza())
        printf("%s are nota mai mica la engleza (%.2f) decat %s (%.2f).\n", s2.getNume(), s2.getEngleza(), s1.getNume(), s1.getEngleza());
    else
        printf("Cei doi studenti au aceeasi nota la engleza.\n");

    printf("\n");
}

void CmpAverage(Student s1, Student s2) {
    if (s1.getMedie() < s2.getMedie())
        printf("%s are media (%.2f) mai mica decat %s (%.2f).\n", s1.getNume(), s1.getMedie(), s2.getNume(), s2.getMedie());
    else if (s1.getMedie() > s2.getMedie())
        printf("%s are media (%.2f) mai mica decat %s (%.2f).\n", s2.getNume(), s2.getMedie(), s1.getNume(), s1.getMedie());
    else
        printf("Cei doi studenti au aceeasi medie.\n");

    printf("\n");
}

void CmpName(Student s1, Student s2) {
    if (strcmp(s1.getNume(), s2.getNume()) < 0)
        printf("%s este inaintea lui %s la catalog.\n", s1.getNume(), s2.getNume());
    else if (strcmp(s1.getNume(), s2.getNume()) > 0)
        printf("%s este inaintea lui %s la catalog.\n", s2.getNume(), s1.getNume());
    else
        printf("Cei doi studenti au acelasi nume.\n");

    printf("\n");
}