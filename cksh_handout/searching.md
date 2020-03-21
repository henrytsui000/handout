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
        cout<<"i"<<endl;//按照順序找到a
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
int l=0,r=n;//下界是0,上界是最大
//另外
while(l<r-1){
    int mid=(r+l)/2;//mid是中間
    if(arr[mid]==A){//中間＝要找到的->輸出
        cout<<mid<<endl;
    }else if(arr[mid]>A){
        r=mid;//中間的數字比較大 所以我們把上界改成中間
    }else{
        l=mid;//中間數字小 所以我們把下界提昇
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