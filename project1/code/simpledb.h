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

/* Table interface */
// Add new student. It's attribute are given as parameter
void insertStudent(const int sid, const char sname[], const float gpa, const int age);

// Delete a row that have sid. If that record doesn't exist, print error msg.
void deleteStudent(const int sid);

void insertClass(const int cid, const char cname[]);
void deleteClass(const int sid);

void insertEnroll(const int sid, const int cid, const float grade);
void deleteEnroll(const int sid, const int cid);


/* Relational operator */
enum ComType {EQ, NEQ, GT, LT};
enum AggType {MAX, MIN, AVG};

// Select operation on Student table.
// It is same to 'select * from student where sid <cmp> <sid>'
void select(const ComType cmp, const int sid);

// Join operation on Student, Class, Enroll table.
// It is same to 'select s.sname, c.name from student as s, class as c, enroll as e where s.sid = e.sid and c.cid = e.sid and e.grade <cmd> <grade>'
void join(const ComType cmp, const float grade);

// Group operation on Student table.
// It is same to 'select age, <agg>(gpa) from student group by age'
void group(const AggType agg);
