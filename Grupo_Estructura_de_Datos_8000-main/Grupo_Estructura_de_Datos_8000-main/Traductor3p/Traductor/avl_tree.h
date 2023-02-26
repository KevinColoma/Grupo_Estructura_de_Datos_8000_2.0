#pragma once
#include "avl_node.h"
#include <string>
#include <functional>
#include <stack>
#include <algorithm>
#include "trunk.h"


class Trunk;
class AvlNode;

class AvlTree
{
public:
    AvlTree() = default;
    /////////////////////////////////////////////////////////////////////
    inline void insert(std::string spanish_word, std::string english_word);
    inline void remove(std::string);
    inline bool has(std::string);
    inline std::vector<AvlNode*> find(std::string word);
    inline void modify(std::string, std::string);
    /////////////////////////////////////////////////////////////////////
    inline void for_each_inorder(std::function<void(AvlNode*)>);
    inline void for_each_preorder(std::function<void(AvlNode*)>);
    inline void for_each_postorder(std::function<void(AvlNode*)>);
    /////////////////////////////////////////////////////////////////////
    inline void print_tree(AvlNode*, Trunk*, bool, int);
    inline void show_trunks(Trunk* p);
    /////////////////////////////////////////////////////////////////////
    // *AVL Tree rotations fuctions
    inline AvlNode* rotate_left(AvlNode*);
    inline AvlNode* rotate_right(AvlNode*);
    /////////////////////////////////////////////////////////////////////
    inline int max_height(int a, int b);
    inline int find_height(AvlNode*);
    inline int balance_factor(AvlNode*);
    inline AvlNode* max_value_node(AvlNode*);
    inline std::string infer_language(std::string);
    inline void to_lower_case(std::string&);
    ////////////////////////////////////////////////////////////////////
    inline int get_size() { return size; };
    inline AvlNode* get_root() { return root; };

private:
    AvlNode* insertAvl(AvlNode*, std::string, std::string);
    AvlNode* deleteAvl(AvlNode*, std::string);
    ////////////////////////////////////////////////////////////////////
    AvlNode* root = nullptr;
    int size = 0;
};

////////////////////////////////////////////////////////////////////////////
// Function: insert
// Purpose: Inserts a word into the tree
// Input: spanish_word - the spanish word to insert
//        english_word - the english word to insert
// Output: None
// Remarks: None
//

inline void AvlTree::insert(std::string spanish_word, std::string english_word)
{
    to_lower_case(english_word);
    to_lower_case(spanish_word);
    root = insertAvl(root, spanish_word, english_word);
}

inline void AvlTree::remove(std::string word)
{
    if (has(word))
    {
        word = infer_language(word);
        to_lower_case(word);
        root = deleteAvl(root, word);
    }
}

inline bool AvlTree::has(std::string word)
{
    return find(word) != std::vector<AvlNode*>{};
}

inline std::vector<AvlNode*> AvlTree::find(std::string word)
{
    if (root == nullptr)
    {
        return std::vector<AvlNode*>{};
    }
    to_lower_case(word);
    std::vector<AvlNode*> temp;
    for_each_inorder([&](AvlNode* node)
        {
            if (node->english_word() == word ||
            node->spanish_word() == word)
            {
                temp.push_back(node);
            }
        });
    return temp;
}

inline void AvlTree::modify(std::string word, std::string new_word)
{
    if (root)
    {
        to_lower_case(word);
        to_lower_case(new_word);
        root = deleteAvl(root, word);
        root = insertAvl(root, new_word, new_word);
    }
    else
    {
        std::cout << "La palabra \"" << word << "\" no se encuentra en el diccionario." << std::endl;
    }
}

