#ifndef NODE_H
#define NODE_H
#include "message.h"
#define RETURN_MESSAGE 0
#define MESSAGE 1
#define LOOP 2
#define ALT 3
#define OPT 4
#define BREAK 5
class CombinedFragment;
class Node
{
    public:

        Node();
        Node(int,Message);
        Node(int,CombinedFragment *);
        int getType();
        void setType(int);
        Message getmFrag();
        void setmFrag(Message);
        CombinedFragment getcFrag();
        void setcFrag(CombinedFragment*);

    private:
        int type;
        Message mfrag;
        CombinedFragment* cfrag;
};

#endif // NODE_H
