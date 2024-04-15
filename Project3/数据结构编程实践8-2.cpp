#include<map>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include <fstream>

using namespace std;
typedef char InfoType;
typedef char ElemType;
#define MAXV 100                //��󶥵����
#define MaxSize 500
#define INF 1000              //�����
int visited[MAXV];				//�������� 
map<char, int> mp;
char s[MAXV][MAXV];
void mune()
{
    cout << "=====��ѡ�����뷽ʽ=====" << endl;
    cout << "1.�ļ�����1" << endl;
    cout << "2.�ļ�����2" << endl;
    cout << "3.�ļ�����3" << endl;
    cout << "4.�ֶ�����" << endl;
    cout << "========================" << endl;

}
//����Ԫ���ļ��ĸ���
int shu1()
{
    int shu, j;
    ifstream f;//�����ȡ�ļ��� f
    f.open("input1.txt");//�����뷽ʽ���ļ�
    for (int i = 0; i < 30; i++) {
        for (j = 0; j < 10000; j++)
        {
            f >> s[i][j];//ÿ��ȡһ��ֵ��д�뵽��ά����
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
    ifstream f;//�����ȡ�ļ��� f
    f.open("input2.txt");//�����뷽ʽ���ļ�
    for (int i = 0; i < 30; i++) {
        for (j = 0; j < 10000; j++)
        {
            f >> s[i][j];//ÿ��ȡһ��ֵ��д�뵽��ά����
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
    ifstream f;//�����ȡ�ļ��� f
    f.open("input3.txt");//�����뷽ʽ���ļ�
    for (int i = 0; i < 30; i++) {
        for (j = 0; j < 10000; j++)
        {
            f >> s[i][j];//ÿ��ȡһ��ֵ��д�뵽��ά����
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
//��ȡ�ļ�
void readfile2(int shu)//��ȡ�ļ�
{
    ifstream f;//�����ȡ�ļ��� f
    f.open("input2.txt");//�����뷽ʽ���ļ�
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            f >> s[i][j];//ÿ��ȡһ��ֵ��д�뵽��ά����
        }
    }
    f.close();//�ļ��ر�
}
void readfile1(int shu)//��ȡ�ļ�
{
    ifstream f;//�����ȡ�ļ��� f
    f.open("input1.txt");//�����뷽ʽ���ļ�
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            f >> s[i][j];//ÿ��ȡһ��ֵ��д�뵽��ά����
        }
    }
    f.close();//�ļ��ر�
}
void readfile3(int shu)//��ȡ�ļ�
{
    ifstream f;//�����ȡ�ļ��� f
    f.open("input3.txt");//�����뷽ʽ���ļ�
    for (int i = 0; i < shu; i++) {
        for (int j = 0; j < shu; j++)
        {
            f >> s[i][j];//ÿ��ȡһ��ֵ��д�뵽��ά����
        }
    }
    f.close();//�ļ��ر�
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
//�ڽӾ�������
typedef struct
{
    int no;                      //������
    InfoType info;               //����������Ϣ
} VertexType;                    //��������
typedef struct
{
    int edges[MAXV][MAXV];       //�ڽӾ�������
    int n, e;                    //������������
    VertexType vexs[MAXV];       //��Ŷ�����Ϣ
} MatGraph;                      //������ͼ�ڽӾ�������
//�ڽӱ�����,���¶����ڽӱ�����
typedef struct ANode
{
    int adjvex;                  //�ñߵ��ڽӵ���
    struct ANode* nextarc;       //ָ����һ���ߵ�ָ��
    int weight;                  //�ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;                       //�߽ڵ�����
typedef struct Vnode
{
    InfoType info;               //����������Ϣ
    ArcNode* firstarc;           //ָ���һ����
} VNode;                         //�ڽӱ�ͷ�ڵ�����
typedef struct
{
    VNode adjlist[MAXV];         //�ڽӱ�ͷ�ڵ�����
    int n, e;                    //ͼ�ж�����n�ͱ���e
} AdjGragh;                      //������ͼ�ڽӱ�����
//------------------------------------------------------------
//----�ڽӾ���Ļ��������㷨----------------------------------
//------------------------------------------------------------
//�����ڽӾ���
void CreatrMat(MatGraph& g, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    g.n = n;
    g.e = e;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.e; j++)
            g.edges[i][j] = A[i][j];
}
//����ڽӾ���g
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
                printf("%4s", "��");
        }
        cout << endl;
    }
}
//�ڽӾ���ת��Ϊ�ڽӱ�
void MatToList(MatGraph g, AdjGragh*& G)
{
    int i, j;
    ArcNode* p;
    
    G = (AdjGragh*)malloc(sizeof(AdjGragh));
    //assert(G);
    for (i = 0; i < g.n; i++)                              //���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
       
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < g.n; i++)                              //����ڽӾ�����ÿ��Ԫ��
    {
        for (j = g.e - 1; j >= 0; j--)
        {
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF)//����һ����
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));     //����һ���ڵ�p
                //assert(p);
                p->adjvex = j;
                p->weight = g.edges[i][j];
                p->nextarc = G->adjlist[i].firstarc;       //����ͷ�巨����ڵ�p
                //assert(p);
                G->adjlist[i].firstarc = p;
            }
        }
    }
    //assert(G);
    G->n = g.n;
    G->e = g.e;
}
//����ڽӱ�G
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
            printf("%3d(%d)��", p->adjvex, p->weight);
            p = p->nextarc;
        }
        cout << endl;
    }
}

