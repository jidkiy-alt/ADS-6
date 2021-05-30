// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::string word;
    char ch2ch;

    std::ifstream file(filename);

    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }

    while (!file.eof()) {
        int ch = file.get();
        ch2ch = static_cast<char>(ch);

        if (ch >= 'A' && ch <= 'z') {
            if (ch >= 'a' && ch <= 'z') {
                ch2ch += 'a' - 'A';
            }
            word += ch2ch;
        } else if (!word.empty()) {
            tree.add(word);
            word = "";
        }
    }

    file.close();

    return tree;
}
