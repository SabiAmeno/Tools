#include "graph.h"
#include <cstring>
#include <stack>
#include <deque>
#include <iostream>

#define return_fail(cond, ret) \
    if(!(cond)) { \
        return ret; \
    }

#define DEL(p) do{delete (p);p = nullptr;}while(0)

Graph::Graph()
{

}

Graph::~Graph()
{
    for(int i = 0;i < m_nsize;++i)
    {
        VNode* t = m_node[i];
        ENode* l = t->i_enode;
        ENode* r = t->o_enode;
        while(l)
        {
            ENode* tmp = l->next;
            DEL(l);
            l = tmp;
        }
        while(r)
        {
            ENode* tmp = r->next;
            DEL(r);
            r = tmp;
        }
        DEL(t);
    }
}

void Graph::setNodeSize(int nsize)
{
    m_nsize = nsize;
    memset(m_node, 0, sizeof(VNode*) * 100);
    for(int i = 0;i < nsize;++i)
    {
        m_node[i] = _new_vnode_(i);
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

void Graph::dfs()
{
    bool visited[100] = {false};
    std::stack<int> defer_node;
    defer_node.push(0);

    while(!defer_node.empty())
    {
        int cid = defer_node.top();

        if(!visited[cid])
        {
            visited[cid] = true;
            std::cout << "current visit node:" << cid << std::endl;
        }

        if(_chirdren_visited_(m_node[cid], visited))
        {
            defer_node.pop();
        }
        else
        {
            ENode* t = m_node[cid]->o_enode;
            while(t)
            {
                if(visited[t->id])
                {
                    t = t->next;
                    continue;
                }

                break;
            }
            if(t)
            {
                defer_node.push(t->id);
            }
        }
    }
}

void Graph::bfs()
{
    bool visited[100] = {false};
    std::deque<int> defer_node;
    defer_node.push_front(0);

    while(!defer_node.empty())
    {
        int cid = defer_node.front();
        visited[cid] = true;
        defer_node.pop_front();
        std::cout << "current visit node:" << cid << std::endl;
        ENode* vn = m_node[cid]->o_enode;
        while(vn)
        {
            if(!visited[vn->id])
            {
                visited[vn->id] = true;
                defer_node.push_back(vn->id);
            }

            vn = vn->next;
        }
    }
}

VNode *Graph::_new_vnode_(int id)
{
    VNode* n = new VNode;
    memset(n, 0, sizeof(VNode));
    n->id = id;
    n->i_enode = n->o_enode = nullptr;

    return n;
}

ENode *Graph::_new_enode_(int id)
{
    ENode* n = new ENode;
    memset(n, 0, sizeof(n));
    n->id = id;
    n->next = nullptr;

    return n;
}

bool Graph::_chirdren_visited_(VNode *n, bool *visited)
{
    ENode* t = n->o_enode;
    while(t)
    {
        if(!visited[t->id])
        {
            return false;
        }
        t = t->next;
    }

    return true;
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
        m_node[e.id_from]->o_enode = _new_enode_(e.id_to);
    }
    else
    {
        t->next = _new_enode_(e.id_to);
    }

    m = m_node[e.id_to];
    t = m->i_enode;
    while(t && t->next)
    {
        t = t->next;
    }

    if(!t)
    {
        m_node[e.id_to]->i_enode = _new_enode_(e.id_from);
    }
    else
    {
        t->next = _new_enode_(e.id_from);
    }
}

void DiGraph::addEdge(const Edge &e)
{
    _add_edge(e);
}
