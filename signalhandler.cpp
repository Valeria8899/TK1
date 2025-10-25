#include "signalhandler.h"
#include <vector>
#include <fstream> 
#include <string>
#include <iostream> 

namespace TK2 {

    void TK2::SignalHandler::Read(const std::string&signals_in)
        {
        std::ifstream iffile(signals_in, std::ios::in);

        if (!iffile.is_open()) {
            throw std::runtime_error("Can't open file");
        }
       
int a;
while (iffile >> a) {
    buffer_.push_back(a);
}

if (iffile.eof()) {
    std::cout << "Достигнут конец файла" << std::endl;
} else if (iffile.fail()) {
    std::cout << "Ошибка чтения: нечисловые данные в файле" << std::endl;
}

// Вывод вектора
std::cout << "Исходный массив: [";
for (size_t i = 0; i < buffer_.size(); i++) {
    std::cout << buffer_[i] << (i < buffer_.size() - 1 ? ", " : "");
}
std::cout << "]" << std::endl;
    
    }
     void TK2::SignalHandler::Write(const std::string&signals_out) {
        
        std::ofstream offile(signals_out, std::ios::out);

        if (!offile.is_open()) {
            throw std::runtime_error("Can't open file");
        }
        for (auto i : buffer_ ) {
            offile << i;
        }
        offile.close();
    }
// 1. Четные числа

    std::vector<int> SignalHandler::getEvenNumbers() const {

    std::vector<int> result;
    for (int x : buffer_) {
        if (x % 2 == 0) {
            result.push_back(x);
        }
    }
    return result;
}


//2. Числа больше среднего значения

std::vector<int> SignalHandler::getNumbersAboveAverage() const {
    
    if (buffer_.empty()) return {};
    
    double sum = 0;
    for (int x : buffer_) {
        sum += x;
    }
    double average = sum / buffer_.size();
    
    std::vector<int> result;
    for (int x : buffer_) {
        if (x > average) {
            result.push_back(x);
             }
    }
    return result;
}

}
