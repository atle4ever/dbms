#include "QueryProcessor.h"

int main() {
    QueryProcessor *qp = new QueryProcessor();

    // Create tables
    SqlCreate* sql = new SqlCreate("Student");
    sql->addColDef(ColDef("sid", ColType(ColType::INT_TYPE, 0)));
    sql->addColDef(ColDef("sname", ColType(ColType::CHAR_TYPE, 30)));
    sql->addColDef(ColDef("gpa", ColType(ColType::FLOAT_TYPE, 0)));
    sql->addColDef(ColDef("age", ColType(ColType::INT_TYPE, 0)));
    qp->process(sql);
    delete sql;

    sql = new SqlCreate("Class");
    sql->addColDef(ColDef("cid", ColType(ColType::INT_TYPE, 0)));
    sql->addColDef(ColDef("cname", ColType(ColType::CHAR_TYPE, 30)));
    qp->process(sql);
    delete sql;

    sql = new SqlCreate("Enroll");
    sql->addColDef(ColDef("sid", ColType(ColType::INT_TYPE, 0)));
    sql->addColDef(ColDef("cid", ColType(ColType::INT_TYPE, 0)));
    sql->addColDef(ColDef("grade", ColType(ColType::FLOAT_TYPE, 0)));
    qp->process(sql);
    delete sql;

    // Insert records into Student
    SqlInsert* sql2 = new SqlInsert("Student");
    sql2->addValue(new int(1));
    sql2->addValue((void*)"John");
    sql2->addValue(new float(3.4));
    sql2->addValue(new int(20));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Student");
    sql2->addValue(new int(2));
    sql2->addValue((void*)"Sujan");
    sql2->addValue(new float(3.9));
    sql2->addValue(new int(22));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Student");
    sql2->addValue(new int(3));
    sql2->addValue((void*)"Tomas");
    sql2->addValue(new float(2.9));
    sql2->addValue(new int(21));
    qp->process(sql2);
    delete sql2;

    // Insert records into Class
    sql2 = new SqlInsert("Class");
    sql2->addValue(new int(1));
    sql2->addValue((void*)"420.123");
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Class");
    sql2->addValue(new int(2));
    sql2->addValue((void*)"420.456");
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Class");
    sql2->addValue(new int(3));
    sql2->addValue((void*)"420.789");
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Class");
    sql2->addValue(new int(4));
    sql2->addValue((void*)"420.451");
    qp->process(sql2);
    delete sql2;

    // Insert records into Enroll
    sql2 = new SqlInsert("Enroll");
    sql2->addValue(new int(1));
    sql2->addValue(new int(1));
    sql2->addValue(new float(3.4));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Enroll");
    sql2->addValue(new int(2));
    sql2->addValue(new int(1));
    sql2->addValue(new float(4.0));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Enroll");
    sql2->addValue(new int(3));
    sql2->addValue(new int(1));
    sql2->addValue(new float(2.0));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Enroll");
    sql2->addValue(new int(2));
    sql2->addValue(new int(2));
    sql2->addValue(new float(2.3));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Enroll");
    sql2->addValue(new int(2));
    sql2->addValue(new int(4));
    sql2->addValue(new float(3.2));
    qp->process(sql2);
    delete sql2;

    sql2 = new SqlInsert("Enroll");
    sql2->addValue(new int(3));
    sql2->addValue(new int(3));
    sql2->addValue(new float(4.2));
    qp->process(sql2);
    delete sql2;

    return 0;
}