//�ڽӱ�ת�����ڽӾ���
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
    cout << "����������ȱ�����" << v + 1 << "���ڵ�" << endl;
    visited[v] = 1;
    for (int w = 0; w < g.n; ++w) {
        if ((!visited[w]) && (g.edges[v][w] != INF)) {
            DFS(g, w);
        }
    }


}


int FindNotVisit1(MatGraph g, int v) { //Ѱ�ҵ�һ��δ���ʵĽڵ�
    int i;
    for (i = 0; i < g.n; i++) {
        if (visited[i] == false && g.edges[v][i] != INF) {
            return i;
        }
    }
    return -1;
}

void DFS1(MatGraph g, int v)//��ջ����ʵ����Ȳ��ң��ڽӾ���洢��ʽ��
{
    stack<int>stack;
    int w;
    w = v;
    cout << "����������ȱ�����" << v + 1 << "���ڵ�" << endl;
    visited[w] = true;
    //�ҵ�w�ĵ�һ��δ�����ʵ��ڽӶ��㣬������λ�ø���w��λ��
    while (FindNotVisit1(g, w) != -1 || stack.empty()) {
        while (FindNotVisit1(g, w) != -1) {
            //�ҵ�w�ĵ�һ��δ�����ʵ��ڽӶ���
            w = FindNotVisit1(g, w);
            //���ʲ����
            cout << "����������ȱ�����" << w + 1 << "���ڵ�" << endl;
            visited[w] = true;
            //��ջ
            stack.push(w);
        }
        if (stack.empty()) {//ջ��Ϊ��
            //��ջ
            stack.pop();
            //�Ҷ���ĵ�һ��δ�����ʵ��ڽӶ���
            w = FindNotVisit1(g, w);
        }
    }

}

int FindNotVisit2(AdjGragh* G, int v) { //Ѱ�ҵ�һ��δ���ʵĽڵ�
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

void DFS2(AdjGragh* G, int v)//�ڽӱ�洢��ʽ
{
    stack<int>st;
    int w = v;
    visited[v] = 1;
    cout << "����������ȱ�����" << v + 1 << "���ڵ�" << endl;
    st.push(v);
    while (FindNotVisit2(G, w) != -1 || st.empty())
    {
        while (FindNotVisit2(G, w) != -1) {
            //�ҵ�w�ĵ�һ��δ�����ʵ��ڽӶ���
            w = FindNotVisit2(G, w);
            //���ʲ����
            cout << "����������ȱ�����" << w + 1 << "���ڵ�" << endl;
            visited[w] = true;
            //��ջ
            st.push(w);
        }
        if (st.empty()) {//ջ��Ϊ��
            //��ջ
            st.pop();
            //�Ҷ���ĵ�һ��δ�����ʵ��ڽӶ���
            w = FindNotVisit2(G, w);
        }

    }

}

void BFS(MatGraph g, int v) {//�ڽӾ���ʵ�ֹ�ȱ���
    cout << "���ڹ�����ȱ�����" << v + 1 << "���ڵ�" << endl;
    visited[v] = 1;
    queue<int> Q; 	//STL
    Q.push(v);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int w = 0; w < g.n; ++w) {//����
            if ((!visited[w]) && (g.edges[u][w] != INF)) {//���������Ȩֵ
                cout << "���ڹ�����ȱ�����" << w + 1 << "���ڵ�" << endl;
                visited[w] = 1;
                Q.push(w);
            }
        }
    }

}

