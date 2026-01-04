#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef unordered_set<int> usi;
typedef unordered_map<int, usi> umiusi;

typedef set<pair<int, int>> spii;
typedef unordered_map<int, spii> umipii;

void add_node_vvi(vvi &graph, vi &newnode) {
  graph.push_back(newnode);
  cout << "node inserted " << endl;
}
vvi make_graph_vvi() {
  vi n1(5, 0);
  vi n2(5, 0);
  vi n3(5, 0);
  vi n4(5, 0);
  vi n5(5, 0);

  n1 = {1, 2, 5};

  n2 = {3, 5};

  n3 = {4, 1};

  n4 = {1, 2, 3, 5};

  n5 = {1};
  vvi graph;
  add_node_vvi(graph, n1);
  add_node_vvi(graph, n2);
  add_node_vvi(graph, n3);
  add_node_vvi(graph, n4);
  add_node_vvi(graph, n5);
  return graph;
}
void add_node_umiusi(umiusi &graph_unorderd, const int &node,
                     const usi &neighbors) {
  graph_unorderd[node].insert(neighbors.begin(), neighbors.end());
}
umiusi make_graph_umiusi() {
  umiusi graph_unorderd;

  add_node_umiusi(graph_unorderd, 1, {1, 2, 5});

  add_node_umiusi(graph_unorderd, 2, {3, 4});

  add_node_umiusi(graph_unorderd, 3, {2, 1});

  add_node_umiusi(graph_unorderd, 4, {1, 2, 3, 5});

  add_node_umiusi(graph_unorderd, 5, {1});
  return graph_unorderd;
}
umipii make_weighted_graph() {
  umipii weighted_graph;

  spii edges = {{1, 100}, {2, 0}, {3, 0}, {4, 0}, {5, 7}};
  weighted_graph.insert({1, edges});

  edges = {{3, 5}, {5, 3}, {1, 0}, {2, 0}, {4, 0}};
  weighted_graph.insert({2, edges});

  edges = {{4, 1}, {1, 4}, {2, 0}, {3, 0}, {5, 0}};
  weighted_graph.insert({3, edges});

  edges = {{1, 4}, {2, 2}, {3, 5}, {5, 3}, {4, 0}};
  weighted_graph.insert({4, edges});

  edges = {{1, 5}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};
  weighted_graph.insert({5, edges});
  return weighted_graph;
}
vvb make_graph_vvb() {
  vvb graph_bool;
  graph_bool.push_back({1, 0, 0, 0, 1});
  graph_bool.push_back({0, 0, 1, 0, 1});
  graph_bool.push_back({0, 1, 0, 0, 1});
  graph_bool.push_back({1, 1, 1, 0, 1});
  graph_bool.push_back({1, 0, 0, 0, 0});
  return graph_bool;
}

void print_adj_list_vvi(vvi &graph) {
  vvi ::iterator nodeit;
  vi::iterator edgeit;
  int node = 1;
  for (nodeit = graph.begin(); nodeit != graph.end(); nodeit++) {

    cout << node++ << " : ";
    for (edgeit = (*nodeit).begin(); edgeit != (*nodeit).end(); edgeit++)
      cout << "\t" << (*edgeit);
    cout << endl;
  }
  cout << endl;
}

void print_adj_matrix_vvb(vvb &graph) {

  vvb::iterator nodeit;
  vb ::iterator edgeit;
  int node = 1;
  cout << "  ";
  for (node = 1; node <= graph.size(); node++) {
    cout << " " << node << " ";
  }
  cout << endl;
  node = 1;
  for (nodeit = graph.begin(); nodeit != graph.end(); nodeit++) {
    cout << node++ << " ";
    for (edgeit = (*nodeit).begin(); edgeit != (*nodeit).end(); edgeit++)

      cout << " " << (*edgeit) << " ";
    cout << endl;
  }
  cout << endl;
}
void print_adj_list_vvb(vvb &graph) {
  vvb ::iterator nodeit;
  int node = 1;
  for (nodeit = graph.begin(); nodeit != graph.end(); nodeit++) {

    cout << node++ << " : ";
    for (int edgeindex = 0; edgeindex < (*nodeit).size(); edgeindex++)
      if ((*nodeit)[edgeindex] != 0)
        cout << "\t" << ++edgeindex;
    cout << endl;
  }
  cout << endl;
}
void print_adj_list_umiusi(umiusi &graph_unorderd) {
  for (const pair<int, usi> &vertex : graph_unorderd) {
    cout << vertex.first << " : ";
    for (const int &neighbor : vertex.second) {
      cout << neighbor << "\t";
    }
    cout << endl;
  }
}

void print_adj_matrix_weighted(umipii &graph_weigthed) {

  int node = 1;
  cout << "  ";
  for (node = 1; node <= graph_weigthed.size(); node++) {
    cout << " " << node << " ";
  }
  cout << endl;
  node = 1;
  for (const pair<int, spii> &vertex : graph_weigthed) {
    cout << node++ << " ";
    for (const pair<int, int> &neighbor : vertex.second)
      cout << " ( " << neighbor.first << "," << neighbor.second << " ) ";
    cout << endl;
  }
  cout << endl;
}
void print_adj_list_weighted(umipii &graph_unorderd) {
  for (const pair<int, spii> &vertex : graph_unorderd) {
    cout << vertex.first << " : ";
    for (const pair<int, int> &neighbor : vertex.second) {
      if (neighbor.second != 0)
        cout << " ( " << neighbor.first << "," << neighbor.second << " ) "
             << "\t";
    }
    cout << endl;
  }
}
int main() {
  vvi graph = make_graph_vvi();
  print_adj_list_vvi(graph);

  vvb graph_bool = make_graph_vvb();
  print_adj_matrix_vvb(graph_bool);
  print_adj_list_vvb(graph_bool);

  umiusi graph_unorderd = make_graph_umiusi();
  cout << "umiusi list" << endl;
  print_adj_list_umiusi(graph_unorderd);

  cout << endl;
  umipii graph_weigthed = make_weighted_graph();
  print_adj_list_weighted(graph_weigthed);
  print_adj_matrix_weighted(graph_weigthed);
}
