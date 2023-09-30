#include <stdio.h>
#include <stdlib.h>

#include "simpletron.h"

// create an instance of the simpletron
struct SIMPLETRON simpl;

// function prototypes
void intro();
void computerDump(struct SIMPLETRON simpletron);

int main(int argc, char *argv[])
{

    intro();

    if (argc == 2)
    {
        //  https://stackoverflow.com/questions/3501338/c-read-file-line-by-line/39237609#39237609
        FILE *filePointer;
        int bufferLength = 10;
        char buffer[bufferLength];

        filePointer = fopen(argv[1], "r");

        if (filePointer == NULL)
        {
            printf("Error! Could not open file\n");
            exit(-1);
        }

        int m = 0;

        while (fgets(buffer, bufferLength, filePointer))
        {
            if (atoi(buffer) > 9999 || atoi(buffer) < -9999)
            {
                printf("Incorrect input!\n");
                exit(-1);
            }

            simpl.memory[m] = atoi(buffer);
            ++m;
        }

        fclose(filePointer);
    }
    else if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
        exit(-1);
    }
    else
    {
        int inp = 0;
        int n = 0;

        // loading program
        while (1)
        {
            if (inp == -9999)
            {
                break;
            }

            printf("%02d ? ", n);
            scanf("%d", &inp);

            if (inp > 9999 || inp < -9999)
            {
                printf("Incorrect input!\n");
                printf("Please try again\n");
                continue;
            }

            simpl.memory[n] = inp;

            ++n;
        }
    }

    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins  ***\n");

    // Run infinte loop through the instructions

    while (simpl.instructionCounter < 100)
    {
        // get current instruction
        simpl.instructionRegister = simpl.memory[simpl.instructionCounter];

        // get opcode and operand
        simpl.operationCode = simpl.instructionRegister / 100;
        simpl.operand = simpl.instructionRegister % 100;

        switch (simpl.operationCode)
        {
        case READ:
            printf("? ");
            scanf("%d", &simpl.memory[simpl.operand]);
            printf("%d loaded into memory address: %d\n", simpl.memory[simpl.operand], simpl.operand);
            ++simpl.instructionCounter;
            break;

        case WRITE:
            printf("? %02d from memory address: %d\n", simpl.memory[simpl.operand], simpl.operand);
            ++simpl.instructionCounter;
            break;

        case LOAD:
            printf("Loaded %d into the accumulator.\n", simpl.memory[simpl.operand]);
            simpl.accumulator = simpl.memory[simpl.operand];
            ++simpl.instructionCounter;
            break;

        case STORE:
            printf("Copied %d from the accumulator into memory address %d.\n", simpl.accumulator, simpl.operand);
            simpl.memory[simpl.operand] = simpl.accumulator;
            ++simpl.instructionCounter;
            break;

        case ADD:
            printf("Add %d to the acummulator's value: %d.\n", simpl.memory[simpl.operand], simpl.accumulator);
            simpl.accumulator += simpl.memory[simpl.operand];
            if (simpl.accumulator > 9999 || simpl.accumulator < -9999)
            {
                printf("*** Accumulator overflow ***\n");
                printf("*** Simpletron execution abnormally terminated ***\n");
                computerDump(simpl);
                exit(1);
            }
            ++simpl.instructionCounter;
            break;

        case SUBSTRACT:
            printf("Substract %d from the acummulator's value: %d.\n", simpl.memory[simpl.operand], simpl.accumulator);
            simpl.accumulator -= simpl.memory[simpl.operand];
            if (simpl.accumulator > 9999 || simpl.accumulator < -9999)
            {
                printf("*** Accumulator overflow ***\n");
                printf("*** Simpletron execution abnormally terminated ***\n");
                computerDump(simpl);
                exit(1);
            }
            ++simpl.instructionCounter;
            break;

        case DIVIDE:
            if (simpl.memory[simpl.operand] == 0)
            {
                printf("*** Attempt to divide by zero ***\n");
                printf("*** Simpletron execution abnormally terminated ***\n");
                computerDump(simpl);
                exit(1);
            }
            printf("Divide the acummulator's value: %d with %d.\n", simpl.accumulator, simpl.memory[simpl.operand]);
            simpl.accumulator /= simpl.memory[simpl.operand];
            ++simpl.instructionCounter;
            break;

        case MULTIPLY:
            printf("Multiply the accumulator's value: %d with %d.\n", simpl.accumulator, simpl.memory[simpl.operand]);
            simpl.accumulator *= simpl.memory[simpl.operand];
            if (simpl.accumulator > 9999 || simpl.accumulator < -9999)
            {
                printf("*** Accumulator overflow ***\n");
                printf("*** Simpletron execution abnormally terminated ***\n");
                computerDump(simpl);
                exit(1);
            }
            ++simpl.instructionCounter;
            break;

        case BRANCH:
            printf("Performed Jump to: %d\n", simpl.operand);
            if (simpl.operand > 100 | simpl.operand < 0)
            {
                printf("*** Invalid Jump ***\n");
                printf("*** Simpletron execution abnormally terminated ***\n");
                computerDump(simpl);
                exit(1);
            }
            simpl.instructionCounter = simpl.operand;
            break;

        case BRANCHNEG:
            if (simpl.accumulator < 0)
            {
                if (simpl.operand > 100 | simpl.operand < 0)
                {
                    printf("*** Invalid Jump ***\n");
                    printf("*** Simpletron execution abnormally terminated ***\n");
                    computerDump(simpl);
                    exit(1);
                }
                simpl.instructionCounter = simpl.operand;
            }
            else
                ++simpl.instructionCounter;
            break;

        case BRANCHZERO:
            if (simpl.accumulator == 0)
            {
                if (simpl.operand > 100 | simpl.operand < 0)
                {
                    printf("*** Invalid Jump ***\n");
                    printf("*** Simpletron execution abnormally terminated ***\n");
                    computerDump(simpl);
                    exit(1);
                }
                simpl.instructionCounter = simpl.operand;
            }
            else
                ++simpl.instructionCounter;
            break;

        case HALT:
            printf("** Simpletron execution terminated ***\n");
            computerDump(simpl);
            exit(0);

        default:
            // printf("%d Incorrect instruction \n", operationCode);
            break;
        }
    }

    return 0;
}

void intro()
{
    printf("*** Welcome to Simpletron! ***\n");
    printf("*** Please enter your program one instruction ***\n");
    printf("*** (or data word) at a time. I will type the ***\n");
    printf("*** location number and a question mark (?).  ***\n");
    printf("*** You then type the word for that location. ***\n");
    printf("*** Type the sentinel -9999 to stop entering  ***\n");
    printf("*** your program. ***\n");
}

void computerDump(struct SIMPLETRON simpletron)
{
    printf("REGISTERS:\n");
    printf("accumulator          %+05d\n", simpletron.accumulator);
    printf("instructionCounter      %02d\n", simpletron.instructionCounter);
    printf("instructionRegister  %+05d\n", simpletron.instructionRegister);
    printf("operationCode           %02d\n", simpletron.operationCode);
    printf("operand                 %02d\n", simpletron.operand);

    printf("\n");

    printf("%8d", 0);
    for (int i = 1; i < 10; i++)
    {
        printf("%6d", i);
    }

    for (int i = 0; i < 100; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n%2d %+05d ", i, simpletron.memory[i]);
        }
        else
        {
            printf("%+05d ", simpletron.memory[i]);
        }
    }

    printf("\n");
}
