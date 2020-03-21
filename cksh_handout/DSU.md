---
author: oxolane
title: DSU
date: 2020 未知
---

# 先來看看題目ㄅ

## 

所有元素P編號1,2,3...,N

對於P中的任意元素p一定恰有一集合包含該元素

要支援以下兩種操作

1. 輸入a,b定他們為同一集合 

2. 請輸出兩數a,b是否為同一集合

## 

保證a>b 否則swap(a,b)

開一個陣列arr[]

arr[n]代表n跟arr[n]為同集合

# 優化-路徑壓縮

## 如果所有元素形成練狀

->那查詢相同則需要O(N)

## 把所有同群元素指向一個元素！

# 啟發式合併

## 當要合併兩個集合時

把小的合併到大的會比較快

# CODE

## 追朔

```cpp
void fnd(int a){
    if(arr[a]==a) return a;//自己是最前面的數字則結束
    else return fnd(arr[a]);//往前繼續尋找
}
```

## 查詢
```c++
bool same(int a,int b){
    if(fnd(a)==fnd(b)) return true;
    //如果自己最前面跟別人相同則在同一集合
    else return false;
}
```

## 合併
```c++
void uni(int a,int b){
    if(a>b) swap(a,b);
    //保證a總是比較小
    arr[b]=a;
}
```

# 優化後CODE

## 追朔

```cpp
int fnd(int a){
    return arr[a]==a ? a:arr[a]=fnd[arr[a]]; 
    //like dp 不是最前面則繼續往前 
    //        並把路上的點也改成最前面的
}
```

## 和併

```cpp
void uni(int x,int y){
    x=fnd(x),y=fnd(y);
    //將x,y修正成最前面的點
    if(f[x]==f[y])return ;
    //本來就在同集合則不用理會
    if(sz[x]<sz[y]) swap(x,y);
    //sz陣列紀錄集合們的大小 
    sz[x]+=sz[y];
    //合併後x集合變成x+y的大小
    f[y]=x;
    //純修改
}
```

## 查詢

```cpp
bool same(int a,int b){
    return fnd(a)==fnd(b);
    //最前面的點相同則回傳true
}
```

## 來看看實做吧

```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

const int maxn =1e5+5;
int f[maxn];//紀錄自己的指向
int sz[maxn];//紀錄大小

int fnd(int x){
    return f[x]==x? x:f[x]=fnd(f[x]);
}

void uni(int x,int y){
    x=fnd(x),y=fnd(y);
    if(f[x]==f[y])
        return ;
    if(sz[x]<sz[y])
        swap(x,y);
    sz[x]+=sz[y];
    f[y]=x;
}

void init(int n){
    rep(i,n){
        sz[i]=1;
        f[i]=i;
    }
}

int32_t main(){
    int n;
    cin>>n;
    init(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        uni(a,b);//把集合a,b合併
    }
    int q;cin>>q;
    while(q--){
        //共有q比詢問 問a,b是否相同集合
        int a,b;
        if(f[fnd(a)]==f[fnd(b)])
            cout<<"same"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}
```

# 題目們

## 題目

[SKYOJ-56](https://pc2.tfcis.org/dev/index.php/problem/view/56/)

[POJ-1182](http://poj.org/problem?id=1182)

## Q&A