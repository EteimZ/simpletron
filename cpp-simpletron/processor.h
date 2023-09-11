#ifndef CPU
	#define CPU

#include <iostream>

using namespace std;

namespace simpletron{
    enum Operands{
        READ = 10,          // Read a word from the terminal into a specific location in memory
        WRITE = 11,         // Write a word from a specific location in memory to the terminal

        LOAD = 20,          // Load a word from a specific location in memory into the accumulator
        STORE = 21,         // Store a word from the accumulator into a specific location in memory

        ADD = 30,           // Add a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator
        SUBSTRACT = 31,     // Substract a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator
        DIVIDE = 32,        // Divide a word from a specific location in memory into the word in the accumalator and then leaves the result in the accumulator
        MULTIPLY = 33,      // Multiply a word from a specific location in memory to the word in the accumalator and then leaves it in the accumulator

        BRANCH = 40 ,       // Branch to a specific location in memory
        BRANCHNEG = 41,     // Branch to a specific location in memory if the accumulator is negative
        BRANCHZERO = 42,    // Branch to a specific location in memory if the accumulator is zero
        HALT = 43,          // Halt the program
    };

    #define SIZE 100 // memory size

    class Processor{
        private:
            int memory[SIZE]; // memory
            int accumulator; // The accumulator
            int instructionCounter;  // The memory address of the current instruction
            int instructionRegister; // The current instruction to be performed
            int operationCode; // The operation code currently being perfromed
            int operand; // The memory address the current variable operates
        public:
            Processor();
            void load();
            void run();
    };

    void intro();
}

#endif