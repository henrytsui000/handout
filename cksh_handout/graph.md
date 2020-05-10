---
author: 建議用firefox閱讀
title: 基礎圖論
date: 2020 未知
---

# 圖 graph

## 圖的元素

- 點
- 邊

![](https://i.imgur.com/o50SLu3.png)

## 無向邊

連接點${u}$跟${v}$的邊

![](https://i.imgur.com/wUryXHS.png)

## 有向邊

從點${u}$指向${v}$的邊

![](https://i.imgur.com/ad45JwK.png)

## 重邊

從點${u}$跟${v}$有複數個邊

![](https://i.imgur.com/gNX9NjP.png)

## 帶權邊

- 有價值的邊
- 帶負值為負邊

![](https://i.imgur.com/1C2h7RP.png)

## 度/degree

在一個有向圖中 對於一個點：

- 出度：該點指向其他點的邊的數量 out-degree

- 入度：其他點指向該點的邊的數量 in-degree

## 環

環：多個點形成圓圈

自環：有一條有向邊指向自己

![](https://i.imgur.com/EANrZqo.png)

## 連通塊

- 無向圖中連在一起的稱做連通塊
- 強連通塊：有向圖中一個點集內任一點皆可走到其他元素

![](https://i.imgur.com/UQeDa4z.png)

## 其他
- 混和圖：同時包含有向邊和無向邊
- 有向無環圖(DAG)：Literally(之後有更多介紹)
- 簡單圖：不包含負邊和自環
- 完全圖：一個簡單圖 且所有點之間皆有一條邊

## Q&A

# 樹

## 定義/名詞

- 沒有環的圖
- 根節點
- 父/子節點
- 葉節點
- 祖先
- 子樹
- 深度

## 根節點

樹的頂端(不一定存在)

![](https://i.imgur.com/zTYWGQ4.png)

## 父/子節點

![](https://i.imgur.com/BVDN6Gs.png)

*註：根據性別平等法，應稱為長輩/小孩節點

## 葉節點

沒有子節點的節點們

![](https://i.imgur.com/muC9t5S.png)

## 祖先

父節點以上到根路徑上的所有點

![](https://i.imgur.com/9pF28V7.png)

## 子樹

以其中一個節點作為根的樹

![](https://i.imgur.com/Uv5WkJG.png)

## 層/深度

距離根節點的距離
根為0

![](https://i.imgur.com/BRn3PJm.png)

## 樹直徑

樹的最遠兩個點的路徑

![](https://i.imgur.com/IELE58z.png)

(兩次DFS可完成)

## 性質
- N個節點的樹 有N-1條邊
- 樹沒有環，但加一條邊就會有
- 樹任兩點都只存在一條簡單路徑

## Q&A

# 儲存一張圖-1

## vector[maxn]

**這是最常用的紀錄法**

用於邊數量<點數量^2^

![](https://i.imgur.com/4x2H4jG.png)


## 紀錄圖

```cpp
vector<int> edge[maxn];

int main(){
    int n;
    rep(i,n){
        int a,b;cin>>a>>b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
}
```

## DFS

```cpp
void dfs(int p,int pa){
    //do something
    for(int x:edge[p]){
        //do something
        dfs(x,p);
        //do something
    }
}
```

# 儲存一張圖-2

## vector<pii>

需要排序邊的時候會用到的結構

![](https://i.imgur.com/vC4zDRG.png)

## 紀錄圖

```cpp
vector< pair<int,int> > edge;
int main(){
    int n;cin>>n;
    rep(i,n){
        int a,b;cin>>a>>b;
        edge.pb(make_pair(a,b));
    }
}
```

# 儲存一張圖-3

## arr[maxn][maxn]

好實做，但複雜度超大

## CODE

```cpp
int graph[maxn][maxn];

void dfs(int n){ 
    rep(i,maxn) if(graph[n][i]) dfs(i);
}

int a,b;cin>>a>>b;
graph[a][b]=1;graph[b][a]=1;
```

## Q&A

# DFS

## 如何遍歷一張圖？
- 找一個點，找他的一條邊走
- 然後再找抵達的點的邊走
- 若走到死路 或沒有尚未走過的路
- 往回前一個點找其他路走
- 以遞迴實作
- [DFS](https://hackmd.io/@henrytsui/HyVdSUreL#/)

## 
![](https://i.imgur.com/x3Q6r06.png)

1

## 往最小數字走
![](https://i.imgur.com/QNeerO4.png)

1->2

## 
![](https://i.imgur.com/3uq0py9.png)

1->2->6

## 走回點1
![](https://i.imgur.com/JnYPA94.png)

1->2->6->1(x)


## 因為已到過1 所以回朔至6
![](https://i.imgur.com/C7T4Fqg.png)

1->2->6->5

## 
![](https://i.imgur.com/CdH19j9.png)


1->2->6->5->3

## 
![](https://i.imgur.com/jOROWsF.png)

1->2->6->5->3->1(x)

## 
![](https://i.imgur.com/wFb6o7N.png)

1->2->6->5->3->4#

## 樹DFS

![](https://i.imgur.com/qCp2Pag.png)

順序：1->2->5->9->3->4->6->7->8

## CODE

*如果是dfs一顆樹 通常會順便紀錄父節點

```cpp
const int maxn = 10;//點的數量
bool vis[maxn];//紀錄該點是否走過
vector<int> edge[maxn];//存邊
void dfs(int n){
    vis[n]=1;//紀錄已走過
    for(int x:edge[n]) if(!vis[x])
        dfs(x,n);
}
int main(){
    dfs(0);//開始
}
```

## 暴力搜尋法

- 將所有個節點設為狀態
- 所有節點都是唯有邊

## 例題

用DFS的方式輸出所有四位數字 

且各個位數皆不相同

很醜的片段

```cpp
bool vis[10];
void dfs(int cnt,int ans){
    if(cnt==4)
        cout<<ans<<endl;
    else rep1(i,9) if(!vis[i]){
        vis[i]=1,cnt++,ans=ans*10+i;
        dfs(cnt,ans);
        cnt--,ans/=10,vis[i]=0;
    }
}
```

## DFS題目

- 八城堡問題
- 八皇后問題
- 圖論的大多數題目
- 尤拉路徑

## Q&A

# BFS

## 其他方式遍歷一張圖？

- 先把一個點的邊走完
- 紀錄經過哪些點 之後按照順序遍歷完
- 以queue實作

## 圖BFS

![](https://i.imgur.com/x3Q6r06.png)

1->2->3->6->5->4

## 樹BFS

![](https://i.imgur.com/qCp2Pag.png)

順序：1->2->3->4->5->6->7->8->9

## 題目

- 老鼠走迷宮

## Q&A

# 題目

## 
- 2020TOI初選pB
- [ZJ-b967](https://zerojudge.tw/ShowProblem?problemid=b967)
- [POJ-2378](http://poj.org/problem?id=2378)
- [ZJ-d375](https://zerojudge.tw/ShowProblem?problemid=d375)
- [UVa-10400](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1341)