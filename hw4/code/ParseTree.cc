#include "ParseTree.h"

#include <sstream>
#include <cassert>

using namespace std;

string ColType::to_string() {
    switch(type) {
    case VT_INT:
        return "int";

    case VT_FLOAT:
        return "float";

    case VT_CHAR:
        {
            stringstream ss;
            ss << "char(";
            ss << length;
            ss << ")";

            return ss.str();
        }
    }

    assert(false && "Invalid ValueType");
}

string ColDef::to_string() {
    stringstream ss;

    ss << cName << " " << cType.to_string();

    return ss.str();
}

string SqlCreate::to_string() {
    stringstream ss;

    ss << "CREATE " << tableName << '\n';
    for(vector<ColDef>::iterator it = colDefs->begin(), end = colDefs->end(); it != end; ++it) {
        ss << it->to_string() << '\n';
    }

    return ss.str();
}

string Value::to_string() {
    stringstream ss;

    ss << val;

    switch(type) {
    case VT_INT:
        ss << "(i)";
        break;

    case VT_FLOAT:
        ss << "(f)";
        break;

    case VT_CHAR:
        ss << "(c)";
        break;
    }

    return ss.str();
}

string SqlInsert::to_string() {
    stringstream ss;

    ss << "INSERT " << tableName << '\n';

    for(vector<Value>::iterator it = values->begin(), end = values->end(); it != end; ++it) {
        ss << it->to_string() << '\n';
    }

    return ss.str();
}
