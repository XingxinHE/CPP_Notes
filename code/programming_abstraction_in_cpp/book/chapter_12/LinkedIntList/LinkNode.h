struct LinkNode
{
    int value;
    LinkNode *next;

    LinkNode(int _value)
            :value(_value), next(nullptr)
    {
    }
};
