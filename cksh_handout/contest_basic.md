---
author: oxolane
title: 競賽入門
---

# 競賽程式

## 競賽程式

輸入 -> 輸出-> accpet

## online-judge

- Zero Judge
- SKYOJ
- TIOJ
- Codeforces
- POJ
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
```c++
if(判斷條件){

}else{

}
```
若判斷事唯一行則可省大括弧

## 特殊用法
在c++中 任何成功執行的事情都會回傳true

因為判斷事可以會按照先後順序

因此可以寫出if(判斷式&&k++)的程式

意思與if(判斷式)k++;相同

# 迴圈

## FOR迴圈

形式
for(初始化;結束條件;更動項目)

for(初始化 : 對應陣列) 之後教

## WHILE迴圈

形式
while(判斷條件)

## n比輸入
常常可以在題目上看到 「此題共有n比輸入」

除了可以用for迴圈以外，也可以用底下的形式

```c++
int main(){
    int n;cin>>n;
    while(n--){
        //對於每筆資料你要做的事情
    }
}
```
省下一個變數名稱可以用

## 多筆輸入

有也時候題目會不跟你說有多少比資料

ex.zerojudge很常幹這種事

```c++
int main(){
    int n;cin>>n;
    while(cin>>n){
        //對於每筆資料你要做的事情
    }
}
```
如果是當n=0時結束 則改成while(cin>>n&&n)即可

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
表格狀結構

## MORE...
Standard Template Library (STL)

* pair, tuple
* vector, string
* set, map, multiset, multimap
* priority_queue
* queue, stack, deque

# 函式

## 
除了main以外 也可以自訂函式

因為自訂函式內的變數是獨立的

(即使相同名稱 也跟main中的是不同變數)

因此可以完成讓程式碼更容易debug

另外也可以遞迴喔

## 結構

回傳的資料型態 函式名稱(傳入資料型態 變數名稱){

    你要做的事情

    return 上面規定的資料型態;

}

## 範例
```c++
int add(int a,int b){
    int re=a+b;
    return re;
}
int main(){
    int x,y;cin>>x>>y;
    cout<<add(x,y)<<endl;
}
```
*下頁有講解*

## 講解(?)

$_{可以注意到main函式傳出是變數x,y，但add是用a,b代替}$

$_{可以想像為在main中x,y只是兩個數字 add函式稱那兩個數字為a,b}$

$_{因此就算在add中 加入a=4，也不會讓main中的x或y改變}$

$_{為了提昇可讀性 建議盡量讓傳出跟傳入想同名字}$

$_{除非是在for迴圈中傳出i,j等迴圈條件}$

## 遞迴

在函式中再次呼叫函式稱為遞迴

在實做遞迴時 需要格外小心中止條件

以免發生stack overflow停不下來

## 遞迴範例
回傳k!
```c++
int muti(int a){
    if(a==1) return 1;
    else return a*muti(a-1);
}
int main{
    int a;cin>>a;
    int answer=muti(a);
    cout<<answer<<endl;
}
```
*下頁有講解*

## 講解(?)

在muti函式中我不斷讓a*muti(a-1)

所以會不斷的進到新的muti函式->muti(a-1) 

直到a=1 因為muti(1)計算完了

因此muti(2)拿到muti(1)的答案而計算2*1結束

最終往上完成muti(a)的遞迴計算，回傳a!到main

# 可以寫題目了!