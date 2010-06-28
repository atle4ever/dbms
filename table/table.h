#include "const.h"

typedef int Rid;

class Table {
private:
    static const int ROWS_PER_PAGE;
    int len;
    int nRid;
    char* rows[NUM_ROWS];

    Table();

    char* getRow(Rid rid);
    
public:
    Table(int len);
    Rid insertRow();
    void deleteRow(Rid rid);
    void read(Rid rid, int pos, int size, void* buf);
    void write(Rid rid, int pos, int size, void* buf);
};

