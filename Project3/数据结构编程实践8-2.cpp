#include<map>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include <fstream>

using namespace std;
typedef char InfoType;
typedef char ElemType;
#define MAXV 100                //最大顶点个数
#define MaxSize 500
#define INF 1000              //定义∞
int visited[MAXV];				//访问数组 
map<char, int> mp;
char s[MAXV][MAXV];
void mune()
{
    cout << "=====请选择输入方式=====" << endl;
    cout << "1.文件输入1" << endl;
    cout << "2.文件输入2" << endl;
    cout << "3.文件输入3" << endl;
    cout << "4.手动输入" << endl;
    cout << "========================" << endl;

}
//返回元素文件的个数
int shu1()
{
    int shu, j;
    ifstream f;//定义读取文件流 f
    f.open("input1.txt");//以输入方式打开文件
    for (int i = 0; i < 30; i++) {
        for (j = 0; j < 10000; j++)
        {
            f >> s[i][j];//每读取一个值就写入到二维表中
            if (s[i][j] == NULL)
                break;
        }
        break;
    }
    for (shu = 0; shu < 10000; shu++)
    {
        if (shu * shu == j)
            break;
    }
    return shu;
}
int shu2()
{
    int shu, j;
    ifstream f;//定义读取文件流 f
    f.open("input2.txt");//以输入方式打开文件
    for (int i = 0; i < 30; i++) {
        for (j = 0; j < 10000; j++)
        {
            f >> s[i][j];//每读取一个值就写入到二维表中
            if (s[i][j] == NULL)
                break;
        }
        break;
    }
    for (shu = 0; shu < 10000; shu++)
    {
        if (shu * shu == j)
            break;
    }
    return shu;
}
int shu3()
{
    int shu, j;
    ifstream f;//定义读取文件流 f
    f.open("input3.txt");//以输入方式打开文件
    for (int i = 0; i < 30; i++) {
        for (j = 0; j < 10000; j++)
        {
            f >> s[i][j];//每读取一个值就写入到二维表中
            if (s[i][j] == NULL)
                break;
        }
        break;
    }
    for (shu = 0; shu < 10000; shu++)
    {
        if (shu * shu == j)
            break;
    }
    return shu;
}
//读取文件
void readfile2(int shu)//读取文件
{
    ifstream f;//定义读取文件流 f
    f.open("input2.txt");//以输入方式打开文件
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            f >> s[i][j];//每读取一个值就写入到二维表中
        }
    }
    f.close();//文件关闭
}
void readfile1(int shu)//读取文件
{
    ifstream f;//定义读取文件流 f
    f.open("input1.txt");//以输入方式打开文件
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            f >> s[i][j];//每读取一个值就写入到二维表中
        }
    }
    f.close();//文件关闭
}
void readfile3(int shu)//读取文件
{
    ifstream f;//定义读取文件流 f
    f.open("input3.txt");//以输入方式打开文件
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            f >> s[i][j];//每读取一个值就写入到二维表中
        }
    }
    f.close();//文件关闭
}
void lu(int A[MAXV][MAXV], int shu)
{
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            if (s[i][j] == 'F')
                A[i][j] = INF;
            else
                A[i][j] = s[i][j] - 48;
        }
    }
}
//邻接矩阵声明
typedef struct
{
    int no;                      //顶点编号
    InfoType info;               //顶点其他信息
} VertexType;                    //顶点类型
typedef struct
{
    int edges[MAXV][MAXV];       //邻接矩阵数组
    int n, e;                    //顶点数，边数
    VertexType vexs[MAXV];       //存放顶点信息
} MatGraph;                      //完整的图邻接矩阵类型
//邻接表声明,以下定义邻接表类型
typedef struct ANode
{
    int adjvex;                  //该边的邻接点编号
    struct ANode* nextarc;       //指向下一条边的指针
    int weight;                  //该边的相关信息，如权值（用整型表示）
} ArcNode;                       //边节点类型
typedef struct Vnode
{
    InfoType info;               //顶点其他信息
    ArcNode* firstarc;           //指向第一条边
} VNode;                         //邻接表头节点类型
typedef struct
{
    VNode adjlist[MAXV];         //邻接表头节点数组
    int n, e;                    //图中顶点数n和边数e
} AdjGragh;                      //完整的图邻接表类型
//------------------------------------------------------------
//----邻接矩阵的基本运算算法----------------------------------
//------------------------------------------------------------
//创建邻接矩阵
void CreatrMat(MatGraph& g, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    g.n = n;
    g.e = e;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.e; j++)
            g.edges[i][j] = A[i][j];
}
//输出邻接矩阵g
void DispMat(MatGraph g)
{
    int i, j;
    for (i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.e; j++)
        {
            if (g.edges[i][j] != INF)
                printf("%4d", g.edges[i][j]);
            else
                printf("%4s", "∞");
        }
        cout << endl;
    }
}
//邻接矩阵转换为邻接表
void MatToList(MatGraph g, AdjGragh*& G)
{
    int i, j;
    ArcNode* p;
    
    G = (AdjGragh*)malloc(sizeof(AdjGragh));
    //assert(G);
    for (i = 0; i < g.n; i++)                              //给邻接表中所有头节点的指针域置初值
       
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < g.n; i++)                              //检查邻接矩阵中每个元素
    {
        for (j = g.e - 1; j >= 0; j--)
        {
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)//存在一条边
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));     //创建一个节点p
                //assert(p);
                p->adjvex = j;
                p->weight = g.edges[i][j];
                p->nextarc = G->adjlist[i].firstarc;       //采用头插法插入节点p
                //assert(p);
                G->adjlist[i].firstarc = p;
            }
        }
    }
    //assert(G);
    G->n = g.n;
    G->e = g.e;
}
//输出邻接表G
void DispAdj(AdjGragh* G)
{
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("%3d(%d)→", p->adjvex, p->weight);
            p = p->nextarc;
        }
        cout << endl;
    }
}

