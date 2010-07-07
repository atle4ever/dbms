#include <string>
#include <vector>

using namespace std;

class ColType {
public:
    enum Type {INT_TYPE, FLOAT_TYPE, CHAR_TYPE};

private:
    Type type;
    int n;

public:
    ColType(Type type, int n) : type(type), n(n) {;}
};

class ColDef {
private:
    string cName;
    ColType type;

public:
    ColDef(string cName, ColType type) : cName(cName), type(type){;}
};

class Value {
private:
    void* value;

public:
    Value(void* value) : value(value) {;}
};

class Sql {
public:
    enum SqlType {CREATE, INSERT};

    virtual SqlType getType() = 0;
};

class SqlCreate : public Sql {
private:
    string tableName;
    vector<ColDef> colDefs;

public:
    SqlCreate(string tableName) : tableName(tableName) {;}

    SqlType getType() { return CREATE; };

    void addColDef(ColDef cd) { this->colDefs.push_back(cd); }
};

class SqlInsert : public Sql{
private:
    string tableName;
    vector<Value> values;

public:
    SqlInsert(string tableName) : tableName(tableName) {;}

    SqlType getType() { return INSERT; };

    void addValue(Value v) { this->values.push_back(v); }
};
