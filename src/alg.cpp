// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tr;
    std::string sl = "";
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tr;
    }
    while (!file.eof()) {
        char ch = file.get();
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            sl += tolower(ch);
        } else if (sl != "") {
            tr.add(sl);
            sl = "";
        }
    }
    file.close();
    return tr;
}
