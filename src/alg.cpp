// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::string word;

    std::ifstream file(filename);

    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }

    while (!file.eof()) {
        char ch = file.get();

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += 'a' - 'A';
            }
            word += ch;
        } else if (!word.empty()) {
            tree.add(word);
            word = "";
        }
    }

    file.close();

    return tree;
}
