---
author: oxolane
title: math
date: 2020 未知
---

# 模MOD

## 基礎知識

mod稱作模 

在c++中跟%功能類似

因為有一些定理 可使得計算題目更簡單

->當答案會超過int範圍 常常題目會要求%1e9+7

以下定義mod=1e9+7

## 

以下為合法的模運算

- (a±b)%mod=(a%mod±b%mod)%mod

- (a×b)%mod=(a%mod×b%mod)%mod


## 費馬小定理

- a^p^ ≡ a (mod p) (p∈質數)

- a^p-1^ ≡ 1 (mod p)

- a^p-2^ ≡ a^-1^ (mod p)

## 費馬小定理-延伸

- a/b=a*b^-1^

- a*b^-1^ ≡ a\*b^p-2^ (mod p)

- a^p-2^是a模b為模逆原

# C(n,k)

## 計算組合數的方法

- C(n,k)=C(n-1,k-1)+C(n-1,k) 遞迴
- C(n,k)=n!/(k!(n-k)!) 相乘

## 遞迴法

- n<3000時

- 利用C(n,k)=C(n-1,k-1)+C(n-1,k)性質

- 開一個n*n的陣列預處理所有的C(n,k)

- 時間複雜度 建表O(N^2^) 詢問O(1)

## 相乘法

- 當n>3000時 且要mod p時

- 開一個陣列紀錄1\~n!以及1^p-2^\~(n^p-2^)!

- 直接計算n!×k!^p-2^×(n-k)!^p-2^

- 時間複雜度 建表O(N) 詢問O(1)

## 相乘法-2

- 可將建立模逆元階乘表從O(NlogN)降至O(N)

- 快速冪計算n^p-2^!%p

- n^p-2^!×n=(n-1)^p-2^!×n^p-2^×n=(n-1)^p-2^!

# 質數

## 線性篩表

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

# 計算幾何

# FFT

## 快速傅立葉變換

可將乘法從O(N^2^)->O(NlogN)

## 