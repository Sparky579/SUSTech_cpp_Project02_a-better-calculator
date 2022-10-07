# SUSTech_cpp_Project02_a-better-calculator

## 项目描述

本项目是 SUSTech CS205 C/C++ Design 的第 2 个大作业（Project02 A Better Calculator）。

项目主要实现了高精度数值型数据（即高精度小数）的计算器。

- 高精度支持：支持在`scale` 精度下的 `+ - * / % ^` 和数学函数的数值计算。
- 运算效率高： `+ - * / %` 全部采用 $O(n \log_2 n)$ 的做法，其他数学函数的效率也不低于 $O(n^2 \log_2 n)$，可以轻松对 $10^3$ 级别有效数字的数据实现快速计算。
- 多运算符和数学函数支持：项目实现了`+ - * / % ^` 运算以及 `sqrt()` （开根号）`trunc()`（截取整数）`floor()`（向下取整）`ceil()`（向上取整）`exp()` （自然指数）`ln()` （自然对数）`fac()` （阶乘）`sin()/cos()/tan()` （三角函数）`arcsin()/arccos()/arctan()` （反三角函数）等数学函数。
- 一些人性化设计：自动忽略输入表达式的所有空格、错误信息提示、多括号输入、科学记数法输入等。

## 如何运行

项目支持推荐在 `Ubuntu` 环境下运行。

1. 使用命令  `git clone https://github.com/Maystern/SUSTech_cpp_Project02_a-better-calculator.git` 将项目下载到当前目录。
2. 在当前目录中执行