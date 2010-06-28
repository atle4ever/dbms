#include "table.h"
#include <iostream>

int main() {
    Table table(12);

    table.insertRow();
    table.insertRow();
    table.write(0, 8, 4, (void*)"abc");
    table.write(1, 8, 4, (void*)"def");

    char buf[100];

    table.read(0, 8, 4, buf);
    std::cout << buf << std::endl;
    table.read(1, 8, 4, buf);
    std::cout << buf << std::endl;
    return 0;
}
