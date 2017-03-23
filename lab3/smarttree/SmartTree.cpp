//
// Created by Piotrek on 19.03.2017.
//

#include <ostream>
#include <memory>
#include <sstream>
#include <regex>
#include <cmath>
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
        tree->left = move(left_subtree);
        return tree;
    }

    unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree) {
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
        std::stringstream ret;
        ret << "[";
        ret << tree->value;
        ret << " " + DumpTree(tree->left);
        ret << " " + DumpTree(tree->right);
        ret << "]";
        return ret.str();
    }


    std::size_t FindCharInString(string str, char wantedChar, std::size_t startingPos = 0) {
        std::size_t foundPosition = str.find(wantedChar, startingPos);
        if (foundPosition != std::string::npos)
            return foundPosition;
        else
            foundPosition = 1;
        return foundPosition;
    }

    unique_ptr<SmartTree> RestoreTree(const string &tree) {
        if (tree == "[none]")
            return nullptr;
        unique_ptr<SmartTree> root = nullptr;
        std::size_t currentIndex = 0;
        int depth = 0;
        string path = "";
        int depthIterator = 0;
        bool leftNow = true;

        while (currentIndex < tree.length() - 1) {
            std::size_t openingPos = FindCharInString(tree, '[', currentIndex);
            if (openingPos == -1) // done
                break;
            std::size_t closingPos = FindCharInString(tree, ']', currentIndex);
            if (openingPos < closingPos) {
                currentIndex = openingPos + 1;
            } else if (openingPos > closingPos) {
                depthIterator++;
                if (depthIterator == 2) { // 2x none
                    depth--;
                    depthIterator = 0;
                }
                currentIndex = closingPos + 1;
            }

            char chAt = tree.at(currentIndex);
            while (chAt == '[' || chAt == ']' || chAt == ' ') { // rare, skip to next digit/none
                currentIndex++;
                chAt = tree.at(currentIndex);
                if (chAt == ']')
                    depth--;
            }
            std::size_t spacePos = FindCharInString(tree, ' ', currentIndex);
            std::size_t closingPPos = FindCharInString(tree, ']', currentIndex);
            if (closingPPos < spacePos) { // none
                leftNow = false;
                currentIndex += 4;
            } else {
                int wart = stoi(tree.substr(currentIndex, spacePos));
                depth += 1;
                if ((path.length() == 1) && (depth == 1))
                    path = "";
                else
                    path = path.substr(0, depth - 2);
                if (root == nullptr) {
                    root = CreateLeaf(wart);
                    leftNow = true;
                } else {
                    if (leftNow) {
                        if (path.length() > 0) {
                            if (path.at(0) == 'L')
                                root->left = InsertLeftChild(move(root->left), CreateLeaf(wart));
                            else
                                root->right = InsertLeftChild(move(root->right), CreateLeaf(wart));
                        } else
                            root = InsertLeftChild(move(root), CreateLeaf(wart));
                        path += "L";
                    } else {
                        leftNow = true;
                        if (path.length() > 0) {
                            if (path.at(0) == 'L')
                                root->left = InsertRightChild(move(root->left), CreateLeaf(wart));
                            else
                                root->right = InsertRightChild(move(root->right), CreateLeaf(wart));
                        } else
                            root = InsertRightChild(move(root), CreateLeaf(wart));
                        path += "R";
                    }
                }
            }
        }
        return root;
    }
}
