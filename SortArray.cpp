#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

std::multiset<int, std::greater<int>> VectorToMultiset(std::vector<int> numbers)
{
    std::multiset<int, std::greater<int>> mset;

    for (auto el : numbers)
    {
        mset.insert(el);
    }

    return mset;
}

std::string SortArray(std::string line)
{
    std::string result;
    std::vector<int> vector;
    std::istringstream iss(line);
    for (std::string line; iss >> line; )
        vector.push_back(stoi(line));

    std::multiset<int, std::greater<int>> mset = VectorToMultiset(vector);

    for (auto el : mset)
    {
        result += std::to_string(el) + " ";
    }

    return result;
}

int main()
{
    std::ofstream out;
    std::ifstream in;
    std::string line;
    
    out.open("OUTPUT.txt");
    in.open("INPUT.txt");

    if (in.is_open())
    {
        while (getline(in, line))
        {
            out << SortArray(line);
        }
    }
    else
    {
        std::cout << "File INPUT.txt wasn't finded. Please read README.txt" << std::endl;
    }

    in.close();
    out.close();

    std::cout << "End of program" << std::endl;
    system("pause");
}