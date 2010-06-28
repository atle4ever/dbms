#include <cstring>
#include <iostream>

#include "table.h"

char* Table::getRow(Rid rid) {
    char *row = rows[rid];
    if(row[len] == 1) {
	std::cerr << "Error: Invalid rid[" << rid << "]" << std::endl;
    } else {
	return row;
    }
}
	
Table::Table(int len) {
    this->len = len;
    nRid = 0;
}

Rid Table::insertRow() {
    rows[nRid] = new char[len+1];
    rows[nRid][len] = 0;
    nRid++;
}

void Table::deleteRow(Rid rid) {
    rows[rid][len] = 1;
}

void Table::read(Rid rid, int pos, int size, void* buf) {
    char* row = getRow(rid);

    memcpy(buf, row + pos, size);
}

void Table::write(Rid rid, int pos, int size, void* buf) {
    char* row = getRow(rid);

    memcpy(row + pos, buf, size);
}
