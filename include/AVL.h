#ifndef AVL_H
#define AVL_H
#include <string>
#include "Persona.h"
using namespace std;
class NodeAVL{
	public:
		Persona * key;
		NodeAVL *left;
		NodeAVL *right;
		int height;
		string generateGraphviz();

};
class AVL
{
	public:
		AVL();
		NodeAVL * getRoot();
		NodeAVL * newNode(Persona *);
		int nodeHeight(NodeAVL *);
		int maxKey(int, int);
		int checkBalance(NodeAVL *);
		NodeAVL * leftRotateTree(NodeAVL *);
		NodeAVL * rightRotateTree(NodeAVL *);
		NodeAVL * rightLeftRotateTree(NodeAVL *);
		NodeAVL * leftRightRotateTree(NodeAVL *);
		NodeAVL * Insert(NodeAVL *,Persona *);
		NodeAVL * Delete(NodeAVL *, Persona *);
		bool _search(NodeAVL *,Persona *);
		void RUpdate(int,int);
		void RDelete(int);
		void RSearch(int);
		void getInsert(int);
		void Report(NodeAVL *);
		void inOrder(NodeAVL *);
		void inPost(NodeAVL *);
		void inPre(NodeAVL *);

		~AVL();


	private:
		NodeAVL * root;

};

#endif // AVL_H