inline AvlNode* AvlTree::insertAvl(AvlNode* current, std::string spanish_word, std::string english_word)
{
    if (current == nullptr)
    {
        size++;
        return new AvlNode(english_word, spanish_word);
    }

    if (english_word < current->english_word())
    {
        current->set_left(insertAvl(current->left(), spanish_word, english_word));
    }
    else if (english_word >= current->english_word())
    {
        current->set_right(insertAvl(current->right(), spanish_word, english_word));
    }

    current->set_height(max_height(find_height(current->left()), find_height(current->right())) + 1);

    //* Obtiene el nuevo factor de equilibrio
    int bf = balance_factor(current);

    //* Rotacion simple a la derecha
    if (bf > 1 && english_word < current->left()->english_word())
    {
        return rotate_right(current);
    }

    //* Rotacion simple a la izquierda
    if (bf < -1 && english_word > current->right()->english_word())
    {
        return rotate_left(current);
    }

    //* Rotacion izquierda derecha
    if (bf > 1 && english_word > current->left()->english_word())
    {
        current->set_left(rotate_left(current->left()));
        return rotate_right(current);
    }

    //* Rotacion derecha izquierda
    if (bf < -1 && english_word < current->right()->english_word())
    {
        current->set_right(rotate_right(current->right()));
        return rotate_left(current);
    }
    return current;
}

inline AvlNode* AvlTree::deleteAvl(AvlNode* current, std::string word)
{
    if (current == nullptr)
    {
        return current;
    }
    if (word < current->english_word())
    {
        current->set_left(deleteAvl(current->left(), word));
    }
    else if (word > current->english_word())
    {
        current->set_right(deleteAvl(current->right(), word));
    }
    else
    {
        if ((current->left() == nullptr) || (current->right() == nullptr))
        {
            AvlNode* temp = nullptr;

            if (temp == current->left())
            {
                temp = current->right();
            }
            else
            {
                temp = current->left();
            }

            //* Si no hay hijos, se elimina el nodo
            if (temp == nullptr)
            {
                current = nullptr;
                size--;
            }
            else
            {
                current = temp;
            }
        }
        else
        {
            //* Si hay hijos, se busca el nodo más alto
            AvlNode* temp = max_value_node(current->left());

            //* Se asigna el valor del nodo más alto a la raiz
            current->set_english_word(temp->english_word());
            current->set_spanish_word(temp->spanish_word());

            current->set_left(deleteAvl(current->left(), temp->english_word()));
        }
    }

    if (current == nullptr)
    {
        return { current };
    }

    current->set_height(max_height(find_height(current->left()), find_height(current->right())) + 1);

    //* Obtiene el nuevo factor de equilibrio
    int bf = balance_factor(current);
    //* Rotacion simple a la derecha
    if (bf > 1 && balance_factor(current->left()) >= 0)
    {
        return rotate_right(current);
    }

    //* Rotacion simple a la izquierda
    if (bf < -1 && balance_factor(current->right()) <= 0)
    {
        return rotate_left(current);
    }
    //* Rotacion izquierda derecha
    if (bf > 1 && balance_factor(current->left()) < 0)
    {
        current->set_left(rotate_left(current->left()));
        return rotate_right(current);
    }
    //* Rotacion derecha izquierda
    if (bf < -1 && balance_factor(current->right()) > 0)
    {
        current->set_right(rotate_right(current->right()));
        return rotate_left(current);
    }

    return current;
}

/////////////////////////////////////////////////////////////////////////////

inline void AvlTree::for_each_inorder(std::function<void(AvlNode*)> callback)
{

    if (root == nullptr)
    {
        return;
    }
    std::stack<AvlNode*> stack;
    AvlNode* current = root;
    while (!stack.empty() || current != nullptr)
    {
        if (current != nullptr)
        {
            stack.push(current);
            current = current->left();
        }
        else
        {
            current = stack.top();
            stack.pop();
            callback(current);
            current = current->right();
        }
    }
}

inline void AvlTree::for_each_preorder(std::function<void(AvlNode*)> callback)
{


    if (root == nullptr)
    {
        return;
    }
    std::stack<AvlNode*> stack;
    stack.push(root);
    while (!stack.empty())
    {
        AvlNode* current = stack.top();
        stack.pop();
        callback(current);
        if (current->right() != nullptr)
        {
            stack.push(current->right());
        }
        if (current->left() != nullptr)
        {
            stack.push(current->left());
        }
    }
}

