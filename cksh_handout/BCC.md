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

可以發現若low[u]>deep[u]

則u以及他的子孫為BCC

# CODE

## 

```c++
void dfs(int a,int pa){

    
}

```