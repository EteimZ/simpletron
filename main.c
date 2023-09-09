#include <stdio.h>
#include "simpletron.h"

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
    int n = 0;
    // loading program
    while (inp != -9999){
        printf("%02d ? ", n);
        scanf("%d", &inp);
        memory[n] = inp;
        ++n;
    }
    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins  ***\n");
    
    // Run infinte loop through the instructions
    int e = 0;
    while (e != 100)
    {   
        // get current instruction
        instructionRegister = memory[instructionCounter];

        // get opcode and operand
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

       switch (operationCode)
        {
            case READ:
                printf("? ");
                scanf("%d", &memory[ operand ]);
                printf("%d loaded into memory address: %d\n", memory[ operand ], operand);
                ++instructionCounter;
                break;
            
            case WRITE:
                printf("? %02d from memory address: %d\n", memory[ operand ], operand);
                ++instructionCounter;
                break;
            
            case LOAD:
                printf("Loaded %d into the accumulator.\n", memory[ operand ]);
                accumulator = memory[ operand ];
                ++instructionCounter;
                break;
            
            case STORE:
                printf("Copied %d from the accumulator into memory address %d.\n",accumulator, operand);
                memory[ operand ] = accumulator;
                ++instructionCounter;
                break;
            
            case ADD:
                printf("Add %d to the acummulator's value: %d.\n", memory[ operand ], accumulator);                
                accumulator += memory[ operand ];
                ++instructionCounter;
                break;
            
            case SUBSTRACT:
                printf("Substract %d from the acummulator's value: %d.\n", memory[ operand ], accumulator);                            
                accumulator -= memory[ operand ];
                ++instructionCounter;
                break;

            case DIVIDE:
                printf("Divide the acummulator's value: %d with %d.\n", accumulator, memory[ operand ]); 
                accumulator /= memory[ operand ];
                ++instructionCounter;
                break;

            case MULTIPLY:
                printf("Multiply the accumulator's value: %d with %d.\n", accumulator, memory[ operand ]);
                accumulator *= memory[ operand ];
                ++instructionCounter;
                break;
            
            case BRANCH:
                printf("Performed Jump to: %d\n", operand);
                instructionCounter = operand;
                break;
            
            case BRANCHNEG:
                if (accumulator < 0 )
                    instructionCounter = operand;
                break;
            
            case BRANCHZERO:
                if (accumulator == 0)
                    instructionCounter = operand;
                break;

            
            case HALT:
                printf("Program Halted\n");
                e = 100;
                break;

            default:
                //printf("%d Incorrect instruction \n", operationCode);
                break;
            
        }
    }
       
    return 0;
}