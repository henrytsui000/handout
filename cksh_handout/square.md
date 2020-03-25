---
author: 建議用firefox閱讀
title: 分塊
date: 2020 未知
---

# 分塊演算法

## 
因為題目通常會有嚴謹的時間限制 

所以我們必須將超時的演算法加速

## 求最大值

如果給大小N一個陣列 

並且Q次操作：

1. 詢問區間$[l,r]$最大值

2. 修改某點的數值

暴力：時間複雜度：$O(Q×N)$

## 如果我們將陣列切成R塊

如標題 我們可以將陣列切成R塊

並且預處理每一塊區間的最大值

![](https://i.imgur.com/T3xxH5T.png)

## 查詢

查詢只要將兩端暴力完成+中間的預處理

時間複雜度：$O(Q×\frac{N}{R})$

![](https://i.imgur.com/iwXArB0.png)

## 修改

我們只需要找到那一塊包含修改點

更改該塊的數值就可了

## 怎麼切可以讓時間最少呢?

先來分析worst case:

詢問數列第2至N-1個

那我們需要省略中間的$\frac{N}{R}-2$塊

並且暴力求頭尾的部份


## 為什麼切$\sqrt{N}$塊
$Find$ $R$ $s.t.$ $f(R)=\frac{N}{R}-2+2(R-1)$ $min$

$when$ $\frac{N}{R}=2R,f(R)$ $min$ -> $R=\sqrt{\frac{N}{2}}$

為了計算方便 我們會取$R=\sqrt{N}$

# CODE

## 建立

```c++
const int maxn = 1e5+5;
int arr[maxn],block[maxn],sq;

int main(){
    int n;cin>>n;sq=sqrt(n);
    rep(i,n)
        cin>>arr[i];
    rep(i,sq)
        rep(j,sq)
            block[i]=max(i*sq+j);
}
```

## 查詢

```c++
int qry(int l,int r){//qry[l,r]
    int res=0;
    int L=l/sq,R=(r+1)/sq;
    //L,R為分塊的開始塊/結束塊的後一塊
    for(int i=l;i<L*sq;i++)
        res=max(res,arr[i]);
    for(int i=L;i<R;i++)
        res=max(res,block[res]);
    for(int i=sq*(1+r/sq);i<=r;i++)
        res=max(res,arr[i]);
    return res;
}
```

## 修改
```c++
void chg(int x,int val){
    arr[x]=val;
    block[x/sq]=min(block[x/sq],val);
}
```

# 題外話

## 
之後會線段樹 功能比分塊演算法好很多

可以暫時不用到精通

但往後的莫隊演算法會需要分塊

# Q&A