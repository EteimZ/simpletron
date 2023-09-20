# simpletron

This is my implementation of the simpletron computer from the book [C How to Program](https://deitel.com/c-how-to-program/).

Simpletron is a simulated computer that that can be programmed using the **Simpletron Machine Language(SML)**. The Simpletron Machine language contains 12 instructions.
The length of each instruction is four numerical values which is refered to as a **word**.

```c
1009     // Read a value from the keyboard and store it into memory address 09                                                                                                                        
1010     // Read a value from the keyboard and store it into memory address 10                                                   
2009     // load the value from memory address 09 into the accumulator                                                   
3010     // Add the value from memory address 10 to the accumulator                                                                                                                        
2111     // Store the value from the accumulator into memory address 11                                                              
1111     // Write the value from memory address 11 to the terminal                                                                                                                        
4300     // Halt the program
```

The program above is **SML**, it instructs the computer to add two numbers together.

## Usage

To use the C implementation of Simpletron, follow the instruction below:

```bash
cd c-simpletron
gcc main.c -o main # compile the program
./main # run the program
```

You are going to add your instructions one line at a time and press enter.
To end the instruction entering phase provide the value **-9999**. 


## Memory 

The simpletron can only store 100 words in memory. The memory location ranges from **00** to **99**.

## Registers 

The simpletron has 3 registers, 1 is a general purpose register the other two are special purpose registers.
- The **Accumalator** : This is used to temporary hold values while operations is still being performed.
- The **Instruction Counter**: This is used to hold the memory location of current instruction.
- The **Instruction Register**: This is used to hold the current instruction being performed. It consist of two parts.
    - **operation**: The operation being performed. This is one of the 12 instructions of the simpletron.
    - **operand**: The memory address the operation is working with. 

## Instruction set

The simpletron contains 12 instructions divided into four categories.

### Input and Output Instructions

These instructions handle the basic input and output of the simpletron

| Name        | Code        | Description|
| ----------- | ----------- |------------|
| READ        | 10          | Read a word from the terminal into a specific location in memory|
| Write       | 11          | Write a word from a specific location in memory to the terminal |

### Accumulator Instructions

These instructions are used to work with the accumulator.

| Name        | Code        | Description|
| ----------- | ----------- |------------|
| LOAD        | 20          | Load a word from a specific location in memory into the accumulator|
| STORE       | 21          | Store a word from the accumulator into a specific location in memory |

### Arithmetic Instructions

These instructions handle arithmetic operations

| Name        | Code        | Description|
| ----------- | ----------- |------------|
| ADD         | 30          | Add a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator|
| SUBTRACT    | 31          | Substract a word from a specific location in memory to the word in the accumalator and then leaves the result in the accumulator |
| DIVIDE      | 32          | Divide a word from a specific location in memory into the word in the accumalator and then leaves the result in the accumulator |
| MULTIPLY    | 33          | Multiply a word from a specific location in memory to the word in the accumalator and then leaves it in the accumulator |

### Control FLow Instructions

These instructions are used to alter the flow of the program

| Name        | Code        | Description|
| ----------- | ----------- |------------|
| BRANCH      | 40          | Branch to a specific location in memory|
| BRANCHNEG   | 41          | Branch to a specific location in memory if the accumulator is negative |
| BRANCHZERO  | 42          | Branch to a specific location in memory if the accumulator is zero |
| HALT        | 43          | Halt the program |





