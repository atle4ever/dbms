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
// Comparison operators used in 'where' clause. =, <>, >, <.
enum CmpOp {EQ, NEQ, GT, LT};

// Aggregate functions
enum AggFun {MAX, MIN, AVG};

// Select operation on Student table.
// It is same to 'select * from student where sid <cmp> <sid>'
void select(const CmpOp cmp, const int sid);

// Join operation on Student, Class, Enroll table.
// It is same to 'select s.sname, c.name from student as s, class as c, enroll as e where s.sid = e.sid and c.cid = e.sid and e.grade <cmd> <grade>'
void join(const CmpOp cmp, const float grade);

// Group operation on Student table.
// It is same to 'select age, <agg>(gpa) from student group by age'
void group(const AggFun agg);
