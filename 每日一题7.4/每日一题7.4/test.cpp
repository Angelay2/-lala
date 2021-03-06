﻿/*
1. 如果将固定块大小的文件系统中的块大小设置大一些，会造成（）。
A. 更好的磁盘吞吐量和更差的磁盘空间利用率
吞吐量：每秒磁盘IO的流量。设置的块越大，一次读取相同数量的块，读取到的流量就越大。文件是按块存储的，如果块大小设置的大一些，读取的时候一次性读取的就更多，磁盘吞吐量提升.
块的大小设置之后就是固定不变的了，当文件内容比较少时，使用一个较大的块来进行读取就会浪费大量的存储空间，造成磁盘空间利用率下降

2. Cache存储器位于主存与CPU之间，用于解决CPU与主存之间的速率瓶颈问题。Cache主要由控制部分和存储部分组成，存储部分用来存放主存的部分拷贝，并不能扩大主存的容量。当CPU访问内存时，若在Cache中找到所需的指令或数据，则称命中，命中率的高低与Cache的容量、替换算法、块的大小、运行程序特性等因素有关。
为了保证速度，cache的全部功能均由硬件实现，并且对程序员透明。
3. -10的四位3进制补码
10的三进制码是 0101
四位三进制3^4是81
所以补码应该是71，也就是2122
4. Unix系统中，关于inode描述错误的是?
A. inode和文件是一一对应的
B. inode能描述文件占用的块数
C. inode描述了文件大小和指向数据块的指针
D. 通过inode实现文件的逻辑结构和物理结构的转换
【答案】A
【解析】Unix/Linux系统内部不使用文件名，而使用inode号码来识别文件。一般情况下，文件名和inode号码是"一一对应"关系。但是，Unix/Linux系统允许，多个文件名指向同一个inode号码。这意味着，可以用不同的文件名访问同样的内容；对文件内容进行修改，会影响到所有文件名；但是，删除一个文件名，不影响另一个文件名的访问。这种情况就被称为"硬链接"（hard link）。
5. 路由器工作在网络模型中的哪一层？
A. 数据链路层
B. 物理层
C. 网络层
D. 应用层
【答案】C
【解析】 网络层：路由器、防火墙
       数据链路层：网卡、网桥、交换机
       物理层：中继器、集线器
*/
