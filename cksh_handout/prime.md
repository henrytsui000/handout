---
author: oxolane
title: 質數
date: 2020 未知
---

# 找範圍內的所有質數

# 暴力窮舉

## 
對於每一個數N

可知道他的質因數一定小於sqrt(N)

所以我建立一個陣列紀錄質數們

且對於每一個點N 去計算他們是否為質數

## 時間複雜度

O(N$\sqrt{N}$)

蠻糟的...

# 線性篩表

## 

對於一個合數N

可找到最大質因數P

合數將會是(N/P)*P

且N/P < P

那我總是將P×{小於P的質數}刪掉時

一定可以把所有和數剔除

## 時間複雜度

當我把小於MAXN的所有的合數藉由他的最大質因數刪除時

只需要O(MAXN)的時間

並且會建立一個表格內容為所有數字是否為質數

## CODE

```c++
const int N = 20000000;
bool sieve[N];
void linear_sieve(){
    vector<int> prime;
    for (int i=2; i<N; i++){
        if (!sieve[i]) prime.push_back(i);
        for (int j=0; i*prime[j]<N; j++){
            sieve[i*prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
```

# Q&A
