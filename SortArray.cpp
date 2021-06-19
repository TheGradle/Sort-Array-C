#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<int> StringToVector(std::string line)
{
    std::vector<int> vector;
    std::istringstream iss(line);

    for (std::string line; iss >> line;)
    {
        vector.push_back(stoi(line));
    }

    return vector;
}

std::string SortArray(std::string line)
{
    std::string result;
    std::vector<int> vector = StringToVector(line);
    int max = 0;
    int temp = 0;

    for (int i = 0; i < vector.size(); i++)
    {
        max = i;
        
        for (int j = i + 1; j < vector.size(); j++)
        {
            max = (vector[j] > vector[max]) ? j : max;
        }

        if (i != max)
        {
            temp = vector[i];
            vector[i] = vector[max];
            vector[max] = temp;
        }
    }

    for (auto el : vector)
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