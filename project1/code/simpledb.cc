#include "simpledb.h"

void insertStudent(const int sid, const char sname[], const float gpa, const int age) {}

void deleteStudent(const int sid) {}

void insertClass(const int cid, const char cname[]) {}

void deleteClass(const int sid) {}

void insertEnroll(const int sid, const int cid, const float grade) {}

void deleteEnroll(const int sid, const int cid) {}

void select(const ComType cmp, const int sid) {}

void join(const ComType cmp, const float grade) {}

void group(const AggType agg) {}
