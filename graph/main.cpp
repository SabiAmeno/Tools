#include "mainwindow.h"
#include <QApplication>
#include "graph.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    DiGraph g;
    g.setNodeSize(5);
    g.addEdge({0, 1});
    g.addEdge({1, 3});
    g.addEdge({2, 4});
    g.addEdge({1, 4});
    g.addEdge({3, 4});

    int in_degree = g.getNodeInd(4);
    int ou_degree = g.getNodeOud(4);

    return 0;
}
