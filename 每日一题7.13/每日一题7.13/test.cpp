/*
1.
某公司申请到一个C类IP地址，但要连接6个的子公司，最大的一个子公司有26台计算机，每个子公司在一个网段中，则子网掩码应设为（）
255.255.255.192
255.255.255.128
255.255.255.0
255.255.255.224

首先题目问的是一个子公司的网络内，子网掩码是什么。不要理解错题意。
一个子公司26台机器，2^5 = 32，刚好够用，所以IP地址最后8位里的后5位用作子网内区分的地址。
前3位就是子网掩码了，即11100000，即224。
选D，255.255.255.224

2. 以下哪个ip不和10.11.12.91/28处于同一个子网
10.11.12.85/28
10.11.12.88/28
10.11.12.94/28
10.11.12.97/28

前28位为网络号，故子网掩码为11111111.11111111. 11111111. 11110000（255.255.255.240）。
256-240=16，有16个子网，每一个子网段大小范围是16。
10.11.12.91/28中91可以表示为：01011011，前四位为网络号，后四位为主机号，
故包含10.11.12.91的子网范围是：01010000~01011111（80~95）。
去掉第一个和最后一个，和 10.11.12.91/28在一个网段的范围为： 10.11.12.81/28~ 10.11.12.94/28。
答案选择D。

3.从浏览器打开 http://www.mi.com ，TCP/IP协议族中不会被使用到的协议是（）
SMTP
HTTP
TCP
IP

1. 域名解析，通过域名查找出IP地址 - IP
2. 浏览器与网站建立TCP连接，三次握手 - TCP
3. HTTP访问，HTTP-GET - HTTP
4. 浏览器与网站断开TCP连接，四次挥手 - TCP
应用层协议: SMTP(简单的邮件传输协议)，与之对应的是POP3,是一种提供有效且可靠的电子邮件传输协议，控制两个相互通信的SMTP进程交换信息。

4. 
假设在x86平台上,有一个int型变量,在内存中的内部由低到高分别是:0x12,0x34,0x56,0x78当通过网络发送该数据时,正确的发送顺序是()
0x12,0x34,0x56,0x78
0x78,0x56,0x34,0x12
0x34,0x12,0x78,0x56
0x56,0x78,0x12,0x34

链接：https://www.nowcoder.com/questionTerminal/d7c1ff50fab44443b61903eccd791f1d
来源：牛客网

小端法(Little-Endian)就是低位字节排放在内存的低地址端(即该值的起始地址),高位字节排放在内存的高地址端;
大端法(Big-Endian)就是高位字节排放在内存的低地址端(即该值的起始地址),低位字节排放在内存的高地址端;

UDP/TCP/IP协议规定:把接收到的第一个字节当作高位字节看待,这就要求发送端发送的第一个字节是高位字节;而在发送端发送数据时,发送的第一个字节是该数值在内存中的起始地址处对应的那个字节,
也就是说,该数值在内存中的起始地址处对应的那个字节就是要发送的第一个高位字节(即:高位字节存放在低地址处);由此可见,多字节数值在发送之前,在内存中因该是以大端法存放的;
所以说,网络字节序是大端字节序;

5. 下列哪个地址不可能是子网掩码()
255.224.0.0
255.255.240.0
255.255.255.248
255.255.255.250

子网掩码前面全是1,后面为0,必须是连续的
224是 1 1 0 0 0 0 0 0 可行
240是 1 1 1 0 0 0 0 0 可行
248是 1 1 1 1 1 0 0 0 可行
250是 1 1 1 1 1 0 1 0 不可行

6. 
下面关于synflood攻击的说法,错误的是()
服务端由于连接队列被占满而不能对外服务
不但能攻击TCP服务,还可以攻击UDP服务
大量连接处于SYN_RECV状态
使用硬件防火墙可以一定程度上抵御攻击

链接：https://www.nowcoder.com/questionTerminal/4048c3110222428d8fa3b66bba429345?toCommentId=77653
来源：牛客网

问题就出在TCP连接的三次握手中，假设一个用户向服务器发送了SYN报文后突然死机或掉线，那么服务器在发出SYN+ACK应答报文后是无法收到客户端的ACK报文的（第三次握手无法完成），这种情况下服务器端一般会重试（再次发送SYN+ACK给客户端）并等待一段时间后丢弃这个未完成的连接，这段时间的长度我们称为SYN Timeout，一般来说这个时间是分钟的数量级（大约为30秒-2分钟）；一个用户出现异常导致服务器的一个线程等待1分钟并不是什么很大的问题，但如果有一个恶意的攻击者大量模拟这种情况，服务器端将为了维护一个非常大的半连接列表而消耗非常多的资源----数以万计的半连接，即使是简单的保存并遍历也会消耗非常多的CPU时间和内存，何况还要不断对这个列表中的IP进行SYN+ACK的重试。实际上如果服务器的TCP/IP栈不够强大，最后的结果往往是堆栈溢出崩溃---即使服务器端的系统足够强大，服务器端也将忙于处理攻击者伪造的TCP连接请求而无暇理睬客户的正常请求（毕竟客户端的正常请求比率非常之小），此时从正常客户的角度看来，服务器失去响应，这种情况我们称作：服务器端受到了SYN Flood攻击（SYN洪水攻击）。

链接：https://www.nowcoder.com/questionTerminal/4048c3110222428d8fa3b66bba429345?toCommentId=77653
来源：牛客网

【问题1】为什么连接的时候是三次握手，关闭的时候却是四次握手？

答：因为当Server端收到Client端的SYN连接请求报文后，可以直接发送SYN+ACK报文。其中ACK报文是用来应答的，SYN报文是用来同步的。但是关闭连接时，当Server端收到FIN报文时，很可能并不会立即关闭SOCKET，所以只能先回复一个ACK报文，告诉Client端，"你发的FIN报文我收到了"。只有等到我Server端所有的报文都发送完了，我才能发送FIN报文，因此不能一起发送。故需要四步握手。

【问题2】为什么TIME_WAIT状态需要经过2MSL(最大报文段生存时间)才能返回到CLOSE状态？
首先补充：MSL是TCP报文里面最大生存时间，它是任何报文段被丢弃前在网络内的最长时间。
答：虽然按道理，四个报文都发送完毕，我们可以直接进入CLOSE状态了，但是我们必须假象网络是不可靠的，有可以最后一个ACK丢失。所以TIME_WAIT状态就是用来重发可能丢失的ACK报文。在Client发送出最后的ACK回复，但该ACK可能丢失。Server如果没有收到ACK，将不断重复发送FIN片段。所以Client不能立即关闭，它必须确认Server接收到了该ACK。Client会在发送出ACK之后进入到TIME_WAIT状态。Client会设置一个计时器，等待2MSL的时间。如果在该时间内再次收到FIN，那么Client会重发ACK并再次等待2MSL。所谓的2MSL是两倍的MSL(Maximum Segment Lifetime)。MSL指一个片段在网络中最大的存活时间，2MSL就是一个发送和一个回复所需的最大时间。如果直到2MSL，Client都没有再次收到FIN，那么Client推断ACK已经被成功接收，则结束TCP连接。
或者换一种更舒服的解释方法：
1）、由于客户端A最后一个ACK可能会丢失，这样B服务端就无法正常进入CLOSED状态。于是B会重传请求释放的报文，而此时A如果已经关闭了，那就收不到B的重传请求，就会导致B不能正常释放。而如果A还在等待时间内，就会收到B的重传，然后进行应答，这样B就可以进入CLOSED状态了。
2）、在这2MSL等待时间里面，本次连接的所有的报文都已经从网络中消失，从而不会出现在下次连接中。

【问题3】为什么不能用两次握手进行连接？

答：3次握手完成两个重要的功能，既要双方做好发送数据的准备工作(双方都知道彼此已准备好)，也要允许双方就初始序列号进行协商，这个序列号在握手过程中被发送和确认。

现在把三次握手改成仅需要两次握手，死锁是可能发生的。作为例子，考虑计算机S和C之间的通信，假定C给S发送一个连接请求分组，S收到了这个分组，并发 送了确认应答分组。按照两次握手的协定，S认为连接已经成功地建立了，可以开始发送数据分组。可是，C在S的应答分组在传输中被丢失的情况下，将不知道S 是否已准备好，不知道S建立什么样的序列号，C甚至怀疑S是否收到自己的连接请求分组。在这种情况下，C认为连接还未建立成功，将忽略S发来的任何数据分 组，只等待连接确认应答分组。而S在发出的分组超时后，重复发送同样的分组。这样就形成了死锁。

【问题4】如果已经建立了连接，但是客户端突然出现故障了怎么办？

TCP还设有一个保活计时器，显然，客户端如果出现故障，服务器不能一直等下去，白白浪费资源。服务器每收到一次客户端的请求后都会重新复位这个计时器，时间通常是设置为2小时，若两小时还没有收到客户端的任何数据，服务器就会发送一个探测报文段，以后每隔75秒钟发送一次。若一连发送10个探测报文仍然没反应，服务器就认为客户端出了故障，接着就关闭连接。

【问题5】TCP最后一次ACK包没有送到就开始传输数据包，会发生什么？
服务端不会接收数据包，还会返回客户端一个RST包，也就是异常包。

tcp和udp的区别 1、连接方面区别 TCP面向连接（如打电话要先拨号建立连接）。 UDP是无连接的，即发送数据之前不需要建立连接。 2、安全方面的区别 TCP提供可靠的服务，通过TCP连接传送的数据，无差错，不丢失，不重复，且按序到达。 UDP尽最大努力交付，即不保证可靠交付。 3、传输效率的区别 TCP传输效率相对较低。 UDP传输效率高，适用于对高速传输和实时性有较高的通信或广播通信。 4、连接对象数量的区别 TCP连接只能是点到点、一对一的。 UDP支持一对一，一对多，多对一和多对多的交互通信。

6. 下列哪个IP地址可以分配给一台计算机?
256.1.3.4
197.3.11.0
199.5.89
11.15.33.235

互联网的网络地址分为A~E五类，其中
A类地址：0.0.0.0 ~ 127.255.255.255
主机号是后24位
B类地址：128.0.0.0 ~ 191.255.255.255
主机号是后16位
C类地址：192.0.0.0 ~ 223.255.255.255
主机号是后8位
D类地址：224.0.0.0 ~ 239.255.255.255
后28位为多播组号
E类地址：240.0.0.0 ~ 255.255.255.255
后27位待用
所以，A错。
主机号全为0的时候，表示一个网段
主机号全为1的时候，是一个指向网络的广播。
B代表一个网段。
C的话，代表了一个直接相连的网络。
D作为一个A类地址，是可以分配给一台计算机的。

首先A中网络号以197开头，则这是一个C类地址，但是该ip中主机号为0，则不可用；B中以主机号以240开头的IP到以255开头的IP为E类地址，目前不使用，同时这里是256超出范围，无法算作IP；C不能算作一个IP地址；D中为一个A类地址，可用；

可用的IP地址一般不是以0或255结尾，以0结尾的一般表示网络地址，255结尾的是广播地址，也就是说我们用的IP地址是1~254结尾之间的，这其中以1或254结尾的地址常常会用作网关地址，所以我们电脑用的ip后面一般是1~253或2~254之间的数结尾的

8. A,B两台机器都正常工作,B机器未监听任何端口.如果A机器向B机器80端口发送SYN包,会收到何种类型的回包?
RST包
ACK包
FIN包
无回应

RST包用来强制关闭TCP链接。 
什么时候发送RST包      
1. 建立连接的SYN到达某端口，但是该端口上没有正在监听的服务。       
2. TCP收到了一个根本不存在的连接上的分节。       
3. 请求超时。 使用setsockopt的SO_RCVTIMEO选项设置recv的超时时间。接收数据超时时，会发送RST包。

9. 
某学校获取到一个B类地址段,要给大家分开子网使用,鉴于现在上网设备急剧增多,管理员给每个网段进行划分的子网掩码设置为255.255.254.0,考虑每个网段需要有网关设备占用一个地址的情况下,每个网段还有多少可用的主机地址()
509
511
512
510

答案是A
因为子网掩码为255.255.254.0,第三段最后一位置能用,第四段8个位置都能用,所以可用地址为2^9=512,除去全1和全0,然后还要减去网关设备占用一个地址,所以为509

10.当我们在局域网内使用ping www.baidu.com时，哪种协议没有被使用：
ICMP
ARP
DNS
TCP

1、因为ping的话 后面跟的是地址，所以要先将域名转换为ip地址，即用到了DNS
2、获取到ip地址后，在数据链路层是根据MAC地址传输的，所以要用到ARP解析服务，获取到MAC地址
3、ping功能是测试另一台主机是否可达，程序发送一份ICMP回显请求给目标主机，并等待返回ICMP回显应答，（ICMP主要是用于ip主机、路由器之间传递控制信息，控制信息是指网络通不通，主机是否科大）
4、TCP的话，不涉及数据传输，不会用到
PING工作在应用层，直接使用网络层的ICMP，而未使用传输层的TCP、UDP
*/