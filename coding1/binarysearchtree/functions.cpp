
/*
 * functions.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: ashissi3
 */
#include "functions.h"

BST::BST()
{
    root = NULL;
}

void BST::inserthelper(Node * a, int data)
{

    if(data <= (a->data))
        {
            if(a->left)
                inserthelper(a->left, data);
            else
            {
                a->left= new Node();
                a->left->data = data;
                a->left->left = NULL;
                a->left->right = NULL;
            }

        }
    else
    {
        if(a->right)
            inserthelper(a->right, data);
        else
        {
            a->right= new Node();
            a->right->data = data;
            a->right->left = NULL;
            a->right->right = NULL;
        }
    }

}

void BST::insert(int data)
{
    if(root==NULL)
        {
            Node * n = new Node();
            n->left = NULL;
            n->right = NULL;
            n->data = data;
            root = n;
        }
    else
    inserthelper(root, data);
}

void BST::inorderhelper(Node * node)
{
    if(node==NULL)
        return;

    inorderhelper(node->left);
    cout<<node->data<<" ";
    inorderhelper(node->right);

}

void BST::inorder()
{
    inorderhelper(root);
}



void BST::insertHelper(Node **node,int data)
{

    if(*node == NULL)
    {
        *node = new Node();
        (*node) -> data = data;
        (*node) -> left = NULL;
        (*node) -> right = NULL;
    }

    else if(data < (*node) -> data)
    {
        insertHelper(&((*node) -> left) ,data);

    }

    else

        insertHelper(&((*node) -> right) ,data);

}


void BST::Insert(int data)
{
    insertHelper(&root,data);
}


int BST::hasPathSum(int sum){
    return hasPathSumHelper(root,sum);

}


int BST::hasPathSumHelper(Node* node,int sum){

    if(node == NULL){
        return (sum == 0);
    }
    if(node->left == NULL && node -> right == NULL){

        return ((sum - (node->data))==0);
    }
    else{

        int subsum = sum - (node ->data);
        cout<<"Subsum"<<subsum<<endl;
        return (hasPathSumHelper(node->left,subsum) || hasPathSumHelper(node -> right,subsum));

    }
}

void BST::printlevelorder()
{
    printlevelorderhelper(root);
}

void BST::printlevelorderhelper(Node*node)
{
    if(node==NULL)
    {
        return;
    }
    else
        cout<<node->data<<endl;
    printlevelorderhelper(node->left);
    printlevelorderhelper(node->right);
}


void BST::printAllPossiblePaths(){
    if(root == NULL){
        cout<<endl<<"Tree empty.No possible paths exist"<<endl;
    }
    else{
        int paths[20];
        printAllPossiblePathsHelper(root,paths,0);
    }
}


void BST::printAllPossiblePathsHelper(Node* node,int paths[],int len){
    if(node == NULL){
        return;
            }
    paths[len++] = node->data;
    printAllPossiblePathsHelper(node->left,paths,len);
    printAllPossiblePathsHelper(node->right,paths,len);
    printPath(paths,len);
}

void BST::printPath(int paths[],int len){
    cout<<endl;
    cout<<"Possible path:"<<endl;
    for(int i=0;i<len;i++){
        cout<<paths[i]<<"->";
    }
    cout<<endl;
}

void BST::deleteBST(){
    if(root == NULL){
        cout<<"tree empty.Nothing to delete"<<endl;
    }
    else{
        deleteBSTHelper(root);

    }

}


void BST::deleteBSTHelper(Node *node){
    if(node == NULL){
        return;
    }
    if(node->left == NULL && node->right ==NULL){
        cout<<"Deleted Node: "<<node->data<<endl;
        delete node;
        node = NULL;
    }
    else{
        if(node -> left){
            deleteBSTHelper(node->left);
            node->left=NULL;
        }
        if(node -> right){
            deleteBSTHelper(node->right);
            node->right=NULL;
                }
        deleteBSTHelper(node);
    }
}

