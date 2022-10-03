#include"head.h"
#include"ListNode.h"
template<typename T>
class List
{
private:
    int _size;
    ListNodeP<T> header;
    ListNodeP<T> trailer;


protected:
    void init();
    
public:
    List();
    ~List();
    void clear();
    ListNodeP<T> insert(ListNodeP<T> p,T const &e);
    ListNodeP<T> insertAsFirst(T const &e);
    ListNodeP<T> insertAsFirst(ListNodeP<T> p);
    ListNodeP<T> insertAsLast(ListNodeP<T> p);
    ListNodeP<T> insertAsLast(T const &e);
    T remove(ListNodeP<T> p);
    T removeLast();
    void reverse();
    void uniquify(); // uniquify  a sorted list
    void traverse(void (*visit)(T & e));
    void print();
    void combine(List<T> &l1,List<T> &l2);
    void reverseCombine(List<T> &l1,List<T> &l2);
    int  sortedRemoveRange(T min,T max);
    T listMax();



};




template <typename T>
void List<T>::init(){
    header=new ListNode<T>(0,nullptr,nullptr);
    trailer=new ListNode<T>(0,nullptr,nullptr);
    header->succ=trailer;
    trailer->pred=header;
    _size=0;
}


template <typename T>
void List<T>::clear(){
    _size=0;
    while (header->succ!=trailer & (!header->succ))
    {
        //printf("hahah");
        remove(header->succ);
    }
}



template <typename T>
List<T>::List()
{
    init();
}

template <typename T>
List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
}


template <typename T>
ListNodeP<T> List<T>::insert(ListNodeP<T> p, T const &e){
    //ListNodeP<T> np=new ListNode<T>(e,p->pred,p);
    //p->pred->succ=np;
    //p->pred=np;
    _size++;
    return p->insertAsPred(e);
}








template <typename T>
ListNodeP<T> List<T>::insertAsFirst(T const &e){
    _size++;
    return header->insertAsSucc(e);
}

template <typename T>
ListNodeP<T> List<T>::insertAsLast(T const &e){
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T>
ListNodeP<T> List<T>::insertAsFirst(ListNodeP<T> p){
    p->pred=header;
    p->succ=header->succ;
    header->succ->pred=p;
    header->succ=p;
    return p;
}


template <typename T>
ListNodeP<T> List<T>::insertAsLast(ListNodeP<T> p){
    p->succ=trailer;
    p->pred=trailer->pred;
    trailer->pred->succ=p;
    trailer->pred=p;
    return p;
}



template <typename T>
T List<T>::remove(ListNodeP<T> p){
    T val=p->data;
    p->pred->succ=p->succ;
    p->succ->pred=p->pred;
    _size--;
    delete p;
    return val;    
}

template <typename T>
T List<T>::removeLast(){
    return remove(trailer->pred);
}


template <typename T>
void List<T>::print(){
 //   printf("%d %d\n",header->succ->data,trailer->pred->data);
    printf("print list\n");
    ListNodeP<T> p=header->succ;
    while (p!=trailer){
        printf("%d ",p->data);
        p=p->succ;
    }
    printf("\n");
}



template <typename T>
void  List<T>::uniquify(){ // uniquify  a sorted list
    ListNodeP<T> p=header->succ;
    while (p!=trailer  && p->succ!=trailer)
    {
        if (p->data==p->succ->data){
            remove(p->succ);       
        }else{
            p=p->succ;
        }
    }
}


template <typename T>
void List<T>::combine(List<T> &l1,List<T> &l2){
    this->clear();
    l1.uniquify();
    l2.uniquify();
    ListNodeP<T> p1=l1.header->succ;
    ListNodeP<T> p2=l2.header->succ;
    while (p1!=l1.trailer && p2!=l2.trailer)
    {
        if (p1->data<p2->data){
            p1=p1->succ;
            this->insertAsLast(p1->pred);
        }else if (p1->data>p2->data){
            p2=p2->succ;
            this->insertAsLast(p2->pred);
        }else{
            p1=p1->succ;
            p2=p2->succ;
            this->insertAsLast(p1->pred);
            remove(p2->pred);
        }
    }
    while(p1!=l1.trailer ){
        p1=p1->succ;
        this->insertAsLast(p1->pred);
    }
    while(p2!=l2.trailer ){
        p2=p2->succ;
        this->insertAsLast(p2->pred);
    }
    l1.header->succ=l1.trailer;    
    l2.header->succ=l2.trailer;

}

template <typename T>
void List<T>::reverse(){
  ListNodeP<T> p=trailer;
  while(p!=nullptr) {
    std::swap(p->pred,p->succ);
    p=p->succ;
  }
  std::swap(header,trailer);
} 

template <typename T>
void List<T>::reverseCombine(List<T> &l1,List<T> &l2){
    this->combine(l1,l2);
    this->reverse();
}

template <typename T>
int List<T>::sortedRemoveRange(T min,T max){
    ListNodeP<T> p=header->succ;
    int count=0;
    while (p!=trailer){
        if (p->data>min && p->data<max){
            count++;
            p=p->succ;
            remove(p->pred);
        }else p=p->succ;
        if (p->data>=max) break;// since it is a sorted list
        
    }
    return count;

}



template <typename T>
T List<T>::listMax(){
    T max=header->succ->data;
    for (ListNodeP<T> p =header->succ ;p !=trailer; p=p->succ)
    {
        max=std::max(max,p->data);
    }
    return max;    
}



template <typename T>
void List<T>::traverse(void (*visit)(T & e)){
    for (ListNodeP<T> p =header->succ ;p !=trailer; p=p->succ)
    {
        visit(p->data);
    }
}


template <typename T>
struct Increase{
    virtual T operator()(T &e){e++;}
};


