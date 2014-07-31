#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

const int num_chars = 26;

class Trie
{
public:
    Trie();
    Trie(Trie& tr);
    virtual ~Trie();
    int trie_search(const char* word,char* entry) const;
    int insert(const char* word,const char* entry);
    int remove(const char* word,char* entry);
protected:
    struct Trie_node
    {
        char* data;  //若不为空，表示从root到此结点构成一个单词
        Trie_node* branch[num_chars]; //分支
        Trie_node(); //构造函数
    };

    Trie_node* root;  //根结点(指针)
};

Trie::Trie_node::Trie_node()
{
    data = NULL;
    for(int i = 0; i < num_chars; ++i)
    {
        branch[i] = NULL;
    }
}

Trie::Trie():root(NULL) 
{

}

Trie::~Trie()
{

}


int Trie::insert(const char* word,const char* entry)
{
    int result = 1,position = 0;
    if(root == NULL)
        root = new Trie_node; //初始插入，根节点为空
    char char_code;
    Trie_node *location = root; //从根节点开始
    while(location != NULL && *word != 0)
    {
        if(*word >= 'A' && *word <= 'Z')
            char_code = *word - 'A';
        else if(*word >= 'a' && *word <= 'z')
            char_code = *word - 'a';
        else
            return 0; // 不合法的单词

        // 不存在此分支
        if(location->branch[char_code] == NULL)
            location->branch[char_code] = new Trie_node; // 创建空分支
        //转入分支
        location = location->branch[char_code];
        position++; 
        word++;
    }
    if(location->data != NULL)
        result = 0; //欲插入的单词已经存在
    else
    {
        //插入数据
        location->data = new char[strlen(entry) + 1]; //分配内存
        strcpy(location->data,entry); //给data赋值表明单词存在
    }
    return result;
}

int Trie::trie_search(const char* word,char* entry) const
{
    int position = 0; //层数
    char char_code;
    Trie_node *location = root; //从根结点开始
    while(location != NULL && *word != 0)
    {
        if(*word >= 'A' && *word <= 'Z')
            char_code = *word - 'A';
        else if(*word >= 'a' && *word <= 'z')
            char_code = *word - 'a';
        else 
            return 0;
        location = location->branch[char_code];
        position++;
        word++;
    }

    // 找到，获取数据，成功返回
    if(location != NULL && location->data != NULL)
    {
        strcpy(entry,location->data);
        return 1;
    }
    else
        return 0; // 不合法的单词
}

int main()
{
    Trie t;
    char entry[100];
    t.insert("a","DET");
    t.insert("abacus","NOUN");
    t.insert("abalone","NOUN");
    t.insert("abandon","VERB");
    t.insert("abate","VERB");
    t.insert("this","PRON");

    if(t.trie_search("this",entry))
        cout<<"'this' was found. pos: "<<entry<<endl;
    if(t.trie_search("abate",entry))
        cout<<"'abate' was found. pos: "<<entry<<endl;
    if(t.trie_search("baby",entry))
        cout<<"'baby' was found .pos: "<<entry<<endl;
    else
        cout<<"'baby' does not exist at all!"<<endl;
    return 0;
}
