#include "mainwindow.h"
#include <QApplication>
#include "graph.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Graph g;
    g.setNodeSize(9);
    g.addEdge({0, 1});
    g.addEdge({0, 2});
    g.addEdge({2, 3});
    g.addEdge({1, 4});
    g.addEdge({3, 4});
    g.addEdge({5, 4});
    g.addEdge({3, 6});
    g.addEdge({6, 7});
    g.addEdge({3, 8});

    int in_degree = g.getNodeInd(4);
    int ou_degree = g.getNodeOud(4);

    g.dfs();
    return 0;
}
