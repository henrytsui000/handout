---
author: 建議用firefox閱讀
title: Sparse table
date: 2020 未知
---

# RMQ?

## $_{Range \; Minimum/Maximun \; Query}$

求區間最大/最小值

# Sparse Table

## 初始化

建立一個表格
st[a][b]代表[b,b+2^a^]中的最大值


## 
st[a][b]=st[a-1][b]+[a-1][b+2^a-1^]

![](https://i.imgur.com/0Q1wtsG.png)


## CODE

```cpp
rep(i,n)
    cin>>st[0][i];
for(int i=1;(1<<i)<=n;i++){
    for(int j=0;j+(1<<i)<=n;j++){
        st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
}
```


## 查詢

如果要查[$l,r$]的max值
設lg = log~2~($r-l+1$)

也就是 $l$+2^lg^ ≦ r ＜ $l$+2^(lg+1)^

則可以尋找max([$l$,$l$ + 2^lg^] , [ $r$ -2^lg^ , $r$ ])
![](https://i.imgur.com/VNaDc2R.png)


## CODE

```cpp
int rmq(int l,int r){
    int k=__lg(r-l+1);
    return max(st[k][l],st[l][r-(1<<k)+1]);
}
```


# 時間複雜度


## 初始化 

O(NlogN)

## 查詢 

O(1)

# 題目 QA

## 題目

- 經典RMQ
- [ZJ-d539](https://zerojudge.tw/ShowProblem?problemid=d539)
- [ZJ-b687](https://zerojudge.tw/ShowProblem?problemid=b687)

## Q&A