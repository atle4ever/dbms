// -*- C++ -*-

#ifndef __PARSE_TREE_H__
#define __PARSE_TREE_H__

#include <vector>
#include <string>

enum ValueType {VT_INT, VT_FLOAT, VT_CHAR};


// Type info. of column
class ColType {
public:
    ColType(const ColType &rhs) : type(rhs.type), length(rhs.length) {}
    ColType(ValueType type, int length) : type(type), length(length) {}

    std::string to_string();

    ValueType type;
    int length;
};


// Type info. and name of column create in CREATE sql
class ColDef {
public:
    ColDef(std::string cName, ColType *cType) : cName(cName), cType(*cType) {}
    ~ColDef(){}

    std::string to_string();
    std::string cName;
    ColType cType;
};


class Sql {
public:
    enum SqlType {CREATE, INSERT};

    virtual ~Sql() {}

    virtual SqlType getType() = 0;
    virtual std::string to_string() = 0;
};


class SqlCreate : public Sql {
public:
    SqlCreate(const std::string &tableName, std::vector<ColDef> *colDefs)
        : tableName(tableName), colDefs(colDefs) {}
    virtual ~SqlCreate() {}

    virtual SqlType getType() { return CREATE; };
    virtual std::string to_string();

    std::string tableName;
    std::vector<ColDef> *colDefs;
};


class Value {
public:
    Value(char *str, ValueType type) : val(str), type(type) {}
    ~Value() {}

    std::string to_string();

    std::string val;
    ValueType type;
};


class SqlInsert : public Sql{
public:
    SqlInsert(const std::string &tableName, std::vector<Value> *values)
        : tableName(tableName), values(values) {}
    virtual ~SqlInsert() {
        std::vector<Value> :: iterator it;
        for(std::vector<Value>::iterator it = values->begin(); it != values->end(); it++){
        }
        this->values->clear();
    }

    SqlType getType() { return INSERT; };
    std::string to_string();

    std::string tableName;
    std::vector<Value> *values;
};

#endif // _PARSE_TREE_H_
