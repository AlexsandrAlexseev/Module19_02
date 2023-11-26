#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;

    // Ввод пути к текстовому файлу
    std::cout << "Enter the path to the text file: ";
    std::getline(std::cin, filePath);

    // Попытка открыть файл
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    // Чтение и вывод содержимого файла
    char buffer[1024];
    while (file.read(buffer, sizeof(buffer))) {
        std::cout.write(buffer, file.gcount());
    }

    // Проверка на ошибки чтения файла
    if (!file.eof() && file.fail()) {
        std::cerr << "Error: Failed to read the file." << std::endl;
        return 1;
    }

    // Закрытие файла
    file.close();

    return 0;
}