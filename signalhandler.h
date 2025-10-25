#include <vector>
#include <fstream> 
#include <string>
#include <iostream> 

namespace TK2 {

    class SignalHandler {

    public:
        void Read(const std::string&signals_in);

        void Write(const std::string&signals_out);

        std::vector<int> getEvenNumbers() const;

        std::vector<int> getNumbersAboveAverage() const;
        
        std::vector<int> getUniqueNumbers() const;



        // Методы для вывода результатов
    void printFilteredResults() const;
    void printVector(const std::vector<int>& vec, const std::string& title) const;


    private:

     std:: vector <int> buffer_;
        };
    }

        
        