#include <stdio.h>

/* Input and Output Operations

   These operations handle basic input and output to from the terminal.
*/
#define READ 10  // Read a word from the terminal into a specific location in memory
#define WRITE 11 // Write a word from a specific location in memory to the terminal

/* Load and Store Operations
   
   These operations handle loading and storing to the accumalator.
*/
#define LOAD 20  // Load a word from a specific location in memory into the accumulator
#define STORE 21 // Store a word from the accumulator into a specific location in memory

/* Arithmetic Operations
   
   These operations handle all arithmetic operations
*/
#define ADD 30 // Add a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator
#define SUBSTRACT 31 // Substract a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator
#define DIVIDE 32 // Divide a word from a specific location in memory into the word in the accumalator and then leaves the result in the accumulator
#define MULTIPLY 33 // Multiply a word from a specific location in memory to the word in the accumalator and then leaves it in the accumulator

/* Transfer of control operations

   Useful for making jumps in the program
*/
#define BRANCH 40     // Branch to a specific location in memory
#define BRANCHNEG 41  // Branch to a specific location in memory if the accumulator is negative
#define BRANCHZERO 42 // Branch to a specific location in memory if the accumulator is zero
#define HALT 43       // Halt the program

#define SIZE 100 // memory size

void intro(){
    printf("*** Welcome to Simpletron! ***\n");
    printf("*** Please enter your program one instruction ***\n");
    printf("*** (or data word) at a time. I will type the ***\n");
    printf("*** location number and a question mark (?).  ***\n");
    printf("*** You then type the word for that location. ***\n");
    printf("*** Type the sentinel -9999 to stop entering ***\n");
    printf("*** your program. ***\n");
}


int main(){
    int memory[SIZE]; // memory
    int accumulator = 0; // The accumulator
    int instructionCounter = 0;  // The memory address of the current instruction
    int instructionRegister = 0; // The current instruction to be performed
    int operationCode = 0; // The operation code currently being perfromed
    int operand = 0; // The memory address the current variable operates 
    
    intro();

    int inp = 0;
    int i = 0;
    // loading progra,
    while (inp != -9999){
        printf("%02d ? ", i);
        scanf("%d", &inp);
        memory[i] = inp;
        ++i;
    }
    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins  ***\n");
   
    return 0;
}