//邻接表转换成邻接矩阵
void ListToMat(AdjGragh* G, MatGraph& g)
{
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL)
        {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }
    g.n = G->n;
    g.e = G->e;
}

void DFS(MatGraph g, int v) {
    cout << "正在深度优先遍历第" << v + 1 << "个节点" << endl;
    visited[v] = 1;
    for (int w = 0; w < g.n; ++w) {
        if ((!visited[w]) && (g.edges[v][w] != INF)) {
            DFS(g, w);
        }
    }


}


int FindNotVisit1(MatGraph g, int v) { //寻找第一个未访问的节点
    int i;
    for (i = 0; i < g.n; i++) {
        if (visited[i] == false && g.edges[v][i] != INF) {
            return i;
        }
    }
    return -1;
}

void DFS1(MatGraph g, int v)//用栈函数实现深度查找（邻接矩阵存储方式）
{
    stack<int>stack;
    int w;
    w = v;
    cout << "正在深度优先遍历第" << v + 1 << "个节点" << endl;
    visited[w] = true;
    //找到w的第一个未被访问的邻接顶点，将顶点位置赋给w的位置
    while (FindNotVisit1(g, w) != -1 || stack.empty()) {
        while (FindNotVisit1(g, w) != -1) {
            //找到w的第一个未被访问的邻接顶点
            w = FindNotVisit1(g, w);
            //访问并标记
            cout << "正在深度优先遍历第" << w + 1 << "个节点" << endl;
            visited[w] = true;
            //入栈
            stack.push(w);
        }
        if (stack.empty()) {//栈不为空
            //出栈
            stack.pop();
            //找顶点的第一个未被访问的邻接顶点
            w = FindNotVisit1(g, w);
        }
    }

}

int FindNotVisit2(AdjGragh* G, int v) { //寻找第一个未访问的节点
    ArcNode* p;
    p = G->adjlist[v].firstarc;
    while (p != NULL)
    {
        if (visited[p->adjvex] == false)
        {
            return p->adjvex;
        }
        p = p->nextarc;
    }
    return -1;
}

void DFS2(AdjGragh* G, int v)//邻接表存储方式
{
    stack<int>st;
    int w = v;
    visited[v] = 1;
    cout << "正在深度优先遍历第" << v + 1 << "个节点" << endl;
    st.push(v);
    while (FindNotVisit2(G, w) != -1 || st.empty())
    {
        while (FindNotVisit2(G, w) != -1) {
            //找到w的第一个未被访问的邻接顶点
            w = FindNotVisit2(G, w);
            //访问并标记
            cout << "正在深度优先遍历第" << w + 1 << "个节点" << endl;
            visited[w] = true;
            //入栈
            st.push(w);
        }
        if (st.empty()) {//栈不为空
            //出栈
            st.pop();
            //找顶点的第一个未被访问的邻接顶点
            w = FindNotVisit2(G, w);
        }

    }

}

