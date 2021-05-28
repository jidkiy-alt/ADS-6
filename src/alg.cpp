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
        return;
    }

    while (!file.eof())
    {
        int ch = file.get();

        if (ch >= 'A' && ch <= 'z') {
            if (ch >= 'a' && ch <= 'z') {
                ch + 26;
            }
            word += ch;
        }
        else if (!word.empty()) {
            tree.add(word);
            word = "";
        }
    }

    file.close();

    return tree;
}
