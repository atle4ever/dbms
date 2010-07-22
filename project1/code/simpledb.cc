#include "simpledb.h"

/* Hard-structured record */
struct Student {
    int sid;
    char sname[30];
    float gpa;
    int age;
};

struct Class {
    int cid;
    char cname[30];
};

struct Enroll {
    int sid;
    int cid;
    float grade;
};

/* Hard-structured table */
struct Student studentTable[100];
struct Class classTable[100];
struct Enroll enrollTable[100];

void insertStudent(const int sid, const char sname[], const float gpa, const int age) {
    // TODO
}

void deleteStudent(const int sid) {
    // TODO
}

void insertClass(const int cid, const char cname[]) {
    // TODO
}

void deleteClass(const int sid) {
    // TODO
}

void insertEnroll(const int sid, const int cid, const float grade) {
    // TODO
}

void deleteEnroll(const int sid, const int cid) {
    // TODO
}

void select(const CmpOp cmp, const int sid) {
    // TODO
}

void join(const CmpOp cmp, const float grade) {
    // TODO
}

void group(const AggFun agg) {
    // TODO
}
