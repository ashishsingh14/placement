#include "functions.h"

class Something
{
public:
    static int s_nValue;
};

int Something::s_nValue;


void calling1()
{
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    g.countislands();
    //cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    //g.bfs(2);
    cout<<"dfs is\n";

}

//void method_c(int m, int n, int arr[m][n]) // cannot write arr[][5]
//{
//    int i, j;
//    for (i = 0; i < m; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            arr[i][j] = j + 3;
//        }
//    }
//}

void calling2()
{
//    Graph g(2);
//    if(g.unionfind())
//        cout<<"There is a cycle\n";
//    else
//        cout<<"No cycle\n";

}

int main()
{
    //calling1();
//    int m = 2;
//    int n =4;
//    int arr[m][n];

//    int i;
//    int j;
//    for(i = 0; i < 2; i++) {
//        for(j = 0; j < 4; j++) {
//            arr[i][j] = j;
//        }
//    }
    Something::s_nValue = 2;
    std::cout << Something::s_nValue;
    return 0;


}

