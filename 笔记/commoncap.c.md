# commoncap.c 
## 1. 对capability修改的思路以及sys_nice的位置
![](2020-04-22-10-28-19.png)
https://elixir.bootlin.com/linux/v5.7-rc1/source/security/commoncap.c

各个capability实现都在这个security/commoncap.c中
这个图里面提到
> Detemine if requested scheduler poicy change is permitted for the specified task, returing 0 if permission is granted, -ve if denied.

所以第一步，直接把这个返回值改成0，全部允许试试看
## 2. 编译内核的方法
<<<<<<< HEAD
我是通过这个方法对Linux内核进行编译的
https://blog.csdn.net/qq_36290650/article/details/83052315
时间较长，但是最后成功，注意中间有一段报错是因为终端没有全屏，全屏之后就好了。
这是修改之前的内核
![](2020-04-22-16-36-30.png)
，这是修改之后的内核，经过博客上那一顿操作之后的内核
![](2020-04-22-16-37-04.png)

这是在这个内核上的非特权容器进行操作（dev文件夹说明了这是一个非特权容器）
![](2020-04-22-16-38-11.png)

这是在非特权容器上利用chrt进行调度策略调整

![](2020-04-22-16-39-05.png)
调整成功，这说明了，我的那个思路是正确的，应该去研究这个commoncap.c
## 3.再次复现
 ### （1）仅仅修改set scheduler，没有修改set nice
 我在vmware上复现，发现不成功，怀疑是不是不对。注意vmware上不要安装vmtools，安装open-vm-tools就可以，现在在物理机上试一下。
 https://www.cnblogs.com/harrypotterjackson/p/11846222.html
 所有步骤都是按照这个进行的。
 这个步骤在efui启动界面不显示，现在增加一条"sudo mkinitramfs 5.6.6 -o /boot/initrd.img-5.6.6“，后面为"sudo update-grub2"
=======
https://blog.csdn.net/qq_36290650/article/details/83052315
我是按照这篇博客来进行调试的，第一步，进行了把上述图中的那个函数，修改成为了 return 0;编译时间有点长
>>>>>>> 0012dbb769f011b4f0ee12d937a58e9255b3b1c4