void BST::checkempty()
{

        cout<<"BST is not empty\n";
        cout<<root->data<<endl;
        cout<<root->left->data<<endl;
        cout<<root->right->data<<endl;

}
void BST::BSTdeletesimple()
{
    if(root == NULL){
            cout<<"tree empty.Nothing to delete"<<endl;
        }
        else{
            BSTdeletesimpleHelper(root);

        }

}

void BST::BSTdeletesimpleHelper(Node *node)
{
    if(node->left == NULL && node->right ==NULL){
            cout<<"Deleted Node: "<<node->data<<endl;
            delete node;
            node = NULL;
        }

}


void BST::bstdeletegeeks()
{
    if(root == NULL){
            cout<<"tree empty.Nothing to delete"<<endl;
        }
        else{
            bstdeletegeekshelper(root);

        }
}

void BST::bstdeletegeekshelper(Node *node)
{
    if (node == NULL) return;

        /* first delete both subtrees */
    bstdeletegeekshelper(node->left);
    bstdeletegeekshelper(node->right);

        /* then delete the node */
        printf("\n Deleting node: %d", node->data);
        delete node;
}

void BST::deleteusingdoublehelper(Node ** node)
{
    if (*node == NULL) return;

        /* first delete both subtrees */
    deleteusingdoublehelper(&(*node)->left);
    deleteusingdoublehelper(&(*node)->right);

        /* then delete the node */
        printf("\n Deleting node: %d", (*node)->data);
        delete *node;
        *node = NULL;
}

void BST::deleteusingdouble()
{
    if(root == NULL){
            cout<<"tree empty.Nothing to` delete"<<endl;
        }
        else{
            deleteusingdoublehelper(&root);
        }
}

void BST::voidswap(){
    swappointers(&root->left,&root->right);
}


void BST::swappointers(Node ** a, Node ** b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}


Node* BST::append(Node *a, Node *b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;

    Node * lastofa = a->left;
    Node * lastofb = b->left;
    lastofa->right = b;
    b->left = lastofa;

    lastofb->right = a;
    a->left = lastofb;

    return a;

}

void BST::greattreelist()
{
    Node *head;
    if(root)
        head = greattreelisthelper(root);
    printforgreatlist(head);
}

Node* BST::greattreelisthelper(Node *root)
{
    Node*leftc, *rightc;
    if(root==NULL)
        return NULL;
    leftc = greattreelisthelper(root->left);
    rightc = greattreelisthelper(root->right);
    root->left = root;
    root->right = root;

    leftc = append(leftc, root);
    leftc = append(leftc, rightc);
    return leftc;
}


void BST::printforgreatlist(Node *head)
{
   Node*temp = head;
   cout<<"Converted list is:"<<endl;
   do
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }while(temp!=head);
   cout<<endl;
}

int BST::countleafnodehelper(Node *root)
{
    int count = 0;
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right==NULL)
        return 1;
    count+=countleafnodehelper(root->left);
    count+=countleafnodehelper(root->right);
    return count;
}

void BST::countleafnodes()
{
    cout<<"leaves";
    int c = countleafnodehelper(root);
    cout<<"The total leaf nodes are: "<<c<<endl;
}


void BST::childrensum()
{
    if(root)
        int a = childrensumhelper(root);
}


int BST::childrensumhelper(Node * root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int a = childrensumhelper(root->left);
    int b = childrensumhelper(root->right);

    int diff = root->data - (a+b);
    if(diff>=0)
        root->data = root->data + diff;
    else
        root->data = root->data - diff;
    return root->data;
}

void BST::verticalordermaphelper(Node * root, map<int,vector<int> > &m, int h)
{
    if(root==NULL)
        return;
    verticalordermaphelper(root->left,m,h-1);
    m[h].push_back(root->data);
    verticalordermaphelper(root->right,m,h+1);
}

void BST::verticalordermap()
{
    map<int,vector<int> > m;
    int h = 0;
    if(root)
    {
        verticalordermaphelper(root,m,h);
    }
    for(map<int,vector<int> >::iterator i = m.begin(); i!=m.end();i++)
    {
        cout<<i->first<<":";
        for(int j = 0;j<(i->second.size());j++)
        {
            cout<<i->second[j]<<" ";
        }
        cout<<endl;
    }
}