inline void AvlTree::for_each_postorder(std::function<void(AvlNode*)> callback)
{
     if (root == nullptr)
    {
        return;
    }
    std::stack<AvlNode*> stack;
    stack.push(root);
    std::stack<AvlNode*> postorder;
    while (!stack.empty())
    {
        AvlNode* current = stack.top();
        stack.pop();
        postorder.push(current);
        if (current->left() != nullptr)
        {
            stack.push(current->left());
        }
        if (current->right() != nullptr)
        {
            stack.push(current->right());
        }
    }
    while (!postorder.empty())
    {
        callback(postorder.top());
        postorder.pop();
    }
}
////////////////////////////////////////////
inline void AvlTree::print_tree(AvlNode* current, Trunk* prev, bool isLeft, int language)
{
    if (current == nullptr)
    {
        return;
    }

    std::string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    print_tree(current->right(), trunk, true, language);

    if (!prev)
    {
        trunk->str = "----";
    }
    else if (isLeft)
    {
        trunk->str = ".----";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`----";
        prev->str = prev_str;
    }

    show_trunks(trunk);
    if (language == 1)
    {
        //rgb(224, 86, 253)
        printf("\033[%d;2;%d;%d;%dm%s\033[0;00m", 38, 224, 86, 253, current->english_word().c_str());
        std::cout << std::endl;
    }
    if (language == 2)
    {
        //rgb(24, 220, 255)
        printf("\033[%d;2;%d;%d;%dm%s\033[0;00m", 38, 24, 220, 255, current->spanish_word().c_str());
        std::cout << std::endl;
    }

    if (prev)
    {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    print_tree(current->left(), trunk, false, language);
}

inline void AvlTree::show_trunks(Trunk* p)
{
    if (p == nullptr)
    {
        return;
    }

    show_trunks(p->prev);
    //rgb(250, 130, 49)
    printf("\033[%d;2;%d;%d;%dm%s\033[0;00m", 38, 255, 255, 255, p->str.c_str());
}
///////////////////////////////////////////////////////////////////////////////

inline AvlNode* AvlTree::rotate_left(AvlNode* node)
{
    AvlNode* current = node->right();
    AvlNode* temp = current->left();
    current->set_left(node);
    node->set_right(temp);

    node->set_height(max_height(find_height(node->left()), find_height(node->right())) + 1);
    current->set_height(max_height(find_height(current->left()), find_height(current->right())) + 1);

    return current;
}

inline AvlNode* AvlTree::rotate_right(AvlNode* current)
{
    //* Construct simple rotation to the right
    //*       y                                              x
    //*      / \                                            / \
    //*     x   c                                          a   y
    //*    / \                                            / \
    //*   a   b                                          b   c
    //*

    AvlNode* new_root = current->left();
    AvlNode* temp = new_root->right();

    //* Se realiza la rotacion
    new_root->set_right(current);
    current->set_left(temp);

    //* Se actualiza las alturas
    current->set_height(max_height(find_height(current->left()), find_height(current->right())) + 1);
    new_root->set_height(max_height(find_height(new_root->left()), find_height(new_root->right())) + 1);
    return new_root;
}

///////////////////////////////////////////////////////////////////////////////

inline int AvlTree::max_height(int a, int b)
{
    return (a > b) ? a : b;
}

inline int AvlTree::find_height(AvlNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height();
}

inline int AvlTree::balance_factor(AvlNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return find_height(node->left()) - find_height(node->right());
}

inline AvlNode* AvlTree::max_value_node(AvlNode* node)
{
    AvlNode* max = node;
    while (max->right() != nullptr)
    {
        max = max->right();
    }
    return max;
}

inline std::string AvlTree::infer_language(std::string word)
{
    std::string language;
    for_each_inorder([&](AvlNode* node)
        {
            if ((node->english_word() == word) ||
            (node->spanish_word() == word))
            {
                language = node->english_word();
            }
        });
    return language;
}

inline void AvlTree::to_lower_case(std::string& word)
{
    std::transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c)
        { return std::tolower(c); });
}
