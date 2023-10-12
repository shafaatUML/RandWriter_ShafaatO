// Copyright [2022] <Shafaat Osmani>
#include "RandWriter.hpp"

RandWriter::RandWriter(std::string text, int k) {
    order = k;
    int i, j;
    std::string orig_string = text;
    int length = text.length();

    for (j = 0; j < order; j++) {
        text += text[j];
    }

    text += text.substr(0, k+1);

    for (i = 0; i < length; i++) {
        char c = text[i];
        if (alphabet.find(c) == std::string::npos) {
            alphabet += c;
        } else {
           continue;
        }
    }

    for (i = 0; i < length; i++) {
        kgram[text.substr(i, k)][text.at(i + k)]++;
        kfreq[text.substr(i, k)]++;
    }
    srand((int)time(NULL)); //NOLINT
}

int RandWriter::orderK() const {
    return order;
}

int RandWriter::freq(std::string text) const {
    if (text.length() != static_cast<size_t>(order)) {
        throw std::runtime_error("kgram not length k (order)!!!");
    }

    auto t = kfreq.find(text);
    if (t == kfreq.end()) {
        return 0;
    } else {
        return t->second;
    }

    return 0;
}

int RandWriter::freq(std::string text, char c) const {
    if (text.size() != static_cast<size_t>(order)) {
        throw std::runtime_error("kgram not length k (order)!!!");
    }

    for (auto itr = kgram.begin(); itr != kgram.end(); itr++) {
        for (auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            if (itr->first == text && ptr->first == c) {
                return ptr->second;
            }
        }
    }

    return 0;
}

char RandWriter::kRand(std::string text) {
    if (text.size() != static_cast<size_t>(order)) {
        throw std::runtime_error("kgram not length k (order)!!!");
    }

    auto it = kgram.find(text);
    if (it == kgram.end()) {
        throw std::runtime_error("kgram does not exist!!!");
    }

    std::string krand;

    for (auto itr = kgram.begin(); itr != kgram.end(); itr++) {
        for (auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            if (itr->first == text) {
                for (int i = 0; i < ptr->second; i++) {
                    krand += ptr->first;
                }
            }
        }
    }

    int randindex = (rand() % krand.size()); //NOLINT
    return krand[randindex];
}

std::string RandWriter::generate(std::string text, int L) {
    if (text.size() != static_cast<size_t>(order)) {
        throw std::runtime_error("kgram not length k (order)!!!");
    }
    if (L < (order)) {
        throw std::runtime_error("L is less than order");
    }
    int difference = L - order;
    char c;
    std::string randstring = text;

    for (int i = 0; i < difference; i++) {
        std::string subway = randstring.substr(i, order);
        c = kRand(subway);
        randstring += c;
    }
    return randstring;
}

std::ostream& operator <<(std::ostream &out, const RandWriter &kGram) {
    out << "Order:      " << kGram.order << std::endl;
    out << "Alphabet:   " << kGram.alphabet << std::endl;

    auto jtr = kGram.kfreq.begin();
    for (auto itr = kGram.kgram.begin(); itr != kGram.kgram.end(); itr++) {
        for (auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            out << itr->first << "        kgram freq: "
            << jtr->second << std::endl << "          Next: " << ptr->first
            << "          Next char Frequency: " << ptr->second << std::endl;
        }
        jtr++;
    }

    return out;
}
