---
author: oxolane
title: STL
date: 2020 未知
---

# pair

## 宣告

pair<型態,型態> 資料名稱;
```cpp
cin>>p.first;
cout<<p.first<<' '<<p.second<<endl;
```

## 優點

一次紀錄兩個東西 就是爽阿

可記錄x,y座標等等

*sort函式處理方便*

## 題目

[ZJ-a915](https://zerojudge.tw/ShowProblem?problemid=a915)

# vector

## 一個可改變大小的陣列

->陣列升級版

## 宣告 

vector<型態> 資料名稱;
```cpp
vector<int> vec;
```

## 輸入

```cpp
vector<int> vec;
rep(i,n){
    int a;cin>>a;
    vec.push_back(a);
    //將a個數字放入vec中
    cout<<vec[0]<<endl;
}
```
會輸出 剛剛輸入的a


## 輸出

跟陣列一樣使用 vec[5];
```cpp
vector<int> vec;//宣告
for(int x:vec){
    //一個變數x 他會按照順序等於vec內的數字
    cout<<x<<' ';輸出x
}
cout<<endl;
```
輸出結果：按照順輸出vec裡面的元素

## 其他功能

常見的:

* vec.begin() 開頭元素
* vec.end() 末端元素
* vec.push_back(Α) 在尾端新增Α這個數
* vec.emplace_back(Α) 在尾端新增Α這個數(較快)
* vec.size() 查大小
* vec.push_back(mack_pair(a,b))
* [更多](https://www.google.com/)

## 優點

伸縮自如

# stack

## 如同一碟盤子

## 後進去先出來

## 宣告 

stack<型態> 資料名稱;
```cpp
stack<int> st;//宣告放盤子的空間 名稱為st
```

## 輸入

```cpp
stack<int> st;
rep(i,n){
    int a;cin>>a;
    st.push(a);//將數字a放入這碟盤子最上層
}
```

## 輸出

```cpp
stack<int> st;
rep(i,n){
    int r=st.top();//r=這碟盤子最上面的數字
    st.pop();//從這碟盤子最上面拿掉一個盤子
    cout<<r<<' ';    
}
cout<<endl;
```

## 其他功能

常見的:

1. st.push(A) 在上面加上數字A
2. st.pop() 移除最上面數字
3. st.top() 回傳最上面的數字
4. st.size() 查大小
5. [更多](https://www.google.com/)

## 題目

- [ZJ-b923](https://zerojudge.tw/ShowProblem?problemid=b923)
- [UVa-12345](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3778)
- [UVa-514](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455)
- [ZJ-d016](https://zerojudge.tw/ShowProblem?problemid=d016)
- [UVa-673](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614)
- [POJ-3250](http://poj.org/problem?id=3250)

# queue

## 羽球筒
先進先出->FIFO

## 宣告 

queue<型態> 資料名稱;
```cpp
queue<int> qu;
```

## 輸入

```cpp
queue<int> qu;
rep(i,n){
    int a;cin>>a;
    qu.emplace(a);   
}
```

## 輸出

跟陣列一樣使用 vec[5];
```cpp
queue<int> qu;
rep(i,n){
    int r=qu.front();
    qu.pop();
    cout<<r<<' ';    
}
cout<<endl;
```

## 其他功能

常見的:

1. qu.push(A) 在後面加上數字A
2. qu.pop() 移除最前面數字
3. qu.front() 回傳最前面的數字
4. qu.size() 查大小
5. [更多](https://www.google.com/)

## 題目

[TIOJ-1013](https://www.google.com/)

# string

## 小孩才用char

升級版的char[]
不限字串長度大小

## 宣告

string 名稱;
```cpp
string str;//宣告存放字串的結構
string str[10];//宣告多個
```

## 輸入

```cpp
string str;
cin>>str;
```
以空格為段落

## 輸出

```cpp
//cout all
cout<<str<<endl;
//cout 指定位置
cout<<str[a]<<endl;
```

假設str="hello-world"

cout<<str[4]<<endl;

結果為o

## 其他功能

```cpp
str.size() 輸出大小
str3=str1+str2 字串相加
```
str1="fd",str2"dc"

str3="fddc"

## 優點

不用多開未知大小的char陣列

可以字串相加

# map

## 宣告

map<型態,型態> 名稱;
```cpp
map<string,int> m;
m["hihi"]=2;
//hihi 對應到2
```

## 其他功能

很沒效率的離散化

# set

## 介紹

不重覆元素集合

按照大小排序

## 宣告

set<型態> 名稱;
```cpp
set<int> s;
```

## 輸入

```cpp
set<int> s;
int a;cin>>a;
s.insert(s);
```

## 其他功能

```cpp
s.size() 查詢大小
*s.begin() 最小元素
```

# 基本STL結束!

## 遺珠之憾

另外還priority_queue以及deque(ㄉㄟˋㄎㄜˇ)

[Google](https://www.google.com/)

## **Q&A**  