# List

**Based on DSA of Deng**

作业实现的函数测试都在`main.cpp`里

## ListNode

为了书写的方便

```c++
template <typename T> using ListNodep ListNode<T>*
```

<img src="http://cdn.zhengyanchen.cn/img202210021906816.png" alt="截屏2022-10-02 19.05.58" style="zoom:50%;" />

* 数据区
  * `data`
  * `pred`
  * `succ`

* 函数区
  * 构造函数
  * 插入前驱`insertAsPred(T const &e)`
  * 插入后驱`insertAsSucc(T const &e)`

## List

* 提供的接口

![截屏2022-10-02 19.17.30](http://cdn.zhengyanchen.cn/img202210021917382.png)



* **private**

  * `_size`(区别于接口)

  * `header`(头哨兵，秩=0),`trailer`(尾哨兵，秩=n)

    ![截屏2022-10-02 19.19.40](http://cdn.zhengyanchen.cn/img202210021919869.png)

    

* **protected **

  * 初始化函数`init()`, 初始化`header`，`trailer` 和`_size`
  * 重载`[]`
  * `copyNodes(Listcodep<T> p,int n)` 先`init()`从p开始，拷贝n个节点
  * `clear()`,调用`remove`,删除所有的节点

* **public**

  * `List()`
  * `Lisr(List<T> const & L)`
  * `~List()`
  * `size()`
  * 
  * `first()`
  * `last()`
  * `insert(T const &e,ListNodep<T> p)`(插入p原来的位置)
  * `remove(ListNodep<T> p)`
    * `insertAsFirst(T const &e)`，在`header`后插入		
    * `insertAsLast(T const &e)`,在`trailer`前插入
  * `disordered()`
  * `sort()`
  * `find(e)`
  *  `uniquify()`
  * `traverse(void (*visit)(T & e))`

  

  

  

  

  

  

  ## 错误

  ```shell
  free(): double free detected in tcache 2
  ```

  * 注意不要多回收内存

  

  

  

  

  

  

  

  

  

  

  