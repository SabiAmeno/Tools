#include "graph.h"
#include <cstring>

#define return_fail(cond, ret) \
    if(!(cond)) { \
        return ret; \
    }

Graph::Graph()
{

}

void Graph::setNodeSize(int nsize)
{
    m_nsize = nsize;
    memset(m_node, 0, sizeof(VNode*) * 100);
    for(int i = 0;i < nsize;++i)
    {
        m_node[i] = newVNode(i);
    }
}

void Graph::addEdge(const Edge &e)
{
    _add_edge(e);
    _add_edge({e.id_to, e.id_from});
}

int Graph::getNodeInd(int id)
{
    return_fail(id > -1 && id < m_nsize, -1);

    ENode* in_d = m_node[id]->i_enode;
    int count = 0;
    while(in_d)
    {
        count++;
        in_d = in_d->next;
    }

    return count;
}

int Graph::getNodeOud(int id)
{
    return_fail(id > -1 && id < m_nsize, -1);

    ENode* on_d = m_node[id]->o_enode;
    int count = 0;
    while(on_d)
    {
        count++;
        on_d = on_d->next;
    }

    return count;
}

VNode *Graph::newVNode(int id)
{
    VNode* n = new VNode;
    memset(n, 0, sizeof(VNode));
    n->id = id;
    n->i_enode = n->o_enode = nullptr;

    return n;
}

ENode *Graph::newENode(int id)
{
    ENode* n = new ENode;
    memset(n, 0, sizeof(n));
    n->id = id;
    n->next = nullptr;

    return n;
}

void Graph::_add_edge(const Edge &e)
{
    VNode* m = m_node[e.id_from];
    ENode* t = m->o_enode;
    while(t && t->next)
    {
        t = t->next;
    }

    if(!t)
    {
        m_node[e.id_from]->o_enode = newENode(e.id_to);
    }
    else
    {
        t->next = newENode(e.id_to);
    }

    m = m_node[e.id_to];
    t = m->i_enode;
    while(t && t->next)
    {
        t = t->next;
    }

    if(!t)
    {
        m_node[e.id_to]->i_enode = newENode(e.id_from);
    }
    else
    {
        t->next = newENode(e.id_from);
    }
}

void DiGraph::addEdge(const Edge &e)
{
    _add_edge(e);
}
