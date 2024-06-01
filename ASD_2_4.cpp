#include <iostream>
#include <cstring>
using namespace std;

typedef struct scale_node_s
{
    char note[4];
    struct scale_node_s *linkp;
} scale_node_t;

void print_list(scale_node_t *headp)
{
    if (headp == NULL)
    {
        cout << "\n";
    }
    else
    {
        cout << (*headp).note << " ";
        print_list((*headp).linkp);
    }
}

void length (scale_node_t *headp)
{
    int length = 1;
    for (int j = 0; j < 7; j++)
    {
        if (headp != NULL)
        {
            length++;
            headp = (*headp).linkp;
        }
    }
    cout << length;
}

int main()
{
    scale_node_t *scalep, *prevp, *newp;
    int i;

    scalep = (scale_node_t *)malloc(sizeof(scale_node_t));
    cin >> (*scalep).note;

    prevp = scalep;
    for (i = 0; i < 7; i++)
    {
        newp = new scale_node_t;
        cin >> (*newp).note;
        (*prevp).linkp = newp;
        prevp = newp;
    }

    (*prevp).linkp = NULL;

    print_list(scalep);
    length(scalep);

    return 0;
}