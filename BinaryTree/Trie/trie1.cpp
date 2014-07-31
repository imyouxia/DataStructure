#include <stdio.h>

struct trie_node
{
    static const int letter_count = 26;
    int count;
    bool is_terminal;
    char letter;
    trie_node *childs[letter_count];
    
    trie_node():letter(0),count(1),is_terminal(false)
    {
        for(int i = 0; i < letter_count; ++i)
            childs[i] = NULL;
    }
};

class trie
{
public:
    trie():root_node_(NULL)
    {
    
    }
    ~trie()
    {
        delete_trie(root_node_);
    }    

    trie_node* create()
    {
        trie_node* n = new trie_node();
        return n;
    }

    void insert(const char* str)
    {
        if(!root_node_ || !str)
        {
            root_node_ = create();
        }

        trie_node* next_element_node = root_node_;
        while(*str != 0)
        {
            char element_index = *str - 'a';
            if(!next_element_node->childs[element_index])
            {
                next_element_node->childs[element_index] = create();
            }
            else
            {
                next_element_node->childs[element_index]->count++;
            }
            next_element_node = next_element_node->childs[element_index];
            next_element_node->letter = *str;
            str++;
        }
        next_element_node->is_terminal = true;
    }

    bool find_word_exists(const char* str)
    {
        if(!root_node_ || !str)
            return NULL;
        trie_node* element_node = root_node_;
        do
        {
            element_node = element_node->childs[*str - 'a'];
            if(!element_node)
            {
                return false;
            }
            str++;
        }while(*str != 0);

        return element_node->is_terminal;
    }

    void delete_trie(trie_node* node)
    {
        if(!node)
            return;
        for(int i = 0; i < trie_node::letter_count;i++)
        {
            if(node->childs[i] != NULL)
                delete_trie(node->childs[i]);
        }
        delete node;
    }

private:
    trie_node* root_node_;
};

