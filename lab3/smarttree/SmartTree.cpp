//
// Created by Piotrek on 19.03.2017.
//

#include <ostream>
#include <memory>
#include <iostream>
#include "SmartTree.h"


using std::unique_ptr;
using std::make_unique;
using std::string;

namespace datastructures {
    unique_ptr<SmartTree> CreateLeaf(int value) {
        unique_ptr<SmartTree> leaf = make_unique<SmartTree>();
        leaf->left = nullptr;
        leaf->right = nullptr;
        leaf->value = value;
        return leaf;
    }

    unique_ptr<SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree) {
        while (tree->left != nullptr)
            tree = move(tree->left);
        tree->left = move(left_subtree);
        return tree;
    }

    unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree) {
        while (tree->right != nullptr)
            tree = move(tree->right);
        tree->right = move(right_subtree);
        return tree;
    }


    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr->left != nullptr)
            PrintTreeInOrder(unique_ptr->left, out);
        *out << unique_ptr->value << ", ";
        if (unique_ptr->right != nullptr)
            PrintTreeInOrder(unique_ptr->right, out);
    }

    string DumpTree(const unique_ptr<SmartTree> &tree) {
        if (tree == nullptr)
            return "[none]";
        string retStr = "[";
        retStr += std::to_string(tree->value);
        retStr += " " + DumpTree(tree->left);
        retStr += " " + DumpTree(tree->right);
        retStr += "]";
        //std::cout << retStr << std::endl;
        return retStr;
    }

    unique_ptr<SmartTree> RestoreTree(const string &tree) {

    }
}
