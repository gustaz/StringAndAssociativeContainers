#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>
#include <string>
#include <regex>

int main()
{
    std::string line;
    std::ifstream in("input.txt");
    
    if(!in.good())
    {
        std::cout << "Failas nerastas! Ar tikrai egzistuoja failas, pavadinimu input.txt?";
        return 1;
    }
    
    std::ofstream out("output.txt");
    std::map<std::string, int> occurences;
    std::map<std::string, std::vector<int>> crossCheck;
    std::vector<std::string> url;
    
    int n = 0;
    while (!in.eof())
    {
        crossCheck.clear();
        n++;
        getline(in, line);

        std::stringstream stream(line);
        std::string word;

        int numberedWord = 0;
        while (stream >> word)
        {
            numberedWord++;
            bool isURL = false;
            std::transform(word.begin(), word.end(), word.begin(),
                [](unsigned char c) { return std::tolower(c); });

            if(std::regex_match(word, std::regex("(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"))) 
            {
                if (word[word.length() - 1] == ',' || word[word.length() - 1] == '.')
                    word.resize(word.length() - 1);
                url.push_back(word);
                word.clear();
                numberedWord--;
            }
            if (isdigit(word[0]) || ispunct(word[0]))
            {
                if (word.find("th") == std::string::npos)
                    for (int i = 0; i < word.length(); i++)
                        if (isdigit(word[i]) || ispunct(word[i]))
                        {
                            word = word.substr(i + 1);
                            i = -1;
                        }
            }

            if (word[word.length() - 2] == '\'')
                word.resize(word.length() - 2);
            
            if (isdigit(word[word.length() - 1]) || ispunct(word[word.length() - 1]))
            {
                if(word[word.length() - 2] == 'h' && word[word.length() - 3] == 't' && ispunct(word[word.length() - 1]))
                    word.resize(word.length() - 1);
                if (word[word.length() - 1] != 'h' && word[word.length() - 2] != 't')
                for (int i = word.length() - 1; i > 0; i--)
                    if (isdigit(word[i]) || ispunct(word[i]))
                    {
                        word.resize(i);
                        i = word.length();
                    }
            }
            
            if (!word.empty())
            {
                crossCheck.insert({ word, {0} });
                crossCheck[word].push_back(numberedWord);

                occurences.insert({ word, 1 });
                occurences[word]++;
            }
        }

        out << n << "-osios eilutes zodziu numeriai: " << std::endl;
        for (auto elem : crossCheck)
        {
            if (elem.second.size() > 1)
                out << elem.first << " ";
            
            for (int i = 1; i < elem.second.size(); i++)
                out << elem.second.at(i) << " ";

            out << std::endl;
        }
        out << std::endl;
    }
    
    out << "Bendras zodziu skaicius: " << std::endl;
    for (auto elem : occurences)
        if (elem.second > 1)
            out << elem.first << " " << elem.second << std::endl;
    out << std::endl;

    out << "Surasti URL: " << std::endl;
        for (auto &elem : url)
            out << elem << std::endl;
        
    in.close();
    out.close();
    return 0;
}


