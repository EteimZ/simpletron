#include "processor.h"

void simpletron::intro(){
   std::cout<<"*** Welcome to Simpletron! ***"<<std::endl;
   std::cout<<"*** Please enter your program one instruction ***"<<std::endl;
   std::cout<<"*** (or data word) at a time. I will type the ***"<<std::endl;
   std::cout<<"*** location number and a question mark (?).  ***"<<std::endl;
   std::cout<<"*** You then type the word for that location. ***"<<std::endl;
   std::cout<<"*** Type the sentinel -9999 to stop entering ***"<<std::endl;
   std::cout<<"*** your program. ***"<<std::endl;
}

simpletron::Processor::Processor(){
    for(int i = 0; i < SIZE; i++){
        this->memory[i] = 0;
    }

    this->accumulator = 0;
    this->instructionCounter = 0;
    this->instructionRegister = 0;
    this->operationCode = 0;
    this->operand = 0;
}

void simpletron::Processor::load(){
    int inp = 0;
    int n = 0;
    // loading program
    while (inp != -9999){
        std::cout<<n<<std::endl;
        std::cin>>inp;
        this->memory[n] = inp;
        ++n;
    }
    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins  ***\n");
}

void simpletron::Processor::run(){
    // Run infinte loop through the instructions
    int e = 0;
    while (e != 100){   
        // get current instruction
        this->instructionRegister = this->memory[this->instructionCounter];

        // get opcode and this->operand
        this->operationCode = this->instructionRegister / 100;
        this->operand = this->instructionRegister % 100;
        
        switch (this->operationCode){
            case simpletron::Operands::READ:
                std::cout<<"? "<<std::endl;
                std::cin>>this->memory[ this->operand ];
                std::cout<<this->memory[ this->operand ]<<" loaded into memory address: "<<this->operand<<std::endl;
                ++this->instructionCounter;
                break;
            
            case simpletron::Operands::WRITE:
                std::cout<<"? "<<this->memory[ this->operand ]<<" from memory address: "<<this->operand<<std::endl;
                ++this->instructionCounter;
                break;
            
            case simpletron::Operands::LOAD:
                std::cout<<"Loaded "<<this->memory[ this->operand ]<<" into the accumulator."<<std::endl;
                this->accumulator = this->memory[ this->operand ];
                ++this->instructionCounter;
                break;
            
            case simpletron::Operands::STORE:
                std::cout<<"Copied "<<this->accumulator<<">>>> from the accumulator into memory address "<<this->operand<<std::endl;
                this->memory[ this->operand ] = this->accumulator;
                ++this->instructionCounter;
                break;
            
            case simpletron::Operands::ADD:
                std::cout<<"Add "<<this->memory[ this->operand ]<<" to the acummulator's value: "<<this->accumulator<<std::endl;                
                this->accumulator += this->memory[ this->operand ];
                ++this->instructionCounter;
                break;
            
            case simpletron::Operands::SUBSTRACT:
                std::cout<<"Substract "<<this->memory[ this->operand ]<<" from the acummulator's value: "<<this->accumulator<<std::endl;                             
                this->accumulator -= this->memory[ this->operand ];
                ++this->instructionCounter;
                break;

            case simpletron::Operands::DIVIDE:
                std::cout<<"Divide the acummulator's value: "<<this->accumulator<<" with "<<this->memory[ this->operand ]<<std::endl; 
                this->accumulator /= this->memory[ this->operand ];
                ++this->instructionCounter;
                break;

            case simpletron::Operands::MULTIPLY:
                std::cout<<"Multiply the accumulator's value: "<<this->accumulator<<" with "<<this->memory[ this->operand ]<<std::endl;
                this->accumulator *= this->memory[ this->operand ];
                ++this->instructionCounter;
                break;
            
            case simpletron::Operands::BRANCH:
                std::cout<<"Performed Jump to: "<<this->operand<<std::endl;
                this->instructionCounter = this->operand;
                break;
            
            case simpletron::Operands::BRANCHNEG:
                if (this->accumulator < 0 )
                    this->instructionCounter = this->operand;
                break;
            
            case simpletron::Operands::BRANCHZERO:
                if (this->accumulator == 0)
                    this->instructionCounter = this->operand;
                break;

            
            case simpletron::Operands::HALT:
                std::cout<<"Program Halted"<<std::endl;
                e = 100;
                break;

            default:
                //std::cout<<"%d Incorrect instruction \n", this->operationCode);
                break;
            
        }
    }
}