void BFS(MatGraph g, int v) {//邻接矩阵实现广度遍历
    cout << "正在广度优先遍历第" << v + 1 << "个节点" << endl;
    visited[v] = 1;
    queue<int> Q; 	//STL
    Q.push(v);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int w = 0; w < g.n; ++w) {//点数
            if ((!visited[w]) && (g.edges[u][w] != INF)) {//访问数组和权值
                cout << "正在广度优先遍历第" << w + 1 << "个节点" << endl;
                visited[w] = 1;
                Q.push(w);
            }
        }
    }

}

void BFS1(AdjGragh* G, int v)//临界表实现广度遍历
{
    queue<int>SQ;                      //定义队列SQ
    int w;
    ArcNode* p;
    cout << "正在广度优先遍历第" << v + 1 << "个节点" << endl;
    visited[v] = 1;                    //设置已访问标记
    SQ.push(v);
    while (!SQ.empty())              //队不为空时循环
    {
        w = SQ.front();
        SQ.pop();                     //出队第一个顶点W
        p = G->adjlist[w].firstarc;   //指向W的第一个邻接点
        while (p != NULL)              //查找W的所有邻接点
        {
            if (visited[p->adjvex] == 0)  //若当前邻接点未被访问
            {
                cout << "正在广度优先遍历第" << p->adjvex + 1 << "个节点" << endl;   //访问该邻接点
                visited[p->adjvex] = 1;         //设置已访问标记
                SQ.push(p->adjvex);             //该顶点进队
            }
            p = p->nextarc;                    //找下一个邻接点
        }
    }
    printf("\n");
}

//销毁图的邻接表
void DestroyAdj(AdjGragh*& G)
{
    for (int i = 0; i < G->n; ++i)		//扫描所有的单链表
    {
        //共性要求二，对邻接表的销毁函数进行优化。
        ArcNode* pre = G->adjlist[i].firstarc;	//p指向第i个单链表的首节点
        while (pre != NULL)			//释放第i个单链表的所有边节点
        {
            ArcNode* p = pre;
            pre = pre->nextarc;
            free(p);
        }
    }
    free(G);						//释放头节点数组
    printf("销毁成功\n");
}

//主函数

int main()
{
kai: mune();
    AdjGragh* G = nullptr;
    MatGraph g;
    int A[MAXV][MAXV], x, chu;
    int n, e;
    scanf_s("%d", &x);
    switch (x)
    {
    case 1:
        readfile1(shu1());
        lu(A, shu1());
        n = shu1(), e = shu1();
        break;
    case 2:
        readfile2(shu2());
        lu(A, shu2());
        n = shu2(), e = shu2();
        break;
    case 3:
        readfile3(shu3());
        lu(A, shu3());
        n = shu3(), e = shu3();
        break;
    case 4:
        printf("输入顶点数：");
        scanf_s("%d", &n);
        e = n;
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                printf("请输入第%d行第%d列的元素：", i1, i2);
                cin >> s[i1][i2];
            }
        }
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                printf("%c ", s[i1][i2]);
            }
            printf("\n");
        }
        lu(A, n);
    default:
        n = 0;
        e = 0;
        break;
    }
   
    CreatrMat(g, A, n, e);
    printf("图G的邻接表：\n");
    MatToList(g, G);
    DispAdj(G);
    printf("\n");
    printf("图G的邻接矩阵：\n");
    DispMat(g);
    printf("\n");
    printf("从顶点0开始的DFS(递归算法):\n");
    DFS(g, 0); printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("从顶点0开始的DFS(栈函数，非递归算法,邻接矩阵的存储方式):\n");
    DFS1(g, 0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("从顶点0开始的DFS(栈函数，非递归算法,邻接表的存储方式):\n");
    DFS2(G, 0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("从顶点0开始的BFS(邻接矩阵的存储方式):\n");
    BFS(g, 0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("从顶点0开始的BFS(邻接表的存储方式):\n");
    BFS1(G, 0);
    printf("\n");
    printf("销毁邻接表\n");
    DestroyAdj(G);
    while (1)
    {
        printf("输入‘0’退出，输入‘1’重新选择案例:");
        scanf_s("%d", &chu);
        switch (chu)
        {
        case 1:
            goto kai;
            break;
        case 2:
            break;
        }
        break;
    }
   
    return 1;
}