//
// Created by Alexs on 26.11.2023.
//
#include <iostream>
#include <fstream>
#include <string>

bool isFileExist(const char* fileName) {
    bool isExist = false;
    std::ifstream fileReader;
    fileReader.open(fileName);

    if (fileReader.is_open() && !fileReader.bad()) {
        isExist = true;
    }

    fileReader.close();

    return isExist;
}

void readFileAsText(const char* fileName) {
    std::string textLine;

    std::cout << "File found.\n" << std::endl;

    std::ifstream fileReader;
    fileReader.open(fileName,std::ios::binary);

    while (std::getline(fileReader, textLine)) {
        std::cout << textLine << std::endl;
    }

    fileReader.close();
}

int main() {
    std::cout << "----Text file viewer----" << std::endl;
    std::string filePath;
    // Ввод пути к текстовому файлу
    std::cout << "Enter the path to the text file: ";
    std::getline(std::cin, filePath);

    if(isFileExist(filePath.c_str())){
        readFileAsText(filePath.c_str());
    }
    else
    {
        std::cerr << "Error: The file was not found." << std::endl;
    };
}
