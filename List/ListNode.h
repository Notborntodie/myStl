#include"head.h"
template <typename T> using ListNodeP=ListNode<T>*;
template <typename T> struct ListNode
{
    T data;
    ListNodeP<T> pred;
    ListNodeP<T> succ;
    ListNode() {}
    ListNode(T e,ListNodeP<T> p=nullptr,ListNodeP<T> s=nullptr):data(e),pred(p),succ(s) {}
    ~ListNode(){}
    ListNodeP<T> insertAsPred(T const &e);
    ListNodeP<T> insertAsSucc(T const &e);
    
};

template <typename T>
ListNodeP<T>  ListNode<T>::insertAsPred(T const &e){
    ListNodeP<T> p=new ListNode(e,pred,this);//this=*LisNode
    pred->succ=p;
    pred=p;    
    return p;
}

template <typename T>
ListNodeP<T>  ListNode<T>::insertAsSucc(T const &e){
    ListNodeP<T> p=new ListNode(e,this,succ);//this=*LisNode
    succ->pred=p;
    succ=p;
    return p;
}








