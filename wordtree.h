#ifndef WORDTREE_H
#define WORDTREE_H
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct WordNode {
	std::string word;
	int WordTracker;
	WordNode* left;
	WordNode* right;
	WordNode(std::string value){
		word = value;
		WordTracker = 1;
		left = nullptr;
		right = nullptr;
	}
};

class WordTree {
private:
	WordNode* root;
	void Insert(WordNode*& nodeptr, string item);
	int sizeOfNodes(WordNode* nodeptr) const;
	int NumberWord(WordNode* nodeptr) const;
	void PrintTree(WordNode* nodeptr, std::ostream&out);
	void deleteNodes(WordNode*nodeptr);
public:
	WordTree(){root = nullptr;}
	~WordTree();
	void add(std::ifstream&inp);
	int CountNodes() const;
	int countTotal() const;
	void printS(std::ostream&out);
	
	friend ostream& operator<<(ostream& os, WordTree& WT);
	

};
#endif