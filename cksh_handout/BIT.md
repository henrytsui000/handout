---
author: oxolane
title: BIT
date: 2020 未知
---

# 先來看看題目吧

## 

給你一個長度為N的數列

Q次詢問區間${l,r}$總和
R次修改單點數值
N,Q,R<1e5

## 暴力查詢？

複雜度 O(QN+R)

好像沒有很好

## 前綴合之後暴力修改？

複雜度O(Q+NR)

並沒有比較好

## BIT!

可以作到O((Q+R)×logN)!

# Binary Indexed Tree

## 結構

構造一個陣列
每個點紀錄該點至他和2的冪次最大公因數之前的點
ex. 
點6->gcd(6,2^N^)=2 ->紀錄(6-2,6]=[5,6]
點9->gcd(9,2^N^)=1 ->紀錄(9-1,9]=[9,9]
點12->gcd(12,2^N^)=4 ->紀錄(12-4,12]=[9,12]

## 圖例-維護範圍

維護範圍

![](https://i.imgur.com/nL8VWMI.png)

## 圖例 維護數值

維護數值

![](https://i.imgur.com/RSZrln9.png)

# 查詢

## 查詢區間[1,9]

$\Sigma$ $arr$~1-9~=bit[8]+bit[9]

![](https://i.imgur.com/At49S28.png)

## 查詢區間[3,9]

[3,9]=[1,9]-[1,3]

=bit[8]+bit[9]-(bit[2]+bit[3])

![](https://i.imgur.com/MVfViDW.png)

## 時間複雜度

O(logN)

# 修改

## 
可發現其實更動點c

只需要連帶修改>c的c+(2的冪次)

![](https://i.imgur.com/s2rOy01.png)

## 時間複雜度

O(logN)

# CODE

## 小技巧

利用位元運算可知道

x&(-x)會得到x+該數值可到達最近的維護位置

#define lowbit(x) (x&(-x))

## 建立/修改

觀察後可知道建立第c位置時

等價於在原本更新到c-1的bit中增加位置c的值

因此從位置c開始一路修改到邊界即可

```c++
void chg(int c,int val){
    for(;c<=N;c+=lowbit(c))
        bit[c]+=val;
}
```

## 查詢

從點c一路往前查到2的冪次即可

```c++
int qry(int c){
    int ret=0;
    for(;c;c-=lowbit(c))
        ret+=bit[c];
    return ret;
}
```

# 題目QA

## 題目

- [ZJ-d788](https://zerojudge.tw/ShowProblem?problemid=d788)

- 離散化

## Q&A