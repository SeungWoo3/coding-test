#include <iostream>
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> split(std::string input, char splitter);
int getSum(std::string input);

int main() {
    std::string input;
    std::cin >> input;
    std::vector<std::string> splited = split(input, '-');
    int sum = 0;

    sum = getSum(splited[0]);

    std::vector<std::string>::iterator iter;
    for (iter = splited.begin() + 1; iter != splited.end(); iter++) {
        sum -= getSum(*iter);
    }
    std::cout << sum << std::endl;

    return 0;
}

std::vector<std::string> split(std::string input, char splitter) {
    std::vector<std::string> output;
    std::stringstream sStream(input);
    std::string buffer;
    while (std::getline(sStream, buffer, splitter)) {
        output.push_back(buffer);
    }
    return output;
}

int getSum(std::string input) {
    int sum = 0;
    std::vector<std::string> numbers;
    numbers = split(input, '+');
    std::vector<std::string>::iterator iter;
    for (iter = numbers.begin(); iter != numbers.end(); iter++) {
        sum += std::stoi(*iter);
    }
    return sum;
}