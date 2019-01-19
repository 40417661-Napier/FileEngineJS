#include "myfunctions.h"

int main(int argc, char **argv)
{
    loadNode("int", "40");
    loadNode("char", "test");
    loadNode("char", "yeet");
    loadNode("float", "3.3454");
    loadNode("double", "3.14159");
    traverseNode(head);
    
    return 0;
}
