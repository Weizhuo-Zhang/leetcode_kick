#一面面经
1. py2 和 py3 的区别
- 智能指针
- 几种排序(归并排序适用场景)
- 二叉树怎么中序遍历
- 最简单的01背包，只有重量，是否能装满

# 计算机网络
1. TCP/IP 三次握手四次挥手?

# 编程题
1. 桶排序

# 其他
1. socket编程


# 答案
## 一面
1. [py2 和 py3 的区别](https://www.runoob.com/python/python-2x-3x.html)
   - Print 函数:
      - py2: print语句
      - py3: print()函数
   - Unicode:
      - py2有ASCII str()类型，unicode()是单独的，不是byte类型
      - py3有了Unicode(utf-8)字符串，以及一个字节类: byte 和 bytearrays, py3源码文件默认使用utf-8编码。
    - 除法运算:
       - py2整数用 `/` 相除，结果还是整数
       - py3整数之间的相除，结果是浮点数
    - 异常
       - py2所有类型对象都可以直接被抛出。
       - py3使用 as 关键字，只有继承自`BaseException`的对象才可以被抛出
    - xrange
       - py2中`xrange()` 比 `range()`更快。
       - py3中只保留了`range()`结合了之前的`range()`和`xrange()`
    - 八进制字面量表示
       - py2支持`0o777`和`0777`表示八进制
       - py3只能用`0o777`表示
    - 不等运算符
       - py2不等于有两种写法`!=`和`<>`
       - py3不等于只有`!=`
    - 去掉了`repr`表达式
       - py2中反引号相当于`repr`函数的作用
       - py3中去掉了反引号的写法，只能用`repr`函数
    - 数据类型
      - py3去掉了long类型
      - py3新增了bytes类型
      - str对象和bytes对象可以用`.encode()(str -> bytes)`和`.decode()(bytes->str)`方法相互转化
      - `dict.has_key()`去掉了，用`in`代替，dict的`.keys(), .items(), .values()`返回迭代器，之前的`iterkeys()`等函数被废弃。
    - 打开文件
       - py2: `file(...) or open(...)`
       - py3: 只有`open(...)`
    - 键盘输入
       - py2: `raw_input("提示信息")`
       - py3: `input("提示信息")`
- s