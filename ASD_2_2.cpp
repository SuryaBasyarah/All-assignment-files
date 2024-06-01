#include <iostream>
using namespace std;

typedef struct node_s
{
    char current[3];
    int volts;
    struct node_s *linkp;
} node_t;

int main()
{
    node_t *node1 = new node_t;
    node_t *node2 = new node_t;
    node_t *node3 = new node_t;

    (*node1).current[0] = 'a';
    (*node1).current[1] = 'c';
    (*node1).current[2] = '\0';
    (*node1).volts = 115;
    (*node1).linkp = node2;

    (*node2).current[0] = 'd';
    (*node2).current[1] = 'c';
    (*node2).current[2] = '\0';
    (*node2).volts = 12;
    (*node2).linkp = node3;

    (*node3).current[0] = 'a';
    (*node3).current[1] = 'c';
    (*node3).current[2] = '\0';
    (*node3).volts = 220;
    (*node3).linkp = NULL;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << (*node1).current[i] << " ";
    // }
    // cout << (*node1).volts << endl;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << (*node2).current[i] << " ";
    // }
    // cout << (*node2).volts << endl;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << (*node3).current[i] << " ";
    // }
    // cout << (*node3).volts << endl;
    

    node2 = (*node1).linkp->linkp;
    cout << (*node2).current << " " << (*node1).linkp->current << " " << (*node1).current << endl;
    cout << (*node1).linkp->volts << " " << (*node1).volts << " " << (*node2).volts << endl;



    return 0;
}