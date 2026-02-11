/*
*Общината в град Усер реши за пореден път
*да ремонтира улиците в града. 
Поради ограничената възможност на фирмата, която
извършва ремонтите, да се справи в разумен срок, 
общината решава да вземе мерки и да даде приоритет
на ремонта на определени улици. 
Целта е да се осигури достъпност до всяка точка в града
по ремонтирани улици. 
Понеже бюджетът на общината е ограничен, 
чиновниците трябва да изберат улици за ремонт, 
така че разходите да бъдат минимални. 
Дадени са броят на ключовите места в града, 
които трябва да бъдат свързани - n, и броят на улиците m. 
Цената за ремонт на улица между m[i] и m[j] е c. 
Да се намери минималната сума, която общината 
трябва да отдели, за да свърже всички точки 
в града с ремонтирани улици.

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, cost;
};

bool compare_edges(Edge a, Edge b)
{
    return a.cost < b.cost;
}
int parent[101];

int find(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

bool unite(int i, int j)
{
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }
    sort(edges.begin(), edges.end(), compare_edges);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int min_total_cost = 0;
    int edges_included = 0;
    for (int i = 0; i < m; i++) {
        if (unite(edges[i].a, edges[i].b)) {
            min_total_cost += edges[i].cost;
            edges_included++;
        }
    }
    cout << min_total_cost << endl;
}
