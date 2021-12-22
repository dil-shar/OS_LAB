#include <stdio.h>

typedef struct producer_consumer
{
    int values[100];
    int pind, cind, max, avail;
} p_c;

p_c pc;

void produce()
{
    if (pc.avail == 0)
    {
        printf("Buffer is full consume some data\n");
        return;
    }
    printf("Enter the data inserting to the buffer\n");
    scanf("%d", &(pc.values[pc.pind]));
    pc.pind = (pc.pind + 1) % pc.max;
    pc.avail--;
}
void consume()
{
    if (pc.avail == pc.max)
    {
        printf("Buffer is empty fill some data\n");
        return;
    }
    printf("Buffer index %d containing data %d is consumed\n", pc.cind, pc.values[pc.cind]);
    pc.cind = (pc.cind + 1) % pc.max;
    pc.avail++;
}
int main()
{
    printf("Enter the buffer size\n");
    scanf("%d", &pc.avail);
    pc.max = pc.avail;
    printf("Enter \n1 to produce\n2 to consume\n3 to exit\n");
    int c = 0;
    pc.pind = 0;
    pc.cind = 0;
    while (c != 3)
    {
        if (c != 0)
            printf("Enter your choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case (1):
            produce();
            break;
        case (2):
            consume();
            break;
        default:
            break;
        }
    }
}
