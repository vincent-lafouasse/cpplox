#include "Lox.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <stdio.h>

#include "Scanner.h"

static std::string load_file(const std::string& path);

bool Lox::had_error = false;

void Lox::main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "Usage: cpplox [script]" << std::endl;
        exit(64);
    } else if (argc == 2) {
        run_file(argv[1]);
    } else {
        run_prompt();
    }
}

void Lox::run(std::string source) {
    Scanner scanner{source};
    std::vector<Token> tokens = scanner.scan_tokens();

    for (const Token& token : tokens) {
        std::cout << token.to_string() << ' ';
    }
    std::cout << '\n';
}

void Lox::run_prompt(void) {
    std::string input;

    for (;;) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "")
            break;
        run(input);
        had_error = false;
    }
}

void Lox::run_file(const std::string& path) {
    run(load_file(path));
    if (had_error) {
        exit(65);
    }
}

void Lox::error(int line, const std::string& message) {
    report(line, "", message);
}

void Lox::report(int line,
                 const std::string& where,
                 const std::string& message) {
    std::cerr << "[line " << line << "] Error" + where + ": " + message
              << std::endl;
    had_error = true;
}

static std::string load_file(const std::string& path) {
    std::ifstream file_stream(path);
    std::stringstream str_stream;
    str_stream << file_stream.rdbuf();
    return str_stream.str();
}
