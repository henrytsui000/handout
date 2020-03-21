---
author: oxolane
title: BCC
date: 2020 未知
---

# 先來看看題目吧

## 

給你一張圖

問有多少點集 在拔掉任何一條邊後

點內任兩點仍然相通

# BCC

## tarjan

把他轉成類似樹的結構

定義low函數為往下走若干次後 往上跳一次

最高能抵達的深度

## 

可以發現若low[u]>=deep[u]

則u以及他的子孫為BCC

# CODE

## 

```c++
const int maxn = 1e5+5;
int deep[maxn],low[maxn];
void dfs(int a,int pa){
    low[a]=deep[a]=deep[pa]+1;
    for(int x:edge[a])if(x!=pa){
        if(low[x])
            low[a]=min(deep[x],low[a]);
        else
            dfs(x,a);
        low[pa]=min(low[a],low[pa]);
    } 
    if(low[a]>=deep[pa]&&a!=0)
        cout<<"find:"<<pa<<' '<<a<<endl;
}
```

# 題目 Q&A

## 題目
- [ZJ-e270](https://zerojudge.tw/ShowProblem?problemid=e720)

## Q&A