mod cpu;

pub use cpu::CPU;

pub fn intro(){
    println!("*** Welcome to Simpletron! ***\n");
    println!("*** Please enter your program one instruction ***");
    println!("*** (or data word) at a time. I will type the ***");
    println!("*** location number and a question mark (?).  ***");
    println!("*** You then type the word for that location. ***");
    println!("*** Type the sentinel -9999 to stop entering ***");
    println!("*** your program. ***");
}