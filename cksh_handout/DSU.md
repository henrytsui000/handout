---
author: oxolane
title: DSU
date: 2020 未知
---

# DSU併查集

## disjoinset and union???

## 來看看題目ㄅ

所有元素P編號1,2,3...,N

對於P中的任意元素p一定恰有一集合包含該元素

要支援以下兩種操作

1. 輸入a,b定他們為同一集合 

2. 請輸出兩數a,b是否為同一集合

## 

保證a>b 否則swap(a,b)

開一個陣列arr[]

arr[n]代表n跟arr[n]為同集合

並且有老大k,使arr[k]=k

若a指向的人不斷回朔的結果 = b指向的人不斷回朔的結果
則他們是同集合

# 優化-路徑壓縮


## 如果所有元素形成長長的一條練狀

->那查詢相同則需要O(N)

## 那就把所有同群元素指向一個元素！

# 啟發式合併

## 當要合併兩個集合時

把小的合併到大的會比較快

# CODE

## 追朔

```cpp
int fnd(int a){
    return arr[a]==a ? a:arr[a]=fnd[arr[a]]; 
}
```

## 和併

```cpp
void uni(int x,int y){
    x=fnd(x),y=fnd(y);
    if(f[x]==f[y])
        return ;
    if(sz[x]<sz[y])
        swap(x,y);
    sz[x]+=sz[y];
    f[y]=x;
}
```

## 查詢

```cpp
bool same(int a,int b){
    return fnd(a)==fnd(b);
}
```

## 來看看實做吧

```cpp
#include <bits/stdc++.h>using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

const int maxn =1e5+5;
int f[maxn];
int sz[maxn];

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
        uni(a,b);
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        if(f[fnd(a)]==f[fnd(b)])
            cout<<"same"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}
```

# 題目們

## 

[SKYOJ-56](https://www.google.com/)

[POJ-1182](http://poj.org/problem?id=1182)

## Q&A