/* 克鲁斯卡尔算法，最小生成树
 * 在含有n个顶点的连通图中选择n-1条边，构成一棵极小连通子图，
 * 并使该连通子图中n-1条边上权值之和达到最小，
 * 则称其为连通图的最小生成树。
 * 克鲁斯卡尔（Kruskal）算法，是用来求加权连通图的最小生成树的算法。
 * 基本思想：按照权值从小到大的顺序选择n-1条边，并保证这n-1条边不构成回路。
 * 具体做法：首先构造一个只含n个顶点的森林，然后依权值从小到大从连通网中
 * 选择边加入到森林中，并使森林中不产生回路，直至森林编程一棵树为止。
 */

/* 问题一：对图的所有边按照权值大小进行排序
 * 问题二：将边添加到最小生成树中时，怎么样判断是否形成了回路。
 */

typedef struct _graph
{
    char vexs[MAX];  //顶点集合
    int vexnum;      //顶点数
    int edgnum;      //边数
    int matrix[MAX][MAX]; //邻接矩阵
}Graph,*PGraph;

//边的结构体
typedef struct _EdgeData
{
    char start; //边的起点
    char end;   //边的终点
    int weight; //边的权重
}EData;

/* Graph是邻接矩阵对应的结构体
 * vesx用于保存顶点，vexnum是顶点数，edgnum是边数；
 * matrix则是用于保存矩阵信息的二维数组。
 * 例如：matrix[i][j] = 1，则表示“顶点i（即vexs[i]）”和“顶点j（即vexs[j]）”
 * 是邻接点；matrix[i][j] = 0,则表示它们不是临界点。
 * EData是邻接矩阵边对应的结构体。
 */
/* 获取图中的边 */

EData *get_edges(Graph G)
{
    int i,j;
    int index = 0;
    EData *edges;
    
    edges = (EData*)malloc(G.edgnum * sizeof(EData));
    for(i = 0; i < G.vexnum; i++)
    {
        for(j = i + 1; j < G.vexnum; j++)
        {
            if(G.matrix[i][j] != INF)
            {
                edges[index].start = G.vexs[i];
                edges[index].end = G.vexs[j];
                edges[index].weight = G.matrix[i][j];
                index++;
            }
        
        }
    
    }
    return edges;
}

/* 对边按照权值大小进行排序 */

void sorted_edges(EData* edges,int elen)
{
    int i,j;
    for(i = 0; i < elen; i++)
    {
        for(j= i+1; j < elen; j++)
        {
            if(edges[i].weight > edges[j].weight)
            {
                EData tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        
        }
    
    }
}

/* 返回ch再matrix矩阵中的位置 */
static int get_position(Graph G,char ch)
{
    int i;
    for(i = 0; i < G.vexnum; i++)
    {
        if(G.vesx[i] == ch)
            return i;
    }
    return -1;
}

/* 获取i的终点 */
int get_end(int vends[],int i)
{
    while(vends[i] != 0)
    {
        i = vends[i];
    }
    return i;
}

void kruskal(Graph G)
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;   // rets数组的索引
    int vends[MAX] = {0};  // 用于保存“已有最小生成树”中每个顶点在该最小树中的终点
    EData rets[MAX];  //结果数组，保存kruskal最小生成树的边
    EData *edges;     //图对应的所有边

    // 获取“图中所有的边”
    edges = get_edges(G);
    // 将边按照“权”的大小进行排序（从小到大）
    sorted_edges(edges,G.edgnum);

    for(i = 0; i < G.edgnum; i++)
    {
        p1 = get_position(G,edges[i].start); //获取第i条边的“起点”的序号
        p2 = get_position(G,edges[i].end);   //获取第i条边的“终点”的序号

        m = get_end(vends,p1);  //获取p1在“已有的最小生成树”
        n = get_end(vends,p2);  //获取p2在“已有的最小生成树”

        //如果 m != n，意味着“边i”与“已经添加到最小生成树中的顶点”形成环路
        if(m != n)
        {
            vends[m] = n; //设置m在“已有的最小生成树”
            rets[index++] = edges[i];   //保存结果
        }
    }
    
    free(edges);
    
    // 统计并打印“kruskal最小生成树”的信息
    length = 0;
    for(i = 0; i < index; i++)
        length += rets[i].weight;
    printf("Kruskal = %d: ",length);
    
    for(i = 0; i < index; i++)
    {
        printf("(%c,%c)",rets[i].start,rets[i].end);
    }
    printf("\n");
}


