/*
1. 
随着IP 网络的发展，为了节省可分配的注册IP 地址，有一些地址被拿出来用于私有IP 地址，以下不属于私有IP 地址范围的是
10.6.207.84
172.23.30.28
172.32.50.80
192.168.1.100

在现在的网络中， IP 地址分为公网 IP 和私有 IP 地址。公网 IP 是在 Internet 使用的 IP 地址，而私有 IP 地址是在局域网中使用的 IP 地址。
私有 IP 地址是一段保留的 IP 地址。只是使用在局域网中，在 Internet 上是不使用的。
A: 10.0.0.0~10.255.255.255 即10.0.0.0/8
B:172.16.0.0~172.31.255.255即172.16.0.0/12
C:192.168.0.0~192.168.255.255 即192.168.0.0/16

2. 常见的http错误描述原因错误的是？
404-Not found（没有找到）
302-临时重定向
500-内部服务器错误
403- IP address rejected
403错误，禁止访问，是网站访问过程中，常见的错误提示。资源不可用。服务器理解客户的请求，但拒绝处理它。通常由于服务器上文件或目录的权限设置导致。
IP address rejected为403.6

3. Linux中，一个端口能够接受tcp链接数量的理论上限是？
1024
65535
65535 * 65535
无上限
一个端口可以建立的连接数量没有理论上限,上限就是你系统的性能

4.
下面是一个http请求：<br />
GET /baidu/blog/item/6605d1b4eb6433738ad4b26d.html HTTP/1.1 <br />
Host: hi.baidu.com <br />
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.8.0.6) Gecko/20060728 Firefox/1.5.0.6 <br />
Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,/*; q = 0.5<br / >
Accept - Language: zh - cn, zh; q = 0.5 <br / >
Accept - Encoding: gzip, deflate <br / >
Accept - Charset : gb2312, utf - 8; q = 0.7, *; q = 0.7<br / >
Keep - Alive: 300 <br / >
Connection : keep - alive <br / >
Referer : http ://hi.baidu.com/baidu <br />
Cookie : BAIDUID = AFB70E986AC48B336ABAB7505CDD1C76; <br / >
下面关于 Host、User - Agent、Accept - Charset、Connection、Referer、Cookie描述错误的是？
Host： HTTP服务器的IP地址或者域名
User - Agent： 告诉HTTP服务器， 客户端使用的操作系统和浏览器的名称和版本.
Accept - Charset：浏览器申明自己接收的字符集，这就是本文前面介绍的各种字符集和字符编码，如gb2312，utf - 8
Cookie： 它记录了服务器的相关的一些信息
Referer： 提供了Request的上下文信息的服务器，告诉服务器我是从哪个链接过来的

答: cookie是用来记录用户信息的，用来表明用户身份的，不会记录服务器的信息。

5. 
int listen(SOCKET s, int backlog);该函数中第二个参数的含义是？
是否打开log信息
是否打开后台log信息
后台等待连接队列的最大限制值
后台等待连接队列的最小限制值
无意义

C
1）backlog  用于在TCP层接收链接的缓冲池的最大个数，这个个数可在应用层中的listen函数里设置，当客户链接请求大于这个个数(缓冲池满），其它的未进入链接缓冲池的客户端在tcp层上tcp模块会自动重新链接，直到超时（大约57秒后）
2）我们的应用层的链接完成是要从tcp层的链接缓冲池中移出一个（accept函数实现）

backlog是连接请求队列的最大长度。
1.在WinSock1.1中最大值5。如果backlog小于1，则backlog被置喂1；若backlog大于SOMAXCONN(定义在winsock.h中，值为5)，则backlog被置为SOMAXCONN。
2.在WinSock2中，没有制定具体值，它由服务提供者决定
3.有时候backlog设置很小，这时我们接进多少台机器都没问题是因为服务器机器处理速度很快队列来不及填满就处理完了，而且在同一个时刻到来的连接还是很少的

6. 
网络地址172.16.22.38/28 请写出此地址的子网ID以及广播地址，此地址所处子网可用主机数
172.16.22.32  172.16.22.255 12
172.16.22.32  172.16.22.47 16
172.16.22.32  172.16.22.255 15
172.16.22.32  172.16.22.47 14

28的掩码对应二进制为11111111.11111111.11111111.11110000，可以看出能变动的主机位为4位，所以一个子网最多能容纳主机为 2^4=16台，去掉前后的网络号和广播号，可用的主机数为14台。172.16.22.0这段地址按16个地址割接，可分为:
172.16.22.0-172.16.22.15
172.16.22.16-172.16.22.31
172.16.22.32-172.16.22.47

.......
172.16.22.38位于172.16.22.32-172.16.22.47这一段内，所以它的网络好是172.16.22.32，广播号是172.16.22.47
0就是可变动的位数，28是指掩码有28个1，简单的可以用32来减32-28=4来算。

7.TCP 三次握手的过程，accept 发生在三次握手哪个阶段？

第一次握手
第二次握手
第三次握手
三次握手后

第一次握手：客户端发送syn包(syn=j)到服务器。
第二次握手：服务器收到syn包，必须确认客户的SYN（ack=j+1），同时自己也发送一个ASK包（ask=k）。
第三次握手：客户端收到服务器的SYN＋ACK包，向服务器发送确认包ACK(ack=k+1)。
三次握手完成后，客户端和服务器就建立了tcp连接。这时可以调用accept函数获得此连接

7. 10.1.0.1/17的广播地址是（ ）
10.1.128.255
10.1.63.255
10.1.127.255
10.1.126.255

首先广播地址即是主机号全为1.
10.1.0.1/17化为二进制为
00001010  00000001  00000000  00000001后15为全为1
即为：
00001010  00000001  01111111  11111111
就是10.1.127.255

9. TCP报文首部信息中与关闭连接有关的是（）
URG
ACK
SYN
FIN

URG:URG=1时，表明紧急指针字段有效，告诉系统有紧急字段需要立即传送。
ACK:ACK=1时确认好才有效，ACK=0时，确认号无效。TCP规定在连接建立之后所有传送的报文都必须吧ACK置1.
RST：RST=1时表示TCP连接出现严重差错，必须释放连接再重新建立连接。
FIN：FIN=1表示要求释放连接。

在四次握手中，因为当Server端收到Client端的SYN连接请求报文后，可以直接发送SYN+ACK报文。其中ACK报文是用来应答的，SYN报文是用来同步 的。但是关闭连接时，当Server端收到FIN报文时，很可能并不会立即关闭SOCKET，所以只能先回复一个ACK报文，告诉Client端，"你发 的FIN报文我收到了"。只有等到我Server端所有的报文都发送完了，我才能发送FIN报文，因此不能一起发送。故需要四步握手。
因此，FIN和关闭链接有关。

10.
linux tcpdump监听网卡 eth0,对方主机IP为10.1.1.180，tcp端口为80的数据，相应命令为？
tcpdump -h eth0 -nn 'tcp and host 10.1.1.180:80'
tcpdump -i eth0 -nn 'tcp and host 10.1.1.180:80'
tcpdump -h eth0 -nn 'tcp and port 80 and host 10.1.1.180'
tcpdump -i eth0 -nn 'tcp and port 80 and host 10.1.1.180'
过滤port不能ip:port，过滤port只能直接指定port

tcpdump抓包命令：用于截取网络分组，并输出分组内容的工具
选项：
-A：以ASCII格式打印所有分组，常用于www的网页的数据抓取
-c：收到指定的数量的分组后，停止tcpdump
-C：将一个原始分组写入文件之前，检查文件的当前大小是否超过了file_size的指定大小，超过则关闭当前文件然后打开一个新文件，、
-d：将匹配信心包的代码以人们能够理解的汇编格式给出
-dd：将匹配信息的代码以C语言程序段的格式给出
-ddd ：将匹配信息的代码以十进制的形式给出
-D：打印系统中所有的可以用tcpdump截包的网络接口
-e：输出行打印数据链路层的头部信息
-f：将外部的internet地址以数字的形式打印
-F:从指定的文件中读取表达式，忽略命令行中给出的表达式、
-i：指定监听的网络接口
-l：使标准输出变成缓冲形式，可以把数据导出到文件
-L：列出网络接口的已知数据链路
-b：在数据链路层选择协议：ip arp rarp ipx
-n：不把网络地址转成名字
-nn：不进行端口名称的转换
-N：不输出主机名中的域名部分
-t：输出的每一行不打印时间戳
-tt：在每一行中输出非格式化的时间戳
-ttt：输出本行和前面一行之间的时间差
-tttt：在每一行中输出由date处理的默认格式的时间戳
-O：不运行分组匹配代码优化程序
-P：不将网络接口设置成混杂模式
-q：快速输出，只输出较少的协议信息
-r：从指定文件中读取包
-S：将tcp的序列号以绝对值形式输出，而不是相对值
-s:从每个分组中读取最开始的snaplen个字节】
-T：将监听的包直接解释为指定类型的报文，常见有rpc远程过程调用，和snmp
-v：输出一个详细信息
-vv：输出详细的报文信息
-w：直接将分组写入文件中，而不是不分析打印
-x:可以列出16进制以及ASCII的数据包的内容
*/