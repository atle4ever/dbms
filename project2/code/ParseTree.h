#ifndef __PARSE_TREE_H__
#define __PARSE_TREE_H__

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <algorithm>

using namespace std;

enum SqlType { SQL_CREATE, SQL_INSERT };
enum ValueType { V_INT, V_FLOAT, V_CHAR };

class Sql {
public:
    virtual SqlType getType() = 0;
};

/*************************
 * Create Query
 *************************/
class ColType {
public:
    ColType(ValueType type, int length) : type(type), length(length) {}

    ValueType type;
    int length;
};

class ColDef {
public:
    ColDef(string cName, ColType cType) : cName(cName), cType(cType) {}

    string cName;
    ColType cType;
};

class SqlCreate : public Sql {
public:
    SqlCreate(string tableName, vector<ColDef> colDefs): tableName(tableName), colDefs(colDefs) {}

    SqlType getType() { return SQL_CREATE; };

    string tableName;
    vector<ColDef> colDefs;
};


/*************************
 * Insert Query
 *************************/
class Value {
public:
    Value() {}
    virtual ~Value(){}

    virtual void* getValue() = 0;
    virtual ValueType getValueType() = 0;
};

class IntValue : public Value {
public:
    IntValue(int n) { value = new int(n); }
    ~IntValue() { delete value; }

    virtual void* getValue() { return value; }
    virtual ValueType getValueType() { return V_INT; }

    int* value;
};

class FloatValue : public Value {
public:
    FloatValue(float f) { value = new float(f); }
    ~FloatValue() { delete value; }

    virtual void* getValue() { return value; }
    virtual ValueType getValueType() { return V_FLOAT; }

    float* value;
};

class CharValue : public Value {
public:
    CharValue(char* c) {
        assert(strlen(c) < 4000);

        value = new char[strlen(c) + 1];
        strcpy(value, c);
    }
    ~CharValue(){
        delete [] value;
    }

    virtual void* getValue() { return value; }
    virtual ValueType getValueType() { return V_CHAR; }

    char* value;
};

class SqlInsert : public Sql{
public:
    SqlInsert(string tableName, vector<Value *> values): tableName(tableName), values(values) {}

    SqlType getType() { return SQL_INSERT; };

    string tableName;
    vector<Value *> values;
};

#endif // __PARSE_TREE_H__
