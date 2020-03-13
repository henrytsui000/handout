---
author: oxolane
title: searching&sort
date: 2020 未知
---

# 先來看看題目吧

## 
給你一個遞增數列a[n]跟數字A

找出A在第幾項

# 從第一項往後找 直到找到他

## CODE
```cpp
int arr[n];
rep(i,n){
    if(arr[i]==A)
        cout<<"i"<<endl;
}
```

## O(N)

# ![](https://i.imgur.com/WrcSigs.jpg)

# 二分搜?

## 作法

先查詢數列中間的值

if >A 答案在(中間,最後]

否則 答案在[開始,中間)

不斷做這動作

## CODE
```cpp
int l=0,r=n;
while(l<r-1){
    int mid=(r+l)/2;
    if(arr[mid]==A){
        cout<<mid<<endl;
    }else if(arr[mid]>A){
        r=mid;
    }else{
        l=mid;
    }
}
```

## O(log N)

# 題目 Q&A

## 題目
有單調性的東西都可以二分搜

若沒有順序性 通常會利用sort使數列單調

- [ZJ-d732](https://zerojudge.tw/ShowProblem?problemid=d732)

- [APCS-基地台](https://zerojudge.tw/ShowProblem?problemid=c575)

- [ZJ-b966](https://zerojudge.tw/ShowProblem?problemid=b966)

- [ZJ-c268](https://zerojudge.tw/ShowProblem?problemid=c268)

- [CF-1260B](https://codeforces.com/contest/1260/problem/B)