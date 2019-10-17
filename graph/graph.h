#ifndef GRAPH_H
#define GRAPH_H

struct ENode
{
    int id;
    ENode* next;
};

struct VNode
{
    int id;
    ENode* i_enode;
    ENode* o_enode;
};

struct Edge
{
    int id_from;
    int id_to;
};

class Graph
{
public:
    Graph();
    virtual ~Graph();

    void setNodeSize(int nsize);

    virtual void addEdge(const Edge& e);

    int getNodeInd(int id);
    int getNodeOud(int id);

    //深度优先搜索
    void dfs();

    //广度优先搜索，此处未使用id从小到大的方式来搜索，而是随机的方式
    void bfs();
protected:
    void _add_edge(const Edge& e);

private:
    VNode *_new_vnode_(int id);
    ENode *_new_enode_(int id);

    bool _chirdren_visited_(VNode* n, bool*);

private:
    int    m_nsize;
    VNode* m_node[100];
};

class DiGraph : public Graph
{
public:
    DiGraph() {}

    virtual void addEdge(const Edge& e);
};

#endif // GRAPH_H
