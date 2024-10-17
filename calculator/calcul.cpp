#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>  // Для std::atof

void print_usage() {
    std::cout << "Usage: calculator -o operation operand1 operand2 [operand3] [operand4]\n";
    std::cout << "Supported operations:\n";
    std::cout << "  -o mul : multiply operands\n";
    std::cout << "  -o div : divide first operand by the rest\n";
}

double multiply(const std::vector<double>& operands) {
    double result = 1.0;
    for (double operand : operands)
        result *= operand;
    return result;
}

double divide(const std::vector<double>& operands) {
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            std::cerr << "Error: Division by zero is not allowed!\n";
            exit(1);
        }
        result /= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 4 || argc > 6) {
        print_usage();
        return 1;
    }

    std::string operation = argv[2];
    std::vector<double> operands;

    for (int i = 3; i < argc; ++i) {
        operands.push_back(std::atof(argv[i]));
    }

    if (operation == "mul") {
        std::cout << "Result: " << multiply(operands) << std::endl;
    } else if (operation == "div") {
        std::cout << "Result: " << divide(operands) << std::endl;
    } else {
        print_usage();
        return 1;
    }

    return 0;
}

