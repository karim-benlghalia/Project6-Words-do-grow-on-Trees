#include"wordtree.h"
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void WordTree::add(std::ifstream&inp){
	
	char c;
	string word = "";
	while (inp.peek() != EOF){
		inp.get(c);
		
		if (isalpha(c) || c == '\''){
			
			c = (tolower(c));

			word = word + c;
				}
		else {
			
			if (!word.empty()){
				Insert(root, word);
				word = "";
			}

		}

	}
}

void WordTree::Insert(WordNode*& nodeptr, string item) {

	if (nodeptr == nullptr){
		nodeptr = new WordNode(item);
		return;

	}
	else {
		if (nodeptr->word == item){
			nodeptr->WordTracker += 1;
			return;
		}
		else if (item < nodeptr->word)
			Insert(nodeptr->left, item);

		else
			Insert(nodeptr->right, item);
	}


}


void WordTree::PrintTree(WordNode* nodeptr, std::ostream&out) {

	if (nodeptr == nullptr)
		return;							//in order (left - Current - Right)
	PrintTree(nodeptr->left, out);
	out << nodeptr->word << " " << nodeptr->WordTracker << endl;
	PrintTree(nodeptr->right, out);
}
int WordTree::CountNodes() const{

	return sizeOfNodes(root);

}
int WordTree::sizeOfNodes(WordNode* nodeptr) const{
	if (nodeptr == nullptr)
		return 0;
	else
		return 1 + sizeOfNodes(nodeptr->left) + sizeOfNodes(nodeptr->right);// pre-order (Current - Left - Right)
}
int WordTree::countTotal() const{
	return NumberWord(root);
}
int WordTree::NumberWord(WordNode* nodeptr) const{
	if (nodeptr == nullptr)
		return 0;
	else
		return NumberWord(nodeptr->left) + (nodeptr->WordTracker) + NumberWord(nodeptr->right);
}
WordTree::~WordTree(){

	deleteNodes(root);
}
void WordTree::deleteNodes(WordNode*nodeptr){

	if (nodeptr != nullptr){
		deleteNodes(nodeptr->left);
		deleteNodes(nodeptr->right); // post-order (Left-Right-Current)
		delete nodeptr;
	}


}
ostream& operator<<(ostream& os, WordTree& WT){

	WT.printS(os);
	return os;

}
void WordTree::printS(std::ostream&out){
	PrintTree(root, out);

}
