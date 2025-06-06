#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdexcept>

using namespace std;

class Microprocessor {
public:
    int ax = 0, ab = 0, ay = 0, ad = 0;
    vector<int> memory;

    Microprocessor(size_t mem_size) : memory(mem_size, 0) {}

    int& getRegister(const char* reg) {
        if (strcmp(reg, "ax") == 0) return ax;
        else if (strcmp(reg, "ab") == 0) return ab;
        else if (strcmp(reg, "ay") == 0) return ay;
        else if (strcmp(reg, "ad") == 0) return ad;
        else throw invalid_argument("Invalid register name");
    }
};

class Move {
public:
    // Move register to register
    static void regToReg(Microprocessor& cpu, const char* src, const char* dst) {
        cpu.getRegister(dst) = cpu.getRegister(src);
    }

    // Move immediate value to register
    static void immToReg(Microprocessor& cpu, int value, const char* dst) {
        cpu.getRegister(dst) = value;
    }

    // Move register value to memory address
    static void regToMem(Microprocessor& cpu, const char* src, int addr) {
        if (addr < 0 || (size_t)addr >= cpu.memory.size()) throw out_of_range("Memory address out of range");
        cpu.memory[addr] = cpu.getRegister(src);
    }

    // Move memory value to register
    static void memToReg(Microprocessor& cpu, int addr, const char* dst) {
        if (addr < 0 || (size_t)addr >= cpu.memory.size()) throw out_of_range("Memory address out of range");
        cpu.getRegister(dst) = cpu.memory[addr];
    }
};

class Arithmetic {
public:
    // Add src register to dst register
    static void add(Microprocessor& cpu, const char* src, const char* dst) {
        cpu.getRegister(dst) += cpu.getRegister(src);
    }

    // Subtract src register from dst register
    static void sub(Microprocessor& cpu, const char* src, const char* dst) {
        cpu.getRegister(dst) -= cpu.getRegister(src);
    }

    // Multiply dst register by src register
    static void mul(Microprocessor& cpu, const char* src, const char* dst) {
        cpu.getRegister(dst) *= cpu.getRegister(src);
    }

    // Divide dst register by src register (integer division)
    static void div(Microprocessor& cpu, const char* src, const char* dst) {
        int divisor = cpu.getRegister(src);
        if (divisor == 0) throw runtime_error("Division by zero");
        cpu.getRegister(dst) /= divisor;
    }
};

// Helper: parse int or register name
bool isRegister(const char* op) {
    return strcmp(op, "ax") == 0 || strcmp(op, "ab") == 0 || strcmp(op, "ay") == 0 || strcmp(op, "ad") == 0;
}

int parseValue(Microprocessor& cpu, const char* op) {
    if (isRegister(op)) {
        return cpu.getRegister(op);
    } else {
        // assume immediate integer
        return atoi(op);
    }
}

int main() {
    Microprocessor cpu(256); // 256 memory size

    ifstream file("instructions.txt");
    if (!file) {
        cerr << "Cannot open instructions.txt\n";
        return 1;
    }

    char line[100];
    int pc = 1;

    while (file.getline(line, sizeof(line))) {
        try {
            // Skip empty lines
            if (strlen(line) == 0) {
                pc++;
                continue;
            }

            // Trim leading spaces
            char* ptr = line;
            while (*ptr == ' ' || *ptr == '\t') ptr++;

            // Stop on HLT
            if (strncmp(ptr, "HLT", 3) == 0) {
                cout << "HLT found at line " << pc << ". Halting.\n";
                break;
            }

            // Parse instruction
            char* inst = strtok(ptr, " ");
            if (!inst) throw "Missing instruction";

            char* operands = strtok(NULL, "\n");
            if (!operands) operands = (char*)"";

            // Split operands by comma
            char* op1 = strtok(operands, ",");
            char* op2 = strtok(NULL, ",");

            // Trim spaces from operands
            if (op1) while (*op1 == ' ') op1++;
            if (op2) while (*op2 == ' ') op2++;

            if (strcmp(inst, "MOV") == 0) {
                if (!op1 || !op2) throw "MOV needs two operands";

                // Determine operand types
                if (isRegister(op1) && isRegister(op2)) {
                    // MOV reg, reg
                    Move::regToReg(cpu, op2, op1);
                } else if (isRegister(op1) && op2 && op2[0] >= '0' && op2[0] <= '9') {
                    // MOV reg, immediate
                    int val = atoi(op2);
                    Move::immToReg(cpu, val, op1);
                } else if (isRegister(op1) && op2 && op2[0] == '[') {
                    // MOV reg, [addr]
                    // parse address inside []
                    int addr = atoi(op2 + 1);
                    Move::memToReg(cpu, addr, op1);
                } else if (op1 && op1[0] == '[' && isRegister(op2)) {
                    // MOV [addr], reg
                    int addr = atoi(op1 + 1);
                    Move::regToMem(cpu, op2, addr);
                } else {
                    throw "Invalid MOV operands";
                }

            } else if (strcmp(inst, "ADD") == 0) {
                if (!op1 || !op2) throw "ADD needs two operands";
                if (!isRegister(op1) || !isRegister(op2)) throw "ADD operands must be registers";
                Arithmetic::add(cpu, op1, op2);

            } else if (strcmp(inst, "SUB") == 0) {
                if (!op1 || !op2) throw "SUB needs two operands";
                if (!isRegister(op1) || !isRegister(op2)) throw "SUB operands must be registers";
                Arithmetic::sub(cpu, op1, op2);

            } else if (strcmp(inst, "MUL") == 0) {
                if (!op1 || !op2) throw "MUL needs two operands";
                if (!isRegister(op1) || !isRegister(op2)) throw "MUL operands must be registers";
                Arithmetic::mul(cpu, op1, op2);

            } else if (strcmp(inst, "DIV") == 0) {
                if (!op1 || !op2) throw "DIV needs two operands";
                if (!isRegister(op1) || !isRegister(op2)) throw "DIV operands must be registers";
                Arithmetic::div(cpu, op1, op2);

            } else {
                throw "Unknown instruction";
            }

            // Print registers after each instruction
            cout << pc << ": " << inst << " ";
            if (op1) cout << op1 << " ";
            if (op2) cout << ", " << op2;
            cout << "\nRegisters: ax=" << cpu.ax << " ab=" << cpu.ab << " ay=" << cpu.ay << " ad=" << cpu.ad << "\n";

            pc++;

        } catch (const char* err) {
            cerr << "Error at line " << pc << ": " << err << "\n";
            pc++;
        } catch (const exception& e) {
            cerr << "Error at line " << pc << ": " << e.what() << "\n";
            pc++;
        }
    }

    cout << "Program ended at PC = " << pc << "\n";

    return 0;
}
