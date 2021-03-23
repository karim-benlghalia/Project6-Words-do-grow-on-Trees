# README #

In this assignment, we are to write a program that analyzes a selection of text, counting the number of times each word appears in the text. Our word counts must ignore capitalization, so the, The, THE, and tHe all increase the count for the word “the” by one. For purposes of this assignment, a word is any consecutive string of letters and the apostrophe character, so don’t counts as a single word, and best-selling counts as two words: best and selling. Notice that a blank space will not necessarily occur between two words.

We must store the words and the counts of the words in a single binary search tree. Each word occurring in the text can only be stored once in the tree. Call the structure for the nodes of the tree WordNode, and call the pointers in this structure left and right. Use C++ strings to store words in the tree. Call the class implementing the binary search tree WordTree.

### The assignment contains the following public functions: ###


* Destructor and default constructor
* Add: adds the given word to the tree if it is not already in the tree OR increments the appropriate counter if it is already there. It returns nothing.
* CountNodes: returns the number of words currently stored in the tree.
* Output operator << : prints the words of the tree in alphabetical order, and next to each word, prints the number of times each word occurs in the text.

* The destructor, output operator, and public member functions Add and CountNodes must each be implemented in terms of a recursive private member function. Three of these operations (all but Add) must visit every node in the tree. One of these must use preorder traversal, one must use inorder traversal, and one must use postorder traversal. You must decide which method to use for each function, but use comments to document the type of traversal used. Also, use const wherever it is appropriate.

* Write the definition for the constructor for WordNode inside the structure definition in the header file, and do the same for the constructor for WordTree. Use initialization lists in these constructors.

* The WordTree class may have only one member variable, root, and it must be private. It contains the address of the root node of the tree.

* The header file should be called wordtree.h, and the definitions for member functions must be in file wordtree.cpp. You must use the main function words.cpp. You must finish writing this file and create the other two files yourself.

