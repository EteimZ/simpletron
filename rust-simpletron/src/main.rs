mod simpletron;


fn main() {
    simpletron::intro();

    let mut cpu = simpletron::CPU::new();
    cpu.load();
    cpu.run();
}
