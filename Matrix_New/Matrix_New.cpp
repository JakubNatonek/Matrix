#include "src/matrix.h"

int main(int argc, char* argv[])
{
    matrix m;
    m.allocate(3);
    m.randomize(10);
    std::cout << m << std::endl;
    
    return 0;
}
