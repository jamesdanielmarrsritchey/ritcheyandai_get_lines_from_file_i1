#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

bool readLines(const std::string& filename, int minLine, int maxLine) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    for (int i = 1; i < minLine; ++i) {
        if (!std::getline(file, line)) {
            return false;
        }
    }

    for (int i = minLine; i <= maxLine; ++i) {
        if (!std::getline(file, line)) {
            break;
        }
        std::cout << line << std::endl;
    }

    file.close();
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " --file <filename> --min_line <minLine> --max_line <maxLine>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename;
    int minLine, maxLine;

    for (int i = 1; i < argc; i += 2) {
        std::string arg = argv[i];
        if (arg == "--file") {
            filename = argv[i + 1];
        } else if (arg == "--min_line") {
            minLine = std::stoi(argv[i + 1]);
        } else if (arg == "--max_line") {
            maxLine = std::stoi(argv[i + 1]);
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (!readLines(filename, minLine, maxLine)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}