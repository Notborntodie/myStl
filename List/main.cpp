#include"List.h"
#include"head.h"

void init(List<int> &L1,List<int> &L2){
    for (int i= 0; i < 10; i+=2)
    {
        L1.insertAsLast(i);
        L1.insertAsLast(i);
        L2.insertAsLast(i+1);
    }
}


int main(){
    List<int> L1,L2,L3,L4,L5;

    //hwtest1
    printf("hwtest1\n");
    init(L1,L2);
    L1.print();
    L2.print();
    L3.combine(L1,L2);// well ,it is not a safe function,since L1,L2 are ruined.
    L3.print();

    //hwtest2
    printf("hwtest2\n");
    init(L1,L2);
    L3.reverseCombine(L1,L2);
    L3.print();



    //hwtest4
    printf("hwtest4\n");
    init(L3,L4);
    L4.print();
    L4.reverse();
    L4.print();

    //hwtest5
    printf("hwtest5\n");
    init(L4,L5);
    L5.print();
    printf("removeNum=%d\n",L5.sortedRemoveRange(3,8));
    L5.print();


    return 0;

}