void BFS1(AdjGragh* G, int v)//�ٽ��ʵ�ֹ�ȱ���
{
    queue<int>SQ;                      //�������SQ
    int w;
    ArcNode* p;
    cout << "���ڹ�����ȱ�����" << v + 1 << "���ڵ�" << endl;
    visited[v] = 1;                    //�����ѷ��ʱ��
    SQ.push(v);
    while (!SQ.empty())              //�Ӳ�Ϊ��ʱѭ��
    {
        w = SQ.front();
        SQ.pop();                     //���ӵ�һ������W
        p = G->adjlist[w].firstarc;   //ָ��W�ĵ�һ���ڽӵ�
        while (p != NULL)              //����W�������ڽӵ�
        {
            if (visited[p->adjvex] == 0)  //����ǰ�ڽӵ�δ������
            {
                cout << "���ڹ�����ȱ�����" << p->adjvex + 1 << "���ڵ�" << endl;   //���ʸ��ڽӵ�
                visited[p->adjvex] = 1;         //�����ѷ��ʱ��
                SQ.push(p->adjvex);             //�ö������
            }
            p = p->nextarc;                    //����һ���ڽӵ�
        }
    }
    printf("\n");
}

//����ͼ���ڽӱ�
void DestroyAdj(AdjGragh*& G)
{
    for (int i = 0; i < G->n; ++i)		//ɨ�����еĵ�����
    {
        //����Ҫ��������ڽӱ�����ٺ��������Ż���
        ArcNode* pre = G->adjlist[i].firstarc;	//pָ���i����������׽ڵ�
        while (pre != NULL)			//�ͷŵ�i������������б߽ڵ�
        {
            ArcNode* p = pre;
            pre = pre->nextarc;
            free(p);
        }
    }
    free(G);						//�ͷ�ͷ�ڵ�����
    printf("���ٳɹ�\n");
}

//������

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
        printf("���붥������");
        scanf_s("%d", &n);
        e = n;
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int i2 = 0; i2 < n; i2++)
            {
                printf("�������%d�е�%d�е�Ԫ�أ�", i1, i2);
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
    printf("ͼG���ڽӱ�\n");
    MatToList(g, G);
    DispAdj(G);
    printf("\n");
    printf("ͼG���ڽӾ���\n");
    DispMat(g);
    printf("\n");
    printf("�Ӷ���0��ʼ��DFS(�ݹ��㷨):\n");
    DFS(g, 0); printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("�Ӷ���0��ʼ��DFS(ջ�������ǵݹ��㷨,�ڽӾ���Ĵ洢��ʽ):\n");
    DFS1(g, 0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("�Ӷ���0��ʼ��DFS(ջ�������ǵݹ��㷨,�ڽӱ�Ĵ洢��ʽ):\n");
    DFS2(G, 0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("�Ӷ���0��ʼ��BFS(�ڽӾ���Ĵ洢��ʽ):\n");
    BFS(g, 0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    printf("�Ӷ���0��ʼ��BFS(�ڽӱ�Ĵ洢��ʽ):\n");
    BFS1(G, 0);
    printf("\n");
    printf("�����ڽӱ�\n");
    DestroyAdj(G);
    while (1)
    {
        printf("���롮0���˳������롮1������ѡ����:");
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