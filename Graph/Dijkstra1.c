/*
 * 详解见此地址：http://www.cnblogs.com/skywang12345/p/3711512.html
 *
 */

//邻接矩阵
typedef struct _graph
{
    char vexs[MAX];  //顶点集合
    int vexnum;     //顶点数
    int edgnum;   //边数
    int matrix[MAX][MAX];  //邻接矩阵
}Graph,*pGraph;

//边的结构体
typedef struct _EdgeData
{
    char start;   //边的起点
    char end;     //边的终点
    int weight;   //边的权重
}EData;


/*
 * Graph是邻接矩阵对应的结构体
 * vexs用于保存顶点，vexnum是顶点数，edgnum是边数；matrix则是用于保存矩阵信息的二维数组。
 * 例如，
 * matrix[i][j] = 1 则表示“顶点i（即vexs[i]）”和“顶点j（即vexs[j]）”是邻接点；
 * matrix[i][j]=0，则表示它们不是邻接点。
 * EData是邻接矩阵对应的结构体。
 *
 */

/*
 * Dijkstra最短路径：
 * 即统计图（G）中“顶点vs”到其它各个顶点的最短路径。
 */

/*参数说明：
 *    G -- 图
 *   vs -- 起始顶点（start,vertex）。即计算“顶点vs”到其它顶点的最短路径。
 * prev -- 前驱顶点数组。即，prev[i] 的值是“顶点vs” 到“顶点i”的最短路径所经历的全部顶点中，位于“顶点i”之前的那个顶点。
 * dist -- 长度数组。即，dist[i]是“顶点vs”到“顶点i”的最短路径的长度。
 */

void dijkstra(Graph G,int vs,int prev[],int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX];  //flag[i] = 1 表示“顶点vs”到“顶点i”的最短路径已成功获取

    // 初始化
    for(i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0; //顶点i的最短路径还没获取到
        prev[i] = 0; //顶点i的前驱顶点为0
        dist[i] = G.matrix[vs][i]; //顶点i的最短路径为“顶点vs”到“顶点i”的权
    }

    //对“顶点vs”自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    //遍历G.vexnum - 1次；每次找出一个顶点的最短路径
    for(i = 1; i < G.vexnum; i++)
    {
        //寻找当前最小的路径
        //即，在未获取最短路径的顶点中，找到离vs最近的顶点（k）。
        min = INF;
        for(j = 0; j < G.vexnum; j++)
        {
            if(flag[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        //标记“顶点k”为已经获取到最短路径
        flag[k] = 1;
        //修正当前最短路径和前驱顶点
        //即，当获取“顶点k的最短路径”之后，更新“未获取最短路径的顶点的最短路径和前驱顶点。”
        for(j = 0; j < G.vexnum; j++)
        {
            tmp = (G.matrix[k][j] == INF?INF:(min+G.matrix[k][j])); //防止溢出
            if(flag[j] == 0 && (tmp < dist[j]))
            {
                dist[j] = tmp;
                prev[j] = k;
            } 
        }
        

    }
    
    //打印dijkstra最短路径的结果
    printf("dijkstra(%c):\n",G.vexs[vs]);
    for(i = 0; i < G.vexnum; i++)
    {
        printf("shortest(%c,%c) = %d\n",G.vexs[vs],G.vexs[i],dist[i]);
    }

}



