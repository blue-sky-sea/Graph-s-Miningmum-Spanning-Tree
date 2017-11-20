# Graph-s-Miningmum-Spanning-Tree
一. 实验目的和要求
 掌握图的最小生成树的概念。
 掌握生成最小生成树的Prim算法（用邻接矩阵表示图）。

二. 实验内容
编写用邻接矩阵表示无向带权图时图的以下基本操作函数：
   ① Status CreateGraph (MGraph &G)  //创建图G  
② int LocateVex(MGraph G, VerTexType u) //返回顶点u在图G中的位置
③ void PrintGraph(MGraph G)  //输出图G的顶点与边（V={…}，E={…}）
把邻接矩阵的结构定义以及这三个函数存放在头文件Graph1.h中。
编写实现生成最小生成树的Prim算法的函数： 
void MiniSpanTree_PRIM(MGraph G, VertexType u)  
把该函数及相关辅助数组（边集数组）结构定义存放在文件test5.cpp中。
编写主函数，通过调用上述函数解决如下问题：“在n个城市之间建立通信网，如何使得费用最省？”。主函数也存放在文件test5.cpp中。 
填写实验报告，实验报告文件取名为report5.doc。
5、上传实验报告文件report5.doc与源程序文件test5.cpp及Graph1.h。

三. 函数的功能说明及算法思路
    包括每个函数的功能说明，及一些重要函数的算法实现思路
	CreateGraph(MGraph &G)
	包括了初始化图，获得图节点和边的信息等内容
	要点是实用&来进行参数传递
	
	PRrintGragh(MGraph G)
	通过for循环遍历输出图的节点名称和边的三元组类型信息

	RrintGragh(MGraph G)
	通过for循环输出邻接矩阵

	MiniSpanTree_PRIM(MGraph G,int *parent)
	最核心的函数就是prim算法的实现：为了实现获得最小生成树，就必须找到未构成环路的有最小的权值的边，通过循环将所有符合要求的边集合起来，通过将它们的下标保存起来得到。
	首先，将不联通的两个节点的权值由0改为MAX(10000)，然后初始化各个辅助数组
	然后，遍历每个节点，找到和已经找到的所有节点（初始时从第一个节点开始）相连且权值最小的点。改变lowcost的值，使得下次遍历不用再考虑这次的权值。通过循环，可以获得相连节点的下标数组parent

	PrintMST(MGraph G,int *parent)
	输出最小生成树所有边，以 a—b 的形式输出
	并且得出最小生成树的权值，即最小费用
