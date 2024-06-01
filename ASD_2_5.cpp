#include <iostream>
using namespace std;

typedef struct list_node_s
{
    int digit;
    struct list_node_s *restp;
} list_node_t;

list_node_t *cari(list_node_t *headp, int target)
{
    while (headp != nullptr)
    {
        if ((*headp).digit == target)
        {
            return headp;
        }
        else
        {
            return cari((*headp).restp, target);
        }
    }
}
list_node_t *get_list(void)
{
    int data;
    list_node_t *ansp;

    cin >> data;
    if (data == 999)
    {
        ansp = NULL;
    }
    else
    {
        ansp = (list_node_t *)malloc(sizeof (list_node_t));
        (*ansp).digit = data;
        (*ansp).restp = get_list();
    }

}

int main()
{
    list_node_t *pi_fracp, *result;

    pi_fracp = get_list();
    result = cari(pi_fracp, 5);
    cout << (*result).digit << " " << (*result).restp;
    return 0;
}