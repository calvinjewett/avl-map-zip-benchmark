#ifndef NODE_H
#define NODE_H

#include "uscity.h"

template <typename Key, typename Value>
class Node {
public:
    Key key;
    Value data;       
    Node* left;
    Node* right;
    Node* next;
    int height;

    Node(const Key& k, const Value& info)
        : key(k), data(info), left(nullptr), right(nullptr), next(nullptr), height(1) {}
};

#endif
