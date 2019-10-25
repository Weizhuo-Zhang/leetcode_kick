# leetcode_kick

## LeetCode Cheat code
下面这段代码能显著提高LeetCode的C++运算速度，使用printf和scanf来代替iostream。
```c
static const auto fasterIO = [](){
    // use printf and scanf instead of cout and cin
    std::ios::sync_with_stdio(false);
    // untie cin and cout
    std::cin.tie(nullptr);
    return nullptr;
}();
```