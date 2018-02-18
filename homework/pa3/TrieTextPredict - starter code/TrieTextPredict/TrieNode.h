#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <vector>
#include <cctype>
using namespace std;

class TrieNode
{
private:
    char _data;
    vector<TrieNode*> _children;

	//For our Trie, we are using the character '$' as a sentinel
	//value to mark the end of a word.  It exists at index 26,
	//which is immediately after the character 'Z'.
    static const int sentinel_index = 26;

	//Nice helper function to convert a char (upper or lower)
	//into a valid index for our Trie.
    int charToIndex(const int &ch) const
    {
        //account for sentinel
        if (ch == '$')
        {
            return sentinel_index;
        }

        //start char 'A' at index 0
        int index = toupper(ch) - 65;
        return index;
    }

public:
    TrieNode(const char &data = '\0')
    {
        setValue(data);
        _children.resize(27);
        for (int i = 0; i < 27; i++)
        {
            _children[i] = nullptr;
        }
    }

    void setValue(const char &data)
    {
        _data = toupper(data);
    }

    const char& getValue() const
    {
        return _data;
    }

    char& getValue()
    {
        return _data;
    }

	//Returns true if the current Trie node represents the end of
	//a word.
    bool isWord() const
    {
        return _children[sentinel_index] != nullptr;
    }

	//Returns true when the current Trie node has the value of 
	//the sentiel node
    bool isSentinel() const
    {
        return _data == '$';
    }

	//returns true when the Trie node has at least one child
    bool hasChild(const char &index) const
    {
        return _children[charToIndex(index)] != nullptr;
    }

    void setChild(const char &index, TrieNode *node)
    {
        int i = charToIndex(index);   
        _children[i] = node;
    }

    TrieNode* getChild(const char &index)
    {
        return _children[charToIndex(index)];
    }

	//returns a list of children.  Null nodes are not included
	//in the list.
	vector<TrieNode*> getChildren()
	{
		vector<TrieNode*> children{};
		for (auto node : _children)
		{
			if (node != nullptr)
			{
				children.push_back(node);
			}
		}
        return children;
    }

};

#endif // !TRIE_NODE_H
