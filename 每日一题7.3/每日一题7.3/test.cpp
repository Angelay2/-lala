/*
虚拟地址先经过分段机制映射到线性地址，然后线性地址通过分页机制映射到物理地址
进程调度中"可抢占"和"非抢占"两种方式，前者引起系统的开销更大 
每个进程都有自己的文件描述符表，所有进程共享同一打开文件表和v-node表
多个进程竞争源出现了循环等待可能造成系统死锁
基本的存储技术包括RAM，ROM，磁盘以及SSD，其中访问速度最慢的是磁盘，CPU的高速缓存一般是由RAM组成的

1. 单任务系统中两个程序A和B，其中
A程序：CPU:10s -> 设备1:5s -> CPU:5s ->设备2:10s ->CPU:10s；
B程序：设备1:10s-> CPU:10s -> 设备2:5s ->CPU:5s ->设备2:10s；
执行顺序为A->B，那么CPU的利用率是（）
A. 30%
B. 40%
C. 50%
D. 60%

cpu利用率计算方法： cpu运行时间 / 程序总花费时间
注意顺序执行不是并发执行，也就是程序A不能在程序B使用设备的时间去使用CPU，也就是进程A执行完毕再去执行进程B。
两个进程总的CPU时间为40s，运行总时间为80s，利用率为50%

2. 有一个变量int a=0；两个线程同时进行+1操作，每个线程加100次，不加锁，最后a的值是（）？
A. 200
B. <=200
C. >=200
D. 都有可能

++这个操作不是原子操作，在汇编中加1有三步：
1.先mov读取
2.再add加操作
3.最后ldr写入
由于线程是同步的，所以，如果他们同时进行mov操作，值就不会变。
如int i=5；同时mov的5再加1=6；在同时ldr写入，好像进行了两次加法，但值还是6.
所以在这里两个线程++100次，值最大的情况就是每次++都不重叠，最大值是200，考虑重叠的情况，小于200的值都是有可能的.
补充：
线程互斥锁的作用就在这里：保证两个i变量同时能被一个线程使用，也就是mov时只能有一个进行读取。
多核cpu，最小值2，最大值200，
单核cpu，最小值100，最大值200

3. 以下哪些不是内核对象（）
进程
线程
互斥器
临界区

临界区是非内核对象,只在用户态进行锁操作。
内核对象有：存取符号对象、事件对象、文件对象、文件映射对象、I/O完成端口对象、作业对象、信箱对象、互斥对象、管道对象、进程对象、信标对象、线程对象和等待计时器对象等。这些对象都是通过调用函数来创建的。
*/