#include "processor.h"

int main(int length, char** args){
    simpletron::intro();

    simpletron::Processor processor;
    processor.load();
    processor.run();
    
    return 0;
}