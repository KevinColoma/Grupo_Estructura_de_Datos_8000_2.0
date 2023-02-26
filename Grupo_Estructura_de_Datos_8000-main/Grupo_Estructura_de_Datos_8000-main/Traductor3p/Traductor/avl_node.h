#pragma once
#include <string>

class AvlNode
{
public:
    /**
     * @brief Construct a new Avl Node object
     *
     * @param english_word
     * @param spanish_word
     */
    AvlNode(std::string, std::string);

    /**
     * @brief Construct a new Avl Node object
     *
     * @param english_word
     * @param spanish_word
     * @param height
     */
    AvlNode(std::string, std::string, int);

    /**
     * @brief Construct a new Avl Node object
     *
     * @param english_word
     * @param spanish_word
     * @param height
     * @param left
     * @param right
     */
    AvlNode(std::string, std::string, int, AvlNode*, AvlNode*);


    /**
     * @brief
     *
     * @return AvlNode*
     */
    inline AvlNode* left();

    /**
     * @brief
     *
     * @return AvlNode*
     */
    inline AvlNode* right();

    /**
     * @brief Set the left object
     *
     * @param node
     */
    inline void set_left(AvlNode*);

    /**
     * @brief Set the right object
     *
     * @param node
     */
    void set_right(AvlNode* n);

    /**
     * @brief Set the height object
     *
     * @param height
     */
    inline void set_height(int);

    /**
     * @brief Set the english word object
     *
     * @param english_word
     */
    inline void set_english_word(std::string);

    /**
     * @brief Set the spanish word object
     *
     * @param spanish_word
     */
    inline void set_spanish_word(std::string);

    /**
     * @brief
     *
     * @return int
     */
    inline int height();

    /**
     * @brief
     *
     * @return std::string
     */
    inline std::string english_word();

    /**
     * @brief
     *
     * @return std::string
     */
    inline std::string spanish_word();

private:
    AvlNode* _left = nullptr;
    AvlNode* _right = nullptr;
    std::string _english_word;
    std::string _spanish_word;
    int _height{ 1 };
};

///////////////////////////////////////////////////////////
// Function: AvlNode
// * Purpose: Constructor
// In: std::string value
// Out: -
// Pre: -
// Post: -
//
AvlNode::AvlNode(std::string english_word, std::string spanish_word)
    : _english_word(english_word), _spanish_word(spanish_word), _height(1)
{
}

///////////////////////////////////////////////////////////
// Function: AvlNode
// *Purpose: Constructor
// In: std::string english_word, std::string spanish_word, int height
// Out: -
// Pre: -
// Post: -
//
AvlNode::AvlNode(std::string english_word, std::string spanish_word, int height)
    : _english_word(english_word), _spanish_word(spanish_word), _height(height)
{
}

//////////////////////////////////////////////////////////
// Function: AvlNode
// *Purpose: Constructor
// In: std::string english_word, std::string spanish_word, int height, AvlNode *left, AvlNode *right
// Out: -
// Pre: -
// Post: -
//
AvlNode::AvlNode(std::string english_word, std::string spanish_word, int height, AvlNode* left, AvlNode* right)
    : _english_word(english_word), _spanish_word(spanish_word), _height(height)
{
    _left = left;
    _right = right;
}


///////////////////////////////////////////////////////////
// Function: left
// Purpose: Return the left node
// In: -
// Out: AvlNode *
// Pre: -
// Post: -
//
inline AvlNode* AvlNode::left()
{
    return _left;
}

///////////////////////////////////////////////////////////
// Function: right
// *Purpose: Return the right node
// In: -
// Out: AvlNode *
// Pre: -
// Post: -
//
inline AvlNode* AvlNode::right()
{
    return _right;
}

///////////////////////////////////////////////////////////
// Function: set_left
// *Purpose: Set the left node
// In: AvlNode *node
// Out: -
// Pre: -
// Post: -
//
inline void AvlNode::set_left(AvlNode* node)
{
    _left = node;
}

///////////////////////////////////////////////////////////
// *Function: set_right
// Purpose: Set the right node
// In: AvlNode *node
// Out: -
// Pre: -
// Post: -
//
inline void AvlNode::set_right(AvlNode* node)
{
    _right = node;
}

///////////////////////////////////////////////////////////
// Function: height
// *Purpose: Return the height of the node
// In: -
// Out: int
// Pre: -
// Post: -
//
inline int AvlNode::height()
{
    return _height;
}

///////////////////////////////////////////////////////////
// Function: set_height
// *Purpose: Set the height of the node
// In: int height
// Out: -
// Pre: -
// Post: -
//
inline void AvlNode::set_height(int height)
{
    _height = height;
}

///////////////////////////////////////////////////////////
// Function: english_word
// *Purpose: Return the english word
// In: -
// Out: std::string
// Pre: -
// Post: -
//
inline std::string AvlNode::english_word()
{
    return _english_word;
}

///////////////////////////////////////////////////////////
// Function: spanish_word
// *Purpose: Return the spanish word
// In: -
// Out: std::string
// Pre: -
// Post: -
//
inline std::string AvlNode::spanish_word()
{
    return _spanish_word;
}

///////////////////////////////////////////////////////////
// Function: set_english_word
// *Purpose: Set the english word
// In: std::string english_word
// Out: -
// Pre: -
// Post: -
//
inline void AvlNode::set_english_word(std::string english_word)
{
    _english_word = english_word;
}

///////////////////////////////////////////////////////////
// Function: set_spanish_word
// *Purpose: Set the spanish word
// In: std::string spanish_word
// Out: -
// Pre: -
// Post: -
//
inline void AvlNode::set_spanish_word(std::string spanish_word)
{
    _spanish_word = spanish_word;
}

///////////////////////////////////////////////////////////