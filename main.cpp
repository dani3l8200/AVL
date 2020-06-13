#include<bits/stdc++.h>
#include "AVL.h";
#include "Persona.h"
using namespace std;

int main()
{
     AVL  * s = new AVL();
	  s->getInsert(100);
	  s->getInsert(29);
	  s->getInsert(71);
      s->getInsert(82);
	  s->getInsert(48);
	  s->getInsert(30);
	//   s->getInsert(30);
	s->getInsert(101);
	  s->getInsert(22);
	  s->getInsert(46);
	  s->getInsert(17);
	  s->getInsert(3);
	  s->getInsert(20);
	  s->getInsert(25);

	 cout<<"Elementos in PreOrder\n";
      s->inPre(s->getRoot());
     cout<<endl;
	 cout<<"Elementos in Order\n";
      s->inOrder(s->getRoot());
     cout<<endl;
	 cout<<"Elementos in PostOrder\n";
      s->inPost(s->getRoot());
     cout<<endl;
	  s->RSearch(25);
	 // s->RDelete(25);
	  s->RSearch(25);
	// s->RUpdate(71,59);
	  // s->getInsert(104);
     s->Report( s->getRoot());


      delete s;
    /*int n;
    int val,val_new;
    while(n!=8)
    {
    cout<<"\n 1. INSERT\n 2. SEARCH \n 3. UPDATE \n 4. DELETE \n 5. DISPLAY INORDER \n 6. DISPLAY POREORDER \n 7. DISPLAY POSTORDER\n 8. EXIT\n SELECT OPTION : ";
    cin>>n;
        switch(n)
        {
            case 1: cout <<"Enter item value : ";
                    cin >> val;
					s.getInsert(val);
                    break;
           /* case 2: cout <<"Enter item value : ";
                    cin >> val;
                    //cout << searchN(head,val) ;
                    if(searchN(head,val))
                    {
                        cout <<"FOUND\n";
                    }
                    else
                    {
                        cout <<"NOT FOUND\n";
                    }
                    break;
            case 3: cout <<"Enter item value : ";
                    cin >> val;
                    if(!searchN(head,val))
                    {
                        cout <<"ITEM NOT FOUND\nRetry!!!";
                        break;
                    }
                    cout<<" Enter the updated value : ";
                    cin >> val_new;
                    head = updateN(head,val,val_new);
                    break;
            case 4: cout <<"Enter item value : ";
                    cin >> val;
                    if(!searchN(head,val))
                    {
                        cout <<"ITEM NOT FOUND\nRetry!!!";
                        break;
                    }
                    head = deleteN(head,val);
                    break;
            case 5:
            		cout<<"In Order Traversal : ";
					inOrder(head);
                    break;
            case 6:
					cout<<"Pre Order Traversal : ";
					preOrder(head);
                    break;

            case 7:

					s.Report(s.getRoot());
                    break;
            case 8:
					cout<<"Exiting!!!";
					exit(0);
                    break;
            default: cout << "Select a valid option \n";
        }
    }*/
    return 0;
}
