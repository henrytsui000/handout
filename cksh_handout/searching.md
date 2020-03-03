---
author: oxolane
title: searching
---

# 一個嚴格遞增的數列
## 找出A在第幾項

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

# 題外話&題目

## 題目
有單調性的東西都可以二分搜

[ZJ-d732](https://zerojudge.tw/ShowProblem?problemid=d732)

[APCS-基地台](https://zerojudge.tw/ShowProblem?problemid=c575)

[CF-1260B](https://codeforces.com/contest/1260/problem/B)