//
//  graph.h
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

typedef struct edgenode{
    string ch;//the one node on the apex of the vex
    int weight=0;//the weight of the vex
}edges;

typedef struct vexnode{
    string ch;//the name of node
    int num=0;//the number of nodes linked to the node
}vexs;

typedef struct MGraph{
    vexnode vexs[VNUM];
    edgenode apexs[VNUM][VNUM];
    int vexnumber,edgenumber;
}Graph;

//+++++++++++++++++++++++++++++++++++++++++++++++++++
/*
	creator:mizukiyuta
	CreateGraph(MGraph &G):
	*GetVexandEdgeNumber(int &vexnum,int &edgenum);
 *initGraph(MGraph &G);
 *LocateVex(MGraph G, VerTexType u);
	*GetVexNode(MGraph &G,int vexnum);
	*GetEdgeNode(MGraph &G,int edgenum);
 */
bool GetVexandEdgeNumber(MGraph &G)
{
    int vexnum=0,edgenum=0;
    cout<<"please put-in the vexnum and edgenum:"<<endl;
    if(cin>>vexnum){
        G.vexnumber = vexnum;
        if(cin>>edgenum){
            G.edgenumber = edgenum;
            cout<<"success!"<<endl;
            return true;
        }
        else {
            cout<<"wrong!(at:GetVexandEdgeNumber)"<<endl;
            return false;
        }
    }
    else {
        cout<<"wrong!(at:GetVexandEdgeNumber)"<<endl;
        return false;
    }
    return true;
}
bool initGraph(MGraph &G)
{
    G.edgenumber=0;
    G.vexnumber=0;
    for(int i=0;i<G.vexnumber;++i)
        for(int j=0;j<G.vexnumber;++j)
        {
            G.apexs[i][j].ch="\0";
            G.apexs[i][j].weight=0;
        }
    return true;
}
int LocateVex(MGraph G,string u)
{
    /*
     LocateVex(MGraph G, VerTexType u):
     //
     */
    //return the location of the node
    int i;
    for(i=0;i<G.vexnumber;++i){
        if(u==G.vexs[i].ch){
            return i;
        }
    }
    if(i==G.vexnumber){
        cout<<"the vexs is not there(LocateVex)"<<endl;
        return -1;
    }
    return -1;
}
bool GetVexNode(MGraph &G)
{
    
    //getchar();
    cout<<"please put-in "<<G.vexnumber<<" VexNodes's name:"<<endl;
    int i;
    for(i=0;i<G.vexnumber;++i){
        cout<<"NO."<<(i+1)<<":";
        cin>>G.vexs[i].ch;	//cout<<" "<<G_temporary->ch;
        //cout<<endl;
        //cin.clear();cin.ignore();
    }
    if(i!=G.vexnumber){
        cout<<"wrong!(at:GetVexNode(MGraph &G)"<<endl;
        exit(-1);
    }
    cout<<"success!"<<endl;
    return true;
}
bool GetEdgeNode(MGraph &G)
{
    string ch1,ch2;
    int weight1;
    //getchar();
    cout<<"please put-in "<<G.edgenumber<<" EdgeNodes's two of endpoints:"<<endl;
    
    int i;
    for(i=0;i<G.edgenumber;){
        cout<<"NO."<<(i+1)<<":";
        cout<<"  one of the endpoint:";
        cin>>ch1;
        cout<<"       the another endpoint:";
        cin>>ch2;
        cout<<"       the weight:";
        cin>>weight1;
        int x,y;
        x=LocateVex(G,ch1);
        y=LocateVex(G,ch2);
        if(x!=-1&&y!=-1){
            if(G.apexs[x][y].weight!=0||G.apexs[y][x].weight!=0){
                cout<<"repeatly put-in!"<<endl;
                continue;
            }
            G.apexs[x][y].weight=weight1;
            G.apexs[y][x].weight=weight1;
            ++i;//this round is valid
        }
        else{
            cout<<"put-in wrong!please put in again:"<<endl;
        }
        //cout<<endl;
        //cin.clear();cin.ignore();
    }
    
    if(i!=G.edgenumber){
        cout<<"wrong!(at:GetEdgeNode(MGraph &G)"<<endl;
        exit(-1);
    }
    cout<<"success!"<<endl;
    return true;
}
bool CreateGraph(MGraph &G)
{
    //create a graph G
    initGraph(G);
    GetVexandEdgeNumber(G);
    //test of GetVexandEdgeNumber(vexnum,edgenum):
    //cout<<G.vexnumber<<endl;//cout<<G.edgenumber<<endl;
    GetVexNode(G);
    GetEdgeNode(G);
    return true;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++




