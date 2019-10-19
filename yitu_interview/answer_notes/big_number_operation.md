# 大数(加、减、乘、除、低精度*大数)模版详解（C++)
[原文地址](https://blog.csdn.net/wjb820728252/article/details/60583658)

## 1. 大数背景简介
- **什么是大数**
   * 大数就是高级语言(C, C++)的基本数据类型的最大长度都装不下的数据，例如：(1234567899876543211234567896542132165465)，这些只能用字符数组(`char []`)或者字符串(`string`) 来处理，大数操作最基础的四个操作就是：大数加法、大数减法、大数乘法、大数除法。

- **C++ 中 `string` 的优点**:
   - `string` 可以像C的字符串一样用下标直接访问索引值所对应的字符。

   ```c
   string str = "123456789123123";  // Init a string
   str[i];     // return the value in i which does not check whether is out of bound
   str.at(i);  // This checks whether is out of bound
   
   ```
   
   - `string` 重载了一些运算符，特别注意当目标串较小，无法容纳新的字符串，系统会自动分配更多的空间给目标串，不必顾虑出界
   - `string` 字符串之间的赋值不再需要像C那样移动数组或者用 `strcpy()` 等函数辅助，`string` 类可以直接赋值

   ```c
   str1 = str2;
   str1 += str2;
   str1 + str2;
   ```
   
   - `string` 字符串之间的比较也不需要用 `strcmp()` 等函数来比较，可以直接用 `<>==`

   ```c
   str1 == str2;       //比较串是否相等，返回布尔值
   str1 != str2;       
   
   str1 <  str2;		   //基于字典序的比较，返回布尔值
   str1 >  str2;
   str1 <= str2;
   str1 >= str2;
   ```
   
   - `string`字符串还有一个标准且强大的STL库，里面提供了许多非常便利有用的辅助函数，如 `str.erase ()`函数（详细介绍这个，因为下面算法经常利用到

- **erase函数的原型如下：**
   - `string& erase ( size_tpos = 0, size_t n = npos );`(常用)

| Name | Description |
|------|-------------|
|作用|从下标size_t pos开始，去掉size_t n个字符|
|例子|str=”023543”|
|用法|str.erase(0,1);|
|结果|str=“23543”|

   - `iterator erase ( iteratorposition );`

| Name | Description |
|------|-------------|
|作用|去掉一个下标为：position的字符|
|例子|str=”023543”|
|用法|str.erase(0);|
|结果|str=“23543”|

   - `iterator erase ( iterator_first, iterator_last );`
 
| Name | Description |
|------|-------------|
|作用|删除从first到last之间的字符（first和last都是迭代器）|

## 大数加法
- **原理：**
首先我们要对字符串进行初始化处理，就是给它们前面补上一个‘0’，防止有进位，如果没有进位我们最后可以用erase()函数将其删掉，然后直接对字符串进行操作，从字符串尾开始操作，往回对应相加，如果相加的结果>10，那么前一个字符就要加上当前字符的进位，当前字符就只保留结果个位数

- **式例: S1=82, S2=74**

| 步骤 | 说明 | S1 | S2 |
|-----|------|----|----|
| 1   | 对位。在被加数和加数前面适当的补0，使他们的包含相同的位数 | 82 | 74 |
| 2   | 前面再补一个0，确定和的最多位数 | 082 | 074 |
| 3   | 从低位开始，对应位相加，结果写入被加数中。如果有进位，直接给被加数前一位加1 | 086 | 074 |
|     |      | 156 | 074 |
|     |      | 156 | 074 |
| 4   | 删除和前面多余的0 | 156 | 074 |

```c
string bigNumberAddInteger(string str_1, string str_2) {
    for (int i = str_1.length() - 1; i >= 0; i--) {
        int num_1 = str_1[i] - ZERO;
        int num_2 = str_2[i] - ZERO;
        if (num_1 + num_2 > 9) {
            str_1[i - 1] = str_1[i - 1] - ZERO + 1 + ZERO;
            str_1[i] = (num_1 + num_2) - 10 + ZERO;
        } else {
            str_1[i] = (num_1 + num_2) + ZERO;
        }
    }
    if (str_1[0] == ZERO) {
        str_1.erase(0, 1);
    }
    return str_1;
}
```

## 大数减法
- **原理：**
减法操作和加法操作类似，首先先初始化，保持输入都是大数减小数，然后从低位开始对应相减，不够减就从借位减一。
- **式例: S1=82, S2=74**

| 步骤 | 说明 | S1 | S2 |
|-----|------|----|----|
| 1   | 对位。在被减数和减数前面适当的补0，使他们的包含相同的位数 | 82 | 74 |
| 2   | 从高位开始，对应位相减，结果写入被减数中。如果需要借位，直接给被减数前一位减1 | 12 | 74 |
|     |      | 08 | 74 |
| 2   | 删除和前面多余的0 | 8 | 774 |

## 大数乘法
## 大数除法