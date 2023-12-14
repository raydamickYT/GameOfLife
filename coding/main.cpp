#include <iostream>

#include <iostream>
#include <vector>
#include "StringProcessor.h"
#include "NumberProcessor.h"

// Helperfunctie om de inhoud van een vector te printen
template <typename T>
void printVector(const std::vector<T> &vec)
{
    for (const auto &item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
int main()
{
    // Werken met std::vector<std::string>
    std::vector<std::string> colours{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    std::vector<std::string> beforePurple, afterPurple;
    StringProcessor::SplitBeforeAndAfterPurple(colours, beforePurple, afterPurple);
    std::cout << "Before 'purple': ";
    printVector(beforePurple);
    std::cout << "After 'purple': ";
    printVector(afterPurple);

    StringProcessor::ConvertToUppercase(colours);
    std::cout << "Uppercase colours: ";
    printVector(colours);

    StringProcessor::RemoveDuplicates(colours);
    std::cout << "Colours without duplicates: ";
    printVector(colours);

    // de nummers
    std::vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
    NumberProcessor::RemoveNegativeNumbers(numbers);

    //hij zegt dat komma getallen even zijn. ik weet niet waarom hij niet het hele getal pakt.
    NumberProcessor::PrintEvenOrOdd(numbers);

    double sum, avg, product;
    NumberProcessor::CalculateStatistics(numbers, sum, avg, product);
    std::cout << "Som: " << sum << ", Gemiddelde: " << avg << ", Product: " << product << std::endl;

    bool isRunning = true;
    while (isRunning)
    {
    }

    return 0;
}