#include "cpu.h"

void handle_instruction(struct cpu *cpu, char *IR);
/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */
void cpu_load(struct cpu *cpu)
{
  const int DATA_LEN = 6;
  char data[DATA_LEN] = {
      // From print8.ls8
      0b10000010, // LDI R0,8
      0b00000000,
      0b00001000,
      0b01000111, // PRN R0
      0b00000000,
      0b00000001 // HLT
  };

  int address = 0;

  for (int i = 0; i < DATA_LEN; i++)
  {
    cpu->ram[address++] = data[i];
  }

  // TODO: Replace this with something less hard-coded
}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB)
{
  switch (op)
  {
  case ALU_MUL:
    // TODO
    break;

    // TODO: implement more ALU ops
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1; // True until we get a HLT instruction
  char *rgstr = cpu->reg;
  char *ram = cpu->ram;

  char *PC = cpu->guts->PC;
  char *IR = cpu->guts->IR;
  char *MAR = cpu->guts->MAR;
  char *MDR = cpu->guts->MDR;
  char *FL = cpu->guts->FL;

  while (running)
  {
    // TODO
    // 1. Get the value of the current instruction (in address PC).
    // 2. switch() over it to decide on a course of action.
    handle_instruction(cpu, IR);
    // 3. Do whatever the instruction should do according to the spec.
    // 4. Move the PC to the next instruction.
  }
}

/**
 * Initialize a CPU struct
 */
void cpu_init(struct cpu *cpu)
{
  // TODO: Initialize the PC and other special registers

  // TODO: Zero registers and RAM
}

/**
 * HELPERS
*/
void handle_instruction(struct cpu *cpu, char *IR)
{
  switch (*IR)
  {
    // ALU
  case ADD:
  case SUB:
  case MUL:
  case DIV:
  case MOD:
  case INC:
  case DEC:
  case CMP:
  case AND:
  case NOT:
  case OR:
  case XOR:
  case SHL:
  case SHR:
  // PC mutators
  case CALL:
  case RET:
  case INT:
  case IRET:
  case JMP:
  case JEQ:
  case JNE:
  case JGT:
  case JLT:
  case JLE:
  case JGE:
  // Other
  case NOP:
  case HLT:
  case LDI:
  case LD:
  case ST:
  case PUSH:
  case POP:
  case PRN:
  case PRA:
  default:
    printf("The %s IR instruction has no handler", IR);
  }
};