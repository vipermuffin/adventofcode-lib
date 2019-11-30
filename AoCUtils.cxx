//
//  Advent of Code Utilities
//
//  https://adventofcode.com
//
//  Created by vipermuffin 
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "AoCUtils.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

std::vector<std::string> parseFileForLines(const std::string& fileName)
{
   string line;
   vector<string> lineArray{};
   ifstream inputFile;
   inputFile.open(fileName);
   
   while(std::getline(inputFile,line))
   {
      lineArray.push_back(line);
   }
   inputFile.close();
   return lineArray;
}

std::vector<std::vector<int>> parseFileForNumbers(const std::string& fileName)
{
   std::vector<std::vector<int>> spreadsheet{};
   auto lines{parseFileForLines(fileName)};
   
   for(const auto& line : lines) {
      spreadsheet.push_back(parseLineForNumbers(line));
   }
   
   return spreadsheet;
}
std::vector<int> parseFileForNumberPerLine(const std::string& fileName)
{
   std::vector<int> spreadsheet{};
   auto lines{parseFileForLines(fileName)};
   
   for(const auto& line : lines) {
      try {
         spreadsheet.push_back(stoi(line));
      } catch (const std::invalid_argument&) {
         //Conversion failed
      }
      
   }
   
   return spreadsheet;
}

std::vector<std::string> parseLineForWords(const std::string& line)
{
   vector<string> words{};
   stringstream ss{line};
   string word;
   while(ss >> word) {
      words.push_back(word);
   }
   return words;
}

std::vector<std::string> parseCsvLineForWords(const std::string& line)
{
   vector<string> words{};
   stringstream ss{line};
   string word;
   while(getline(ss,word,',')) {
      words.push_back(word);
   }
   return words;
}

std::vector<int> parseLineForNumbers(const std::string& line)
{
   vector<int> numbers{};
   vector<string> words{parseLineForWords(line)};
   for(const auto& word : words) {
      try {
         numbers.push_back(stoi(word));
      } catch (const std::invalid_argument&) {
         //Conversion failed
      }
   }
   return numbers;
}

std::string convertVectorToString(const std::vector<int>&input)
{
   string s{};
   for(const auto& num : input) {
      s.append(to_string(num));
   }
   return s;
}

void printVector(const vector<int>& v) {
   cout << "v = {";
   auto x  = v.begin();
   if(x>= v.end()) {
      cout << "}";
   }
   while(x < v.end()) {
      cout << *x++ << (x==v.end() ? "}" : ",");
   }
   cout << endl;
}