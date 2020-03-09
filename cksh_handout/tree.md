---
author: oxolane
title: 樹
date: 2020 未知
---

# 樹 資料結構

## struct

如果樹有固定數量的子節點

我們可以蓋一個struct作為節點

紀錄他的小孩，本身數值

## CODE

```c++
struct Node{
    int val;
    Node *lc,*rc;
}root;
```

## dfs
```c++
void dfs(Node nd){
    //do something
    dfs(nd->lc);
    //do something
}
```

# 二元搜尋樹

## 
一顆每個節點皆有兩個子節點

- 使每個左子節點<該節點

- 使每個右子節點>該節點

## 加值

從根開始往下走

大於節點就往右 否則往左走

在最後的葉節點增加一個新節點

## 查詢
如同加值 往下走之後即可找到

時間複雜度：碰撞不嚴重O(logN) 嚴重碰撞O(N)

# 最小生成樹 MST

## 
給你n個點

以及任兩點之間連接需要的代價

問把n個點變成連通塊的最低總代價

## Prim's Algorithm

1. 將所有邊的代價由小到大排序

2. 從最小開始看加入此邊是否會使不連通得兩個點連通

3. 加入此邊

4. 回到第2步驟 直到完成MST

(用DSU查詢兩個點的連通狀況)

## Kruskal's Algorithm

設定X=(一條邊就可抵達且目前不連通的某個點)

1. 隨便找一個點作為基礎連通塊

2. 不斷更新 基礎連通塊走到X 所需的最低代價

3. 找出所有X中代價最低的點/連接的邊

4. 加入此邊 

5. 回到第二步 直到完成MST

# 樹壓平

## 時間戳章

用陣列紀錄點在dfs時的抵達/離開順序

以及紀錄dfs時抵達點的順序

~離開不用增加時間~

範例在右頁

## 性質

當兩點u,v:

in_time[u] < in_time[v]且out_time[u] ≥ out_time[v]

則u為v祖先

# 範例

## 

![](https://i.imgur.com/WJs3oCm.png)

## 

![](https://i.imgur.com/3XcEUey.png)

## 

![](https://i.imgur.com/bC0FBK6.png)

## 

![](https://i.imgur.com/iyn37mp.png)

## 

![](https://i.imgur.com/UHs4Wl7.png)

## 

![](https://i.imgur.com/HCWnJAA.png)

## 

![](https://i.imgur.com/mH6ABZS.png)

## 

![](https://i.imgur.com/NR2taAH.png)

## 

![](https://i.imgur.com/WHTfRvt.png)

## 

![](https://i.imgur.com/KoOSpof.png)

## 

![](https://i.imgur.com/m0JmzMP.png)

## 

![](https://i.imgur.com/pgLBmbf.png)

## 

![](https://i.imgur.com/FRpAszl.png)

## 

![](https://i.imgur.com/RHA8yfD.png)

## 

![](https://i.imgur.com/Fr58zX3.png)

## 

![](https://i.imgur.com/Tff4Nft.png)

## 

![](https://i.imgur.com/YrxyCIG.png)

## 

![](https://i.imgur.com/rzPdnx8.png)

## 

![](https://i.imgur.com/1AGs821.png)

## 

![](https://i.imgur.com/mJCXqjy.png)

## 

![](https://i.imgur.com/shNZcHi.png)


## 

![](https://i.imgur.com/gml3re1.png)


## 

![](https://i.imgur.com/sWIpQ2D.png)


## 

![](https://i.imgur.com/Nifhrou.png)


## 

![](https://i.imgur.com/cxu6yTz.png)

## 

![](https://i.imgur.com/jMTmIgF.png)

## 

![](https://i.imgur.com/mZq1z4O.png)

## 

![](https://i.imgur.com/TaEhnfZ.png)


# 重心分治

## 樹重心tree centorid

在樹上的一或二個點

若將該點移除 剩下的兩個連通塊的大小會小於一半

## 作法

dfs時 紀錄子樹+自己的大小

祖先的大小即為全部-子樹

## 分治

接著我們可以把樹重心處理完之後

刪除樹重心 ->尋找剩下兩顆樹的重心

遞迴把答案算出來

## 時間複雜度

找重心×次數 O(N×logN)

# 題目QA

## 題目

- MST模板題

## Q&A