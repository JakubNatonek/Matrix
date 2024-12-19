#include "src/matrix.h"

int main(int argc, char* argv[])
{
    matrix m;
    m.allocate(5);
    m.checkerboard();
    m += -20;
    m(4.75);
    std::cout << m << std::endl;
    
    return 0;
}
