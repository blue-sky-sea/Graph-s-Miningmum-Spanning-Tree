//
//  main.cpp
//  1
//
//  Created by tt on 17/11/19.
//  Copyright © 2017年 tt. All rights reserved.
//

#include <string.h>

#include <iostream>

//#include <>

using namespace std;

#define VNUM 20

#define MAX 10000

#include "graph.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
	*PRrintGragh(MGraph G):
	*RrintGragh(MGraph G);
 */
bool PRrintGragh(MGraph G)
{
    
    //print the vex and the node of the graph
    int i=0,j=0;
    cout<<"vexs of the Graph :";
    for(i=0;i<G.vexnumber;++i){
        cout<<" "<<G.vexs[i].ch<<" ";
    }
    cout<<endl;
    cout<<"edges of the Graph";
    for(i=0;i<G.vexnumber;++i)
        for(j=0;j<G.vexnumber;++j)
            if(i<j)
                if(G.apexs[i][j].weight!=0)
                    cout<<" ("<<G.vexs[i].ch<<","<<G.vexs[j].ch<<","<<G.apexs[i][j].weight<<") ";
    cout<<endl;
    return true;
}
bool RrintGragh(MGraph G)
{
    int i,j;
    //print the vex and the node of the graph
    cout<<"Matrix Graph is:"<<endl;
    for( i=0; i<G.vexnumber; i++ ) {
        for( j=0; j<G.vexnumber; j++ )
            cout<<G.apexs[i][j].weight<<" ";
        cout<<endl;
    }
    return true;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 *void SetWeight( Graph G)
	*MiniSpanTree_PRIM(MGraph G);
	*void PrintMST(G,parent);
 */
void SetWeight(MGraph &G)
{
    //SET 0 WEIGHT WITH MAX
    for( int i=0; i<G.vexnumber; i++ )
        for( int j=0; j<G.vexnumber; j++ )
            if( 0 == G.apexs[i][j].weight )
                G.apexs[i][j].weight = MAX;
}
void MiniSpanTree_PRIM(MGraph G,int *parent)
{
    
    //SET 0 WEIGHT by MAX
    //*SetWeight(MGraph &G);
    //++++++++++++++++++++++++++++++++++++++++
    for( int i=0; i<G.vexnumber; i++ )
        for( int j=0; j<G.vexnumber; j++ )
            if( 0 == G.apexs[i][j].weight )
                G.apexs[i][j].weight = MAX;
    //+++++++++++++++++++++++++++++++++++++++++
    
    
    int i,j,k;
    int lowcost[VNUM];
    int closest[VNUM];
    int used[VNUM];//used[] keep the flag for whether the node has been used
    int min;
    
    for(i=0;i<G.vexnumber;i++){
        lowcost[i] = G.apexs[0][i].weight;
        closest[i] = 0;
        used[i] = 0;    //used[i]==0 shows that node(i) is kept at U
        //!=0 shows that node is kept at V-U
        parent[i] = -1;
    }
    used[0]=1;      //node(i=1) has been used ,it is uesd as the first node
    
    for(i=0;i<G.vexnumber-1;i++){
        j=0;
        min=MAX;
        
        //find the j
        for(k=1;k<G.vexnumber;++k){
            if((used[k]==0)&&(lowcost[k]<min)){
                min = lowcost[k];   //find the lowest weight connet to the first vex in used[k]=0
                j=k;    //keep the lowest j
            }
        }
        
        parent[j] = closest[j];
        used[j] = 1;//node(j) has been used(take the node(j) into U)
        
        //
        for(k=0;k<G.vexnumber;k++){
            //update lowest[] and cloest[];
            if((used[k]==0)&&(G.apexs[k][j].weight<lowcost[k])){
                lowcost[k] = G.apexs[k][j].weight;
                closest[k] = j;//closest[] keep the lowset's j
            }
        }
    }
    
}
void PrintMST(MGraph G,int *parent)
{
    int weight1 = 0;
    cout<<"the edge of MST is:"<<endl;
    for(int i=1;i<G.vexnumber;++i)
    {
        int j = parent[i];
        cout<<" "<<G.vexs[j].ch<<"--"<<G.vexs[i].ch<<endl;
        //cout<<G.apexs[j][i].weight<<endl;
        weight1 += G.apexs[j][i].weight;
    }
    cout<<"the weight of MST is:"<<weight1<<endl;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main()
{
    MGraph G;
    CreateGraph(G);
    PRrintGragh(G);
    RrintGragh(G);
    
    int parent[VNUM];
    MiniSpanTree_PRIM(G,parent);
    PrintMST(G,parent);
    
    
}

