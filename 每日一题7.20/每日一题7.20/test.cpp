/*
1. 负责数据库中查询操作的数据库语言是______。

A．数据定义语言
B．数据管理语言
C．数据操纵语言
D．数据控制语言

C
[解析] 本题考查的知识点是数据库语言。数据库语言包括如下三点。
・数据定义语言(DDL)及其翻译程序：主要负责数据的模式定义与数据的物理存取构建。
・数据操纵语言(DML)及其编译(或解释)程序：主要负责数据的基本操作，包括查询及增加、删除、修改等操作。
・数据控制语言：主要负责解释每个控制命令的含义，决定如何去执行控制命令。
2. 数据库管理系统是（　　）。
A . 操作系统的一部分
B . 在操作系统支持下的系统软件
C . 一种编译系统
D . 一种操作系统

B。【解析】数据库系统属于系统软件的范畴。

3. SQL 语句中修改表结构的命令是______。

A．ALTER TABLE
B．MODIFY TABLE
C．ALTER STRUCTURE
D．MODIFY STRUCTURE
在Visual FoxPro中，修改表的结构有两个命令：
ALTER TABLE：用SQL命令修改表的结构；
MODIFY STRUCTURE：在表设计器中修改表的结构； 
题目要求是SQL语句中修改表结构的命令，所以命令是ALTER TABLE。

4. 
订单表 ( 订单号，雇员代号，地区代号，订购日期 ) 中订单号为主键，要删除订单中前三年以前的信息， SQL 为：

delete from 订单表 where 订购日期<getdate()+3
delete from 订单表 where 订购日期<DATEADD(yy,3,getdate())
delete from 订单表 where 订购日期<getdate()-3
delete from 订单表 where 订购日期<DATEADD(yy,-3,getdate())

delete from 订单表 where 订购日期<DATEADD(yy,-3,getdate())
DATEADD() 函数在日期中添加或减去指定的时间间隔。
语法
DATEADD(datepart,number,date)
datapart参数的取值范围是{yy/yyyy,qq/q,mm/m,dy/y,dd/d,wk/ww,dw/w,hh,mi/n,ss/s,ms,mcs,ns}
number 是您希望添加的间隔数
date 参数是合法的日期表达式

5. 下列关于视图的说法中错误的是______

A．视图是从一个或多个基本表导出的表，它是虚表
B．视图可以被用来对无权用户屏蔽数据
C．视图一经定义就可以和基本表一样被查询和更新
D．视图可以用来定义新的视图

正确答案
C
答案解析
视图一经定义之后就可以进行查询操作了，与基本表一样，并无差别。但是一般只对“行列子集视图”才能更新。

6. 
在学生表 Student 的系别 (Sdept) 属性中查询信息系 (IS) 、数学系 (MA) 和计算机系 (CS) 的学生姓名 (Sname) 和性别 (Ssex) ，正确的命名格式应为：

SELECT Student FROM Sname, Ssex WHERE Sdept IN (‘IS’, ’MA’, ‘CS’)
SELECT Sname, Ssex FROM Student WHERE Sdept IN (‘IS’, ’MA’, ‘CS’)
SELECT Sname, Ssex FROM Student WHERE Sdept (IS, MA, CS)
SELECT Sname, Ssex FROM Student WHERE Sdept LIKE IS, MA, CS

B
select后写上需要选择的列名，from表名，where后写选择条件，要求查询这三个系的学生使用in进行选择，in后面写系名的可能值，如果查询到的数据系名在可能值中则被选中

7.
SQL 查询语句中 WHERE 、 GROUP BY 、 HAVING 这些关键字区别和用法总结错误的是（）

HAVING在查询语句中必须依赖于GROUP BY
WHERE子句用来限制SELECT语句从表中指定选取的行
GROUP BY子句用来分组WHERE子句的输出结果集
HAVING子句用来从分组的结果中筛选列

HAVING 子句
在 SQL 中增加 HAVING 子句原因是，WHERE 关键字无法与聚合函数一起使用。
HAVING 子句可以让我们筛选分组后的各组数据。

10. 
一个关系数据库文件中的各条记录（） 。

前后顺序不能任意颠倒，一定要按照输入的顺序排列
前后顺序可以任意颠倒，不影响库中的数据关系
前后顺序可以任意颠倒，但排列顺序不同，统计处理的结果就可能不同
前后顺序不能任意颠倒，一定要按照关键字字段值的顺序排列

一个关系表中的数据就是数据集. 无序
*/