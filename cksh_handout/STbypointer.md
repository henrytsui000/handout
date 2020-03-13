---
author: oxolane
title: 指標線段樹
date: 2020 未知
---

# 先來看看題目吧

## 
給定數列A

詢問Q次 

區間l,r的總和

## 不要中毒啦

## 前綴合搞定

## 
竹中軟研社長：

莫隊+treap

-2018.?月?日

![](https://i.imgur.com/fJ71V9b.jpg)


# 如果前面那題加上操作

## 可將位置x更動？


## BIT(X

# 什麼是線段樹


## 維護線段的樹狀結構

![imgur](https://i.imgur.com/tFC0Nwg.png)
嘔心瀝血畫出來ㄉ 請見諒


# 來看看實做吧


## 初始化

用struct當作節點

裡面紀錄 左節點 右節點 值域 資料

*pull函數稍後用到*

```cpp
struct Node{
    Node *lc,*rc;
    int l,r;
    int data;
    void pull(){
        data=max(lc->data,rc->data);
    }
};
```


## 建立

若為子節點 則填上數值

否則遞迴完成子節點

子節點完成後再利用pull函數合併

```cpp
Node *build(int l,int r){
    if(l==r-1)
        return new Node{0,0,l,r,arr[l]};
    int mid=(l+r)>>1;
    node *ret = new Node{build(l,mid),build(mid,r),l,r,0};
    ret->pull();
    return ret;
}
```


## 單點修改

先遞迴走到子節點

改值後再往上回推完成

```cpp
void add (int x, int val, node *nd) {
    if(nd->l==x&&nd->r==x+1){
        nd->data+=val;
    }else{
        int mid=(nd->l+nd->r)>>1;
        if(x>=mid){
            add(x,val,nd->rc);
        }else{
            add(x,val,nd->lc);
        }
        nd->pull();
    }
}
```


## 查詢

從根節點往下走  若查詢區域跟節點一樣則回傳

若區域全都在右邊就往右走//區域全左就往左走

否則左右分別找答案
```cpp
int qry(int l,int r,node *nd){
    if(l==nd->l&&r==nd->r){
        return nd->data;
    }else{
        int mid=(nd->l+nd->r)>>1;
        if(l>=mid){
            return qry(l,r,nd->rc);
        }else if(r<=mid){
            return qry(l,r,nd->lc);
        }else{
            return max(qry(l,mid,nd->lc),
                        qry(mid,r,nd->rc));
        }
    }
}
```


# 時間複雜度

## 建立 O(N)

## 單點修改 O(logN)

## 查詢O(logN)

## 時間/空間比陣列線段樹慢

->但好實做

# 區間加值


## 不斷的單點修改？


## 複雜度O(NlogN)

甚至比暴力修改還慘！


## lazy_tag

在節點多紀錄一個值

若修改蓋過此節點所有值域

則不繼續更改子節點 選擇紀錄在此點上

![imgur](https://i.imgur.com/mLytQ62.png)


## new struct

```cpp
struct Node{
    Node *lc,*rc;
    int l,r;
    int data,tag;
    void pull(){
        data=max(lc->data,rc->data);
    }
    void push(){
        if(lc&&rc){
            lc->tag+=tag;
            rc->tag+=tag;
        }
        data+=tag;
        tag=0;
    }
};
```

## 其他操作只是在函數前加上nd->push();

# 題目 Q&A

## 題目

- 經典RMQ

- [ZJ-d539](https://zerojudge.tw/ShowProblem?problemid=d539)
- [SKY-52](https://pc2.tfcis.org/dev/index.php/problem/view/52/)
- [SKY-39](https://pc2.tfcis.org/dev/index.php/problem/view/39/)
- [SKY-58](https://pc2.tfcis.org/dev/index.php/problem/view/58/)
- [SKY-86](https://pc2.tfcis.org/dev/index.php/problem/view/86/)

## Q&A