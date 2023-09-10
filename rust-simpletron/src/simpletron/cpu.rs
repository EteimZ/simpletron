enum Operands{
    READ,        // Read a word from the terminal into a specific location in memory
    WRITE,         // Write a word from a specific location in memory to the terminal

    LOAD,          // Load a word from a specific location in memory into the self.accumulator
    STORE,         // Store a word from the self.accumulator into a specific location in memory

    ADD,           // Add a word from a specific location in memory to the word in the accumalator and then leaves the result in the self.accumulator
    SUBSTRACT,     // Substract a word from a specific location in memory to the word in the accumalator and then leaves the result in the self.accumulator
    DIVIDE,        // Divide a word from a specific location in memory into the word in the accumalator and then leaves the result in the self.accumulator
    MULTIPLY,      // Multiply a word from a specific location in memory to the word in the accumalator and then leaves it in the self.accumulator

    BRANCH,       // Branch to a specific location in memory
    BRANCHNEG,     // Branch to a specific location in memory if the self.accumulator is negative
    BRANCHZERO,    // Branch to a specific location in memory if the self.accumulator is zero
    HALT,          // Halt the program
}

impl Operands {
    fn from(value: i32)->Result<Self, String>{
        return match value {
            10 => Ok(Operands::READ),
            11 => Ok(Operands::WRITE),
            20 => Ok(Operands::LOAD),
            21 => Ok(Operands::STORE),
            30 => Ok(Operands::ADD),
            31 => Ok(Operands::SUBSTRACT),
            32 => Ok(Operands::DIVIDE),
            33 => Ok(Operands::MULTIPLY),
            40 => Ok(Operands::BRANCH),
            41 => Ok(Operands::BRANCHNEG),
            42 => Ok(Operands::BRANCHZERO),
            43 => Ok(Operands::HALT),
            _ => Err(format!("instruction not recognized {}", value))
        }
    }
}

const SIZE: usize = 100;

pub struct CPU{
    memory: [i32; SIZE], // memory
    accumulator: i32, // The self.accumulator
    instruction_counter: usize,  // The memory address of the current instruction
    instruction_register: i32, // The current instruction to be performed
    operation_code: i32, // The operation code currently being perfromed
    operand: i32 // The memory address the current variable operates 
}

impl CPU {
    pub fn new ()->Self{
        return CPU{
            memory: [0; SIZE], accumulator: 0,
            instruction_counter: 0, instruction_register: 0,
            operation_code: 0, operand: 0
        };
    }

    pub fn load(&mut self) {
        let mut inp = 0;
        let mut index: usize = 0;
        // loading program
        while inp != -9999{
            println!("{:6} ? ", index);
            let mut line: String = String::new();
            match std::io::stdin().read_line(&mut line){
                Err(error) => {
                    print!("invalid input {}", error);
                },
                Ok(_) =>{
                    inp =  line.trim().parse().unwrap();
                    self.memory[ index ] = inp;
                }
            }
            index += 1;
        }
        println!("*** Program loading completed ***");
        print!("*** Program execution begins  ***");
    }

    pub fn run(&mut self){
        // Run infinte loop through the instructions
        let mut e = 0;
        while e != 100 {   
            // get current instruction
            self.instruction_register = self.memory[self.instruction_counter];

            // get opcode and self.operand
            self.operation_code = self.instruction_register / 100;
            self.operand = self.instruction_register % 100;
            
            match Operands::from(self.operation_code){
                Ok(operand) =>{
                    match operand {
                        Operands::READ =>{
                            println!("? ");
                            //scanf("%d", &self.memory[ self.operand as usize ]);
                            let mut line: String = String::new();
                            match std::io::stdin().read_line(&mut line){
                                Err(error) => {
                                    print!("invalid input {}", error);
                                    e = 100;
                                },
                                Ok(_) =>{
                                    self.memory[ self.operand as usize ] = line.trim().parse().unwrap();
                                    println!("{} loaded into memory address: {}", self.memory[ self.operand as usize ], self.operand);
                                    self.instruction_counter += 1;
                                }
                            }
                        }
                        Operands::WRITE =>{
                            println!("? {} from memory address: {}", self.memory[ self.operand as usize ], self.operand);
                            self.instruction_counter += 1;
                        }
                        Operands::LOAD =>{
                            println!("Loaded {} into the accumulator.", self.memory[ self.operand as usize ]);
                            self.accumulator = self.memory[ self.operand as usize ];
                            self.instruction_counter += 1;
                        }
                        Operands::STORE =>{
                            println!("Copied {} from the accumulator into memory address {}.",self.accumulator, self.operand);
                            self.memory[ self.operand as usize ] = self.accumulator;
                            self.instruction_counter += 1;
                        }
                        Operands::ADD =>{
                            println!("Add {} to the acummulator's value: {}.", self.memory[ self.operand as usize ], self.accumulator);                
                            self.accumulator += self.memory[ self.operand as usize ];
                            self.instruction_counter += 1;
                        }
                        Operands::SUBSTRACT =>{
                            println!("Substract {} from the acummulator's value: {}.", self.memory[ self.operand as usize ], self.accumulator);                            
                            self.accumulator -= self.memory[ self.operand as usize ];
                            self.instruction_counter += 1;
                        }
                        Operands::DIVIDE =>{
                            println!("Divide the acummulator's value: {} with {}.", self.accumulator, self.memory[ self.operand as usize ]); 
                            self.accumulator /= self.memory[ self.operand as usize ];
                            self.instruction_counter += 1;
                        }
                        Operands::MULTIPLY =>{
                            println!("Multiply the accumulator's value: {} with {}.", self.accumulator, self.memory[ self.operand as usize ]);
                            self.accumulator *= self.memory[ self.operand as usize ];
                            self.instruction_counter += 1;
                        }
                        Operands::BRANCH =>{
                            println!("Performed Jump to: {}", self.operand);
                            self.instruction_counter = self.operand as usize;
                        }
                        Operands::BRANCHNEG =>{
                            if self.accumulator < 0{
                                self.instruction_counter = self.operand as usize;
                            }
                        }
                        Operands::BRANCHZERO =>{
                            if self.accumulator == 0{
                                self.instruction_counter = self.operand as usize;
                            }
                        }
                        Operands::HALT =>{
                            println!("Program Halted");
                            e = 100;
                        }
                    }
                },
                Err(error) =>{
                    println!("encounterd a strange instruction: {}", error);
                }
            }
        }
    }
}