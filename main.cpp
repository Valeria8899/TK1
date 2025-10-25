#include <iostream>
#include "signalhandler.h"

int main() {
    TK2::SignalHandler file;

    file.Read("signals_in.txt");
    file.Write("signals_out.txt");

//Четные числа 
     auto even = file.getEvenNumbers();

    std::cout << "Четные числа: [";

    for (size_t i = 0; i < even.size(); i++) {
        std::cout << even[i] << (i < even.size() - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
    
    // Числа больше среднего

    auto aboveAvg = file.getNumbersAboveAverage();
    
    std::cout << "Числа > среднего: [";
    for (size_t i = 0; i < aboveAvg.size(); i++) {
        std::cout << aboveAvg[i] << (i < aboveAvg.size() - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    return 0;
}