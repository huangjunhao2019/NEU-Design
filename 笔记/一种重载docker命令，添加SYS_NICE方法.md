# 直接重载docker命令的方法（4.20）
## 1.重载docker命令
![](2020-04-20-14-58-05.png)
从上图可以发现，docker run可以写成上述形式，因此我想直接把 docker run重载为docker run --cap-add SYS_NICE，
https://www.cnblogs.com/i0ject/p/3658084.html
这篇文章有如何重载命令的书写，这条路走不通
![](2020-04-20-15-39-10.png)
只能重写一个单词的命令

# 2.
   现在基本已经明白了capability的原理，下面要做的就是，到内核中了解，是如何给进程赋予capability的了。
 **#define CAP_SYS_NICE         23** ，