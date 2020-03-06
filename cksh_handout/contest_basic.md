---
author: oxolane
title: 競賽入門
---

# 競賽程式

## 競賽程式

輸入 -> 輸出-> accpet

## online-judge

- Codeforces
- Zero Judge
- TIOJ
- TPOJ(現在死ㄌ)

## 上傳結果

 
* AC->答對!
* WA->答案錯誤->debug 檢查邏輯
* TLE->時間超過限制->減少時間複雜度
* MLE->記憶體超過限制->滾動等方式解決
* CE->編譯錯誤->先在本機確認程式能用
* RE->各種形式的壞掉

# 複習時間

# 宣告

## int

宣告一個或多個變數且在±2^31^-1之間

且數值範圍大約為正負2*1e9左右

- **1eX代表10^x^**

*注意：若大於數字範圍 將會變成不可預知的數字*

*若宣告在main函式中 將會不可預知他的初始數字*

## 其他

- long long 在±2^63^-1之間

- unsigned long long 在0~2^64^-1之間

- double 15位數且可帶小數點

# IF判斷式


## IF

形式
if(判斷條件){

}

特殊用法 if(判斷式&&k++) 短路結構

# 迴圈

## FOR迴圈

形式
for(初始化;結束條件;更動項目)

for(初始化 : 對應陣列) 之後教

## WHILE迴圈

形式
while(判斷條件)

特殊用法while(cin>>n)

# 資料結構

## 1D 
一維陣列
```cpp
int arr[n];
array<int,2(const)> arr;
```

## 2D
二維陣列
```cpp
int arr[n][n];
```

## MORE...
Standard Template Library (STL)

* pair, tuple
* vector, string
* set, map, multiset, multimap
* priority_queue
* queue, stack, deque

# 可以打競賽了!