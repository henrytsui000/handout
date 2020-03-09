---
author: oxolane
title: LCA
date: 2020 未知
---

# 先來看看題目吧

## 
給你一顆N個點樹跟樹上兩點u,v

詢問Q次u,v的最近共同祖先

ex. (u,v)=(8,11),LCA=4

![](https://i.imgur.com/bpstHrx.png)

##
為了方便

我們設定v會比u深或一樣 且樹的深度≦2^d^

# 作法

## 
我們可以先把v往上走到跟u深度一樣的

然後一起往上走

直到遇到同一個點

## 走到一樣高

![](https://i.imgur.com/A4j5Yqi.png)

## 往上找到LCA

![](https://i.imgur.com/PCT6ZjC.png)

## 時間複雜度

若先紀錄每一個點的父節點則O(N+QN)=O(QN)

一次DFS處理深度+走到一樣高+往上找LCA

# ![](https://i.imgur.com/WrcSigs.jpg)

# 倍增法

## 
我們可以預先紀錄每個點上方2的冪次的節點

f[a][b]為b節點上方2^a^的節點

![](https://i.imgur.com/bpstHrx.png)

![](https://i.imgur.com/i3CXTVh.png)

## 
當深度不一樣時

知道v要往上爬deep[v]-deep[u]=x

使用類似快速冪的想法

將x拆成多個2的冪次相加組成

## 
ex.x=13=2^3^+2^2^+2^0^

若要將點v往上爬13

->v往上爬2^3^後

該點再往上2^2^，最後在爬2^0^

deep[f[0][f[2][f[3][v]]]]=deep[u]

## 深度一樣後
可以先觀察上方2^d^是不是一樣

然後往下尋找2^d-1^是否一樣

直到找到一個點對不相同 則(u,v)一起往上移動

然後對於新的點做一樣的事情

直到他們父節點相同 輸出父節點

## 優化-1

因為f[x][v]=f[x-1][f[x-1][v]]

因此建表的時候不用每個都重新計算

## 優化-2

可以發現前一次往上2^k^時

下一次一定往上小於2^k^距離

不然一開始往上2^k^×2就好啦

## 優化-3

往上找時 可以利用二分搜的技巧

增快找到目標的速度

但是範圍只有1~16

速度增加也不多 沒必要增加實做難度

## 時間複雜度

建表O(NlogN)

查詢O(logN)

總共O(N+logN+QlogN)

~優化3可將詢問改成O(log(logN))~

# 圖例

## 走到一樣高
已經一樣高了

![](https://i.imgur.com/8kqs2iJ.png)

## 發現2^1^不相同

往上爬

![](https://i.imgur.com/GdRUtEc.png)

## 發現2^1^相同

不做動作

![](https://i.imgur.com/GdRUtEc.png)

## 輸出父親

![](https://i.imgur.com/qLkS2KH.png)

# CODE

## CODE-dfs建表

```c++
void dfs(int a,int pa){
    f[0][a]=pa;
    for(int x:edge[a]){
        deep[a]=deep[pa]+1;
        dfs(x,a);
    }
}
int main(){
    dfs(0,-1);
    for(int i=1;i<=d;i++)
        rep(j,n)
            f[i][j]=f[i-1][f[i-1][j]];
}
```

## CODE-爬到一樣高

```c++
int main(){
    int u,v;cin>>u>>v;
    if(deep[u]>deep[v])
        swap(u,v);
    int x=deep[v]-deep[u];
    for(int i=d;i>=0;i--)
        if(deep[f[v][i]]<=deep[u])
            v=f[v][i];
}
```

## CODE一起向上找LCA

```c++
int main(){
    for(int i=d;i>=0;i--)
        if(f[u][i]!=f[v][i])
            u=f[u][i],v=f[v][i];
    cout<<"LCA:"<<f[u][i]<<endl;
}
```

# 利用時間戳章

## 
1. 陣列A紀錄dfs經過點的順序 (2n-1個點)

2. 按照A的順序紀錄深度，陣列f紀錄第一次經過點i的時間

3. 對A做RMinQ (f[u],f[v]) 求出LCA的深度跟點

# 題目Q&A

## 題目
- [ZJ-d767](https://zerojudge.tw/ShowProblem?problemid=d767)

## Q&A