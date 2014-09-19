/*
 * 来源：http://wangkuiwu.github.io/2014/05/13/prim-c/
 */

// 邻接矩阵
typedef struct _graph
{
    char vexs[MAX]; //顶点集合
    int vexnum;    //顶点数
    int edgnum;     //边数
    int matrix[MAX][MAX];   //邻接矩阵
}Graph，*PGraph;

// 边的结构体
typedef struct _EdgeData
{
    char start; //边的起点
    char end;   //边的终点
    int weight; //边的权重
}EData;

/* Graph是邻接矩阵对应的结构体
 * vesx用于保存顶点，vexnum是顶点数，edgnum是边数；
 * matrix则是用于保存矩阵信息的二维数组。
 * 例如，matrix[i][j] = 1，则表示“顶点i（即vexs[i]）”和“顶点j（即vexs[j]）”
 * 是邻接点；matrix[i][j] = 0，则表示它们不是邻接点。
 * EData是邻接矩阵边对应的结构体。
 */

/* 
 * G     -- 邻接矩阵图
 * start -- 从图中的第start个元素开始，生成最小数
 */

void prim(Graph G,int start)
{
    int min,i,j,k,m,n,sum;
    int index = 0; // prim最小树的索引，即prims数组的索引
    char prims[MAX];    //prim最小树的结果数组
    int weights[MAX];   //顶点间边的权值

    // prim最小生成树中第一个数是“图中第start个顶点”，因为是从start开始的
    prims[index++] = G.vexs[start];

    // 初始化“顶点的权值数组”
    // 将每个顶点的权值初始化为“第start个顶点”到“该顶点”的权值
    for(i = 0; i < G.vexnum; i++)
    {
        weights[i] = G.matrix[start][i];
    }
    // 将第start个顶点的权值初始化为0
    // 可以理解为“第start个顶点到它自身的距离为0”
    weights[start] = 0;

    for(i = 0; i < G.vexnum; i++)
    {
        //由于从start开始的，因此不需要再对第start个顶点进行处理
        if(start == i)
            continue;
        k = 0;
        k = 0;
        min = INF;

        // 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
        while(j < G.vexnum)
        {
            // 若weights[j] = 0，意味着“第j个节点已经被排序”（或者说已经加入了最小生成树中）
            if(weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
            j++;
        }

        // 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点
        // 将第k个顶点加入到最小生成树的结果数组中
        prims[index++] = G.vexs[k];
        // 将“第k个顶点的权值”标记为0，意味着第k个顶点已经排序过了（或者说已经加入了最小生成结果中）
        weights[k] = 0;
        // 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值
        for(j = 0; j < G.vexnum; j++)
        {
            //当第j个节点没有被处理，并且需要更新时才被更新
            if(weights[j] != 0 && G.matrix[k][j] < weights[j])
            {
                weights[j] = G.matrix[k][j];
            }
        }
    }
    //计算最小生成树的权值
    sum = 0;
    for(i = 1; i < index; i++)
    {
        min = INF;
        // 获取prims[i]在G中的位置
        n = get_position(G,prims[i]);
        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        for(j = 0; j < i; j++)
        {
            m = get_position(G,prims[j]);
            if(G.matrix[m][n] < min)
                min = G.matrix[m][n];
        }

        sum += min;
    }

    // 打印最小生成树
    printf("PRIM(%c)=%d：",G.vexs[start],sum);
    for(i = 0; i < index; i++)
        printf("%c ",prims[i]);
    printf("\n");
}

