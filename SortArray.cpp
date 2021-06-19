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

bool isNumbers(std::string line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if ((int(line[i]) < 48 || int(line[i]) > 57) && (int(line[i]) != 32 && int(line[i]) != 45))
        {
            return false;
        }
    }

    return true;
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
            if (isNumbers(line))
            {
                out << SortArray(line);
                std::cout << "Sorted! See the results in the OUTPUT.txt file" << std::endl << std::endl;
            }
            else
            {
                std::cout << "Error! Enter only numbers!" << std::endl << std::endl;
            }
        }
    }
    else
    {
        std::cout << "File INPUT.txt wasn't finded. Please create and fill it." << std::endl << std::endl;
    }

    in.close();
    out.close();

    system("pause");
}