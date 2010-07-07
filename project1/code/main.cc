#include "simpledb.h"

int main() {
    insertStudent(1, "John", 3.4, 20);
    insertStudent(2, "Sujan", 3.9, 22);
    insertStudent(3, "Tomas", 2.9, 21);

    insertClass(1, "420.123");
    insertClass(2, "420.456");
    insertClass(3, "420.789");
    insertClass(4, "420.451");

    insertEnroll(1, 1, 3.4);
    insertEnroll(2, 1, 4.0);
    insertEnroll(3, 1, 2.0);
    insertEnroll(2, 2, 2.3);
    insertEnroll(2, 4, 3.2);
    insertEnroll(3, 3, 4.2);

    deleteStudent(1);
    deleteEnroll(1, 1);

    select(EQ, 2);
    select(LT, 3);

    join(EQ, 2.0);
    join(NEQ, 2.0);

    group(MIN);
    group(AVG);

    return 0;
}
