#ifndef SIMPLETRON_H
#define SIMPLETRON_H

// Operations

#define READ 10  // Read a word from the terminal into a specific location in memory
#define WRITE 11 // Write a word from a specific location in memory to the terminal

#define LOAD 20  // Load a word from a specific location in memory into the accumulator
#define STORE 21 // Store a word from the accumulator into a specific location in memory

#define ADD 30 // Add a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator
#define SUBSTRACT 31 // Substract a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator
#define DIVIDE 32 // Divide a word from a specific location in memory into the word in the accumalator and then leaves the result in the accumulator
#define MULTIPLY 33 // Multiply a word from a specific location in memory to the word in the accumalator and then leaves it in the accumulator

#define BRANCH 40     // Branch to a specific location in memory
#define BRANCHNEG 41  // Branch to a specific location in memory if the accumulator is negative
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero
#define HALT 43       // Halt the program

#define SIZE 100 // memory size

// The simpletron computer
struct SIMPLETRON {
    int accumulator; // The accumulator
    int instructionCounter;  // The memory address of the current instruction
    int instructionRegister; // The current instruction to be performed
    int operationCode; // The operation code currently being perfromed
    int operand; // The memory address the current variable operates 
    int memory[SIZE]; // memory
};



#endif