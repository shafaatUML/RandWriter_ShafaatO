// Copyright [2022] <Shafaat Osmani>
#pragma once
#include <iostream>
#include <string>
#include <map>

class RandWriter {
 public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string text) const;
    int freq(std::string text, char c) const;
    char kRand(std::string text);
    std::string generate(std::string text, int L);
    friend std::ostream& operator<<(std::ostream &out,
    const RandWriter &kGram);

 private:
    int order;
    std::string alphabet;
    std::map<std::string, std::map<char, int>> kgram;
    std::map<std::string, int> kfreq;
};
