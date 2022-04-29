#include <cstring>
#include <iostream>
using namespace std;

string pre_order(string in_order, string post_order)
{
    if(in_order == "" and post_order == "")
        return "";
    if(in_order.size() == 1 and post_order.size() == 1)
        return in_order;
    char root = post_order[post_order.size() - 1];
    int position = in_order.find(root);
    return string(root + \
        pre_order(in_order.substr(0, position), post_order.substr(0, position)) + \
        pre_order(in_order.substr(position+1), post_order.substr(position, post_order.size()-position-1)));
}
int main()
{
    string in_order;
    string post_order;
    cin >> in_order;
    cin >> post_order;
    cout << pre_order(in_order, post_order) << endl;
    return 0;
}
/*
Test Case
BADC
BDCA

*/