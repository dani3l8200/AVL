#include "AVL.h"
#include <string>
#include <cstring>
#include<stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

AVL::AVL()
{
	root = NULL;
}

NodeAVL * AVL::getRoot(){
	return root;
}


NodeAVL* AVL::newNode(Persona * key)
{
    NodeAVL * a = new NodeAVL;
    a->key = key;
    a->left = NULL;
    a->right = NULL;
    a->height=1;
    return a;
}

int AVL::nodeHeight(NodeAVL* a)
{
    return (a == NULL)?0:a->height;
}

int AVL::maxKey(int n,int m)
{
    return (n>m)? n:m;
}

int AVL::checkBalance(NodeAVL* node)
{
    return (node == NULL)?0:nodeHeight(node->left)-nodeHeight(node->right);
}

NodeAVL* AVL::leftRotateTree(NodeAVL* a)
{
    NodeAVL* cur_right = a->right;
    NodeAVL* future_right = cur_right->left;
    // rotate
    cur_right->left =a;
    a->right = future_right;
    a->height=maxKey(nodeHeight(a->left),nodeHeight(a->right))+1;
    cur_right->height = maxKey(nodeHeight(cur_right->left),nodeHeight(cur_right->right))+1;
    return cur_right;
}

NodeAVL * AVL::rightRotateTree( NodeAVL *a)
{
    NodeAVL* cur_left = a->left;
    NodeAVL* future_left = cur_left->right;
    // rotate
    cur_left->right = a;
    a->left = future_left;

    a->height=maxKey(nodeHeight(a->left),nodeHeight(a->right))+1;
    cur_left->height = maxKey(nodeHeight(cur_left->left),nodeHeight(cur_left->right))+1;
    return cur_left;
}

NodeAVL * AVL::rightLeftRotateTree(NodeAVL* a)
{
    a->right = rightRotateTree(a->right);
    return leftRotateTree(a);
}
NodeAVL * AVL::leftRightRotateTree( NodeAVL* a)
{
    a->left = leftRotateTree(a->left);
    return rightRotateTree(a);
}

 NodeAVL * AVL::Insert( NodeAVL* a, Persona * key)
{
    if(a == NULL)
        return newNode(key);
    if(key->getNumbers() < a->key->getNumbers())
        a->left = Insert(a->left,key);
    else if(key->getNumbers() > a->key->getNumbers() )
        a->right = Insert(a->right,key);
    else
        return a;
    // set new height
    int maxH = maxKey(nodeHeight(a->left),nodeHeight(a->right));
    a->height = 1+maxH;

    int balance = checkBalance(a);

    if (balance > 1 && key->getNumbers() < a->left->key->getNumbers())  // left
        return rightRotateTree(a);
    if (balance < -1 && key->getNumbers() > a->right->key->getNumbers())  //right
        return leftRotateTree(a);
    if (balance > 1 && key->getNumbers() > a->left->key->getNumbers())  // left right
        return leftRightRotateTree(a);
    if (balance < -1 && key->getNumbers() < a->right->key->getNumbers())   // right left
        return rightLeftRotateTree(a);

    return a;
}
void AVL::getInsert(int numbers){
	Persona * key = new Persona(numbers);
	root = Insert(root,key);
}
void AVL::inOrder(NodeAVL * p){
   if(p!=nullptr){
		inOrder(p->left);
		cout<<"---->" << p->key->getNumbers() << "<----\n" <<flush;
		inOrder(p->right);
   }
}

