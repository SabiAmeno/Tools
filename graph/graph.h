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

    void setNodeSize(int nsize);

    virtual void addEdge(const Edge& e);

    int getNodeInd(int id);
    int getNodeOud(int id);

protected:
    void _add_edge(const Edge& e);

private:
    VNode *newVNode(int id);
    ENode *newENode(int id);

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
