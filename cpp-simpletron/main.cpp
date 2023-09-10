include "cpu.h"

int main{
    simpletron::CPU cpu;

    cpu.load();
    cpu.run();
    
    return 0;
}