/*
1. 
关于求和函数，以下说法正确的是（）

sum返回表达式中所有数的总和，因此只能用于数字类型的列
Avg返回表达式中所有数的平均值，可以用于数字型和日期型的列
Max和Min可以用于字符型的列
Count可以用于字符型的列

题目问的  关于求和函数！！！！！！
不考虑题目的话 1，3，4 都是对的。

2. 关系数据库所采用的数据存放形式是（）

二维表
链表
网状
二叉树

A ---每一行对应一条记录，每一列对应（实体/关系）一项属性

3. 不属于SQL语句的是（）

SELECT
CANCEL
UPDATE
ALTER

B
select是选择语句
update是数据更新语句
alter是修改语句

4.
设有表示学生选课的三张表，学生S（学号，姓名，性别，年龄，身份证号），课程C（课号，课名），选课SC（学号，课号，成绩），则表SC的关键字（键或码）为（  ）。
课号，成绩
学号，成绩
学号，课号
学号，姓名，成绩
正确答案：C
题目解析：
学号是学生表S的主键，课号是课程表C的主键，所以选课表SC的关键字就应该是与前两个表能够直接联系且能唯一定义的学号和课号，所以选择C。

5. 某关系表有：员工（部门编号，部门名称，员工编号，姓名，性别，年龄），则其主码为（）。

部门编号、员工编号
员工编号
姓名
部门编号

正确答案：A
题目解析：
由于一个员工可能属于多个部门（如CEO等），所以主码应该选A。
注意：本题并没有考察是否符合某种范式，请仔细阅读题意，不要自设条件。

6. 将实体-联系模型转换为关系模型时，实体之间多对多联系在关系模型中的实现方式是（  ）
建立新的关系
建立新的属性
增加新的关键字
建立新的实体

正确答案：A
题目解析：
将实体-联系模型转换为关系模型时，一个m:n的联系可以转换为一个独立的关系模式，与该联系相连的各实体的码及联系本身的属性均转换为关系的属性，而关系的码为各实体码的组合。故本题答案为A选项。

7. 下列四项中，不属于数据库系统特点的是（ ）

数据共享
数据完整性
数据冗余度高
数据独立性高

数据库系统的特点：
1.数据结构化
2.数据共享性高，冗余度低且易扩展
3.数据独立性高
4.数据由数据库管理系统统一管理个控制

8. 在使用 limit 子句时，如果没有足够的行，则：
MySQL会报错
MySQL将只返回它能返回的那么多行
MySQL将不会返回任何行

B

9.
定义学生、教师和课程的关系模式STC(SNO，SN，SA，TN，CN，G)，其中的六个属性分别为学生的学号、姓名、年龄、教师的姓名、课程名以及学生的成绩，则该关系为（  ）。
第一范式
第二范式
第三范式
BCNF范式

范式是符合某一种级别的关系模式的集合。关系数据库中的关系必须满足一定的要求，满足不同程度要求的为不同范式。目前关系数据库有六种范式：第一范式（1NF）、第二范式（2NF）、第三范式（3NF）、Boyce-Codd范式（BCNF）、第四范式（4NF）和第五范式（5NF）。满足最低要求的范式是第一范式（1NF）。在第一范式的基础上进一步满足更多要求的称为第二范式（2NF），其余范式以次类推。一般说来，数据库只需满足第三范式（3NF）就行了。 第一范式：主属性（主键）不为空且不重复，字段不可再分（存在非主属性对主属性的部分依赖）。 第二范式：如果关系模式是第一范式，每个非主属性都没有对主键的部分依赖。 第三范式：如果关系模式是第二范式，没有非主属性对主键的传递依赖和部分依赖。 BCNF范式：所有属性都不传递依赖于关系的任何候选键。 题目中关系模式STC满足第一范式，但不满足第二范式。故本题答案为A选项。
*/