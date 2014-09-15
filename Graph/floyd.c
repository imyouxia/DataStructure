/* 
 * 来源：http://wangkuiwu.github.io/2014/05/15/floyd-c/
 */

//邻接矩阵
typedef struct _graph
{
    char vexs[MAX];   // 顶点集合
    int vexnum;       // 顶点数
    int edgnum;       // 边数
    int matrix[MAX][MAX];  //邻接矩阵
}Graph, *PGraph;

/*
 * Graph是邻接矩阵对应的结构体。
 * vexs用于保存顶点，vexnum是顶点数，edgnum是边数；
 * matrix则是用于保存矩阵信息的二维数组。
 * 例如，matrix[i][j] = 1，
 * 则表示“顶点i（即vexs[i]）”和“顶点j（即vexs[j]）”是邻接点；
 * matrix[i][j] = 0 ,则表示它们不是邻接点。
 */

/*
 * floyd最短路径。
 * 即，统计图中各个顶点间的最短路径。
 *
 * 参数说明：
 *   G -- 图
 * path -- 路径。path[i][j] = k 表示，“顶点i”到“顶点j”的最短路径会经过顶点k
 * dist -- 长度数组。即，dist[i][j] = sum表示，“顶点i”到“顶点j”的最短路径的长度是s
 */

void floyd(Graph G,int path[][MAX],int dist[][MAX])
{
    int i,j,k;
    int tmp;

    //初始化
    for(i = 0; i < G.vexnum; i++)
    {
        for(j = 0; j < G.vexnum; j++)
        {
            dist[i][j] = G.matrix[i][j]; //“顶点i”到“顶点j”的路径长度为“i到j的权值”。
            path[i][j] = j;  //“顶点i”到“顶点j”的最短路径是经过顶点j
        }
    }

    //计算最短路径
    for(k = 0; k < G.vexnum; k++)
    {
        for(i = 0; i < G.vexnum; i++)
        {
            for(j = 0; j < G.vexnum; j++)
            {
                // 如果经过下标为k顶点路径比原两点间路径更短，则更新dist[i][j]和path[i][j]
                tmp = (dist[i][k] == INF || dist[k][j] == INF) ? INF : (dist[i][k] + dist[k][j]);
                if(dist[i][j] > tmp)
                {
                    // "i到j最短路径"对应的值设为更小的一个（即经过k）
                    path[i][j] = path[i][k];
                
                }
            
            }
        
        }
    }
    
    //打印floyd最短路径的结果
    printf("floyd:\n");
    for(i = 0; i < G.vexnum; i++)
    {
        for(j = 0; j < G.vexnum; j++)
        {
            printf("%2d ",dist[i][j]);
        }
        printf("\n");
    }    
}


