NodeAVL * AVL::Delete(NodeAVL * a, Persona * key)
{
    if(a == NULL)
        return a;
    if (key->getNumbers() > a->key->getNumbers())
        a->right = Delete(a->right,key);
    else if(key->getNumbers()  < a->key->getNumbers())
        a->left = Delete(a->left,key);
    else
    {
        if(a->left == NULL)
        {
            NodeAVL * new_node = a->left;
            free(a);
            return new_node;
        }
        else if(a->right == NULL)
        {
            NodeAVL * new_node = a->right;
            free(a);
            return new_node;
        }

        NodeAVL * current = a->right;
         while (current->left != NULL)
            current = current->left;
        //struct Avl* temp = current;

        a->key = current->key;
        a->right = Delete(a->right,current->key);

    }
    if(a == NULL)
        return 0;
    int maxH = maxKey(nodeHeight(a->left),nodeHeight(a->right));
    a->height = 1+maxH;

    int balance = checkBalance(a);


    // rotation conditions
    if (balance > 1 && checkBalance(a->left) >= 0)  // left
        return rightRotateTree(a);
    if (balance < -1 && checkBalance(a->right) <= 0)  //right
        return leftRotateTree(a);
    if (balance > 1 &&  checkBalance(a->left) < 0)  // left right
        return leftRightRotateTree(a);
    if (balance < -1 &&  checkBalance(a->right) > 0)   // right left
        return rightLeftRotateTree(a);

    return a;

}

void AVL::RDelete(int key){
	Persona * temp = new Persona(key);
	root = Delete(root,temp);
}


void AVL::RUpdate(int key_old,int key_new){
	RDelete(key_old);
	getInsert(key_new);
}

bool AVL::_search(NodeAVL * p,Persona * key){
	if(p == nullptr)
		return false;
	if(p->key->getNumbers() == key->getNumbers())
		return true;
	else if(key->getNumbers() > p->key->getNumbers())
		_search(p->right,key);
	else
		_search(p->left,key);

}

void AVL::RSearch(string key){
	Persona * temp = new Persona(key);
	cout<<"Buscando Elemento "<<key<<endl<<endl;
	if(!_search(root,temp)){
		cout<<"Elemento no encontrado\n\n";
	}else{
		cout<<"Elemento encontrado "<<temp->getId() <<"   "<< temp->getDescripcion() <<"  " << temp->getNombre() <<endl<<endl;
	}


}

void AVL::inPost(NodeAVL * a){
	  if(a != NULL){
        inPost(a->left);
        inPost(a->right);
        cout<<"---->" << a->key->getNumbers() << "<----\n" <<flush;
    }
}

void AVL::inPre(NodeAVL * a){
	 if(a != NULL){
		cout<<"---->" << a->key->getNumbers() << "<----\n" <<flush;
        inPost(a->left);
        inPost(a->right);
    }
}

string NodeAVL::generateGraphviz(){
	string part;

	part += "\"" + to_string(key->getNumbers()) + "\" [label=\"" + to_string(key->getNumbers()) + "\"];\n\t";
	if(left != nullptr){
		part += left->generateGraphviz() + "\"" + to_string(key->getNumbers()) + "\" -> \"" + to_string(left->key->getNumbers()) + "\";\n\t";
	}
	if(right != nullptr){
		part += right->generateGraphviz() + "\"" + to_string(key->getNumbers()) + "\" -> \"" + to_string(right->key->getNumbers()) + "\";\n\t";
	}
	part += "\n";
	return part;
}

void AVL::Report(NodeAVL * p){
	string report;
	report += "digraph AVL {\n\t";
	report += "rankdir=L;\n\t nodesep = 0.6;\n\t ranksep =0.4; node [shape = circle,width = 0.4,height=0.6,style=filled, fillcolor=olivedrab1,fixedsize=true];\n\t";
	report += "graph[bgcolor = lemonchiffon1, label=\"Numeros\"];\n\t";
	report += "edge [color=red];\n\t";
	report += root->generateGraphviz();


	report += "}";
	char cstr[report.size() + 1];
	strcpy(cstr, &report[0]);
       FILE* pFile;

		pFile = fopen("avl.dot","w");

		fputs(cstr ,pFile);

		fclose(pFile);

    system("dot -Tjpg avl.dot  -o avl.jpg");
    system("avl.jpg");

}

AVL::~AVL(){

}
