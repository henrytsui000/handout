---
author: oxolane
title: 陣列線段樹
date: 2020 未知
---

# 陣列版本的線段樹!

## 先蓋一顆樹
上方為原陣列

對於N號節點的左節點是編號2\*N 右2*N+1

![](https://i.imgur.com/iMrvaDa.png)

## 建立
*假設該樹為求min*

![](https://i.imgur.com/RJCMhq5.png)


## 查詢

遞迴找到區間

![](https://i.imgur.com/t3peo5h.png)

## 修改

從下往上修正
(父節點為子節點[id/2])

![](https://i.imgur.com/3NAIbQ7.png)

# CODE

## define大法好

```c++
#define lc(x) (2*x)
#define rc(x) (2*x+1)
```

## 建立/修改

```c++
void build(int l,int r,int id){
    if(l==r-1)
        st[id]=arr[l];
    else{
        int mid=(l+r)>>1;
        build(l,mid,lc(id));
        build(mid,r,rc(id));
        st[id]=min(st[lc(id)],st[rc(id)]);
    }
}
```


## 查詢

```c++
int qry(int l,int r,int L,int R,int id){
    if(l==L&&r==R){
        return st[id];
    }else{
        int mid=(L+R)>>1;
        if(r<=mid) return qry(l,r,L,mid,lc(id));
        else if(l>=mid) return qry(l,r,mid,R,rc(id));
        else{
            return min( qry(l,mid,L,mid,lc(id)),
                        qry(mid,r,mid,R,rc(id)) );
        }
    }
}
```

# 題目 Q&A

## 題目
- [SKY-52](https://pc2.tfcis.org/dev/index.php/problem/view/52/)
- [SKY-39](https://pc2.tfcis.org/dev/index.php/problem/view/39/)
- [SKY-58](https://pc2.tfcis.org/dev/index.php/problem/view/58/)
- [SKY-86](https://pc2.tfcis.org/dev/index.php/problem/view/86/)
## Q&A
