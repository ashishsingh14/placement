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
    if(root)
    inorderhelper(root);
}

void BST::preorderhelper(Node * node)
{
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorderhelper(node->left);
    preorderhelper(node->right);

}

void BST::preorder()
{
    if(root)
    preorderhelper(root);
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


void BST::childrensum()
{
    if(root)
        childrensumhelper(root);
}

void BST::childrensumhelper(Node * root)
{
   int a = 0, b = 0;
   int diff;
   if((root->left==NULL && root->right==NULL) || root==NULL)
       return;
   else
   {

       childrensumhelper(root->left);
       childrensumhelper(root->right);

       if(root->left)
            a = root->left->data;
       if(root->right)
            b = root->right->data;
       diff = (a + b) - root->data;
       if(diff>=0)
           root->data = root->data + diff;
       if(diff<0)
           increment(root, -diff);
   }
}

void BST::increment(Node *root, int diff)
{
    if(root->left!=NULL)
    {
        root->left->data = root->left->data + diff;
        increment(root->left, diff);
    }
    else if(root->right!=NULL)
    {
        root->right->data = root->right->data + diff;
        increment(root->right, diff);
    }
}

Node* BST::newnode(int a)
{
    Node * n = new Node();
    n->data = a;
    n->left = NULL;
    n->right = NULL;
    cout<<"inserted data "<<n->data<<endl;
    return n;
}

void BST::createrandom()
{
    root = newnode(50);
    root->left = newnode(7);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(1);
    root->right->right = newnode(30);
}


Node* BST::treefrompostin(int post[],int in[], int start, int end)
{
    if(start>end)
        return NULL;
    static int i = end;
    Node * n = newnode(post[i--]);
    if(start==end)
        return n;
    int j = searchin(in, n->data,start,end);
    n->right = treefrompostin(post, in, j+1, end);
    n->left = treefrompostin(post, in, start, j-1);
    return n;
}


Node* BST::treefromprein(int pre[], int in[], int start, int end)
{
    if(start>end)
        return NULL;
    static int i = 0;
    Node * n = newnode(pre[i++]);
    if(start==end)
        return n;
    int j = searchin(in, n->data,start,end);
    n->left = treefromprein(pre, in, start, j-1);
    n->right = treefromprein(pre, in, j+1, end);
    return n;
}

int BST::searchin(int *in, int d, int start, int end)
{
    for(int j = start;j<=end;j++)
    {
        if(in[j]==d)
        {
            return j;
            break;
        }
    }
}


Node* BST::constructtreeFromInAndPostTraversals(int inorder[],int postorder[],int startIndx,int endIndx){
    static int postIndx=5;
    if(startIndx>endIndx){
        return NULL;
    }
    Node* tNode=newnode(postorder[postIndx--]);
    if(startIndx==endIndx){
        return tNode;
    }
    int inIndx=searchin(inorder,tNode->data,startIndx,endIndx);

    tNode->right=constructtreeFromInAndPostTraversals(inorder,postorder,inIndx+1,endIndx);
    tNode->left=constructtreeFromInAndPostTraversals(inorder,postorder,startIndx,inIndx-1);
    return tNode;
}


void BST::buildtree()
{
    int in[6]={4,2,5,1,6,3};
    int pre[6]={1,2,4,5,3,6};
    int post[6] = {4,5,2,6,3,1};
    //root = treefromprein(pre,in,0,5);
    //root = treefrompostin(post,in,0,5);
    root = constructtreeFromInAndPostTraversals(in,post,0,5);
    preorder();
    //printlevelorder();
}

