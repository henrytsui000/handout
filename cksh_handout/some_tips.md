---
title: 一些小知識
authoer: oxolane
---

# bits/stdc++.h標頭檔

## 每次都要#include一堆東西很麻煩？

#include<bits/stdc++.h>解決一切

## max/min

回傳兩元素最大/小值

```cpp
cout<<max(a,b)<<endl;
cout<<max({a,b,c})<<endl;
```

## sort

幫你排列數列
```cpp
int arr[5]={5,3,1,6,4};
sort(arr,arr+5);
//arr={1,3,4,5,6};
vector<int> vec;
sort(vec.begin(),vec.end())
```


## 如果是pair的陣列

會按照first排列再second

*可用sort(arr,arr+N,tmp);自訂排列方式 自己google*

## 二分搜

自帶二分搜
```cpp
lower_bound(arr,arr+N,c)
//回傳arr中c的"位置"
lower_bound(arr,arr+N,c)-arr
//回傳arr中c在第幾個
upper_bound同理
```

# 輸入輸出優化

## 在C++中 輸入輸出很慢

**尤其是資料量很大的時候**

## CODE
```cpp
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
int main(){
    IOS;
    return 0;
}
```

# FOR迴圈

## 客家打字時間
```cpp
#define rep(i,n) for(int i=0;i<(int)n;i++)
rep(i,10)
    cout<<arr[i]<<endl;
```
for(int i=0;i<n;i++)等價於rep(i,n)


## 其實FOR很慢


## 展開FOR迴圈

```cpp
#pragma GCC optimize("unroll-loops,no-stack-protector")
```

# define大法好

## define

```cpp
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define all(a) a.begin(),a.end()
#define sz(a) ((int)a.size())
#define F first
#define S second
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<(int)n;i++)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define cans cout<<ans<<endl
#define in cout<<"in lar"<<endl
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
```

## using/const

```cpp
using ll = long long;
using pii = pair<int,int>;
using ld = long double;

const int maxn =1e5+5;
int arr[maxn];
```

## 絕招

```cpp
#define int long long
int32_t main(){
    return 0;
}
```
# const int maxn

## 
因為main函數可以用的記憶體不多

所以我們應該先把需要用到的陣列開在全域

但因為還不知道要開多大

故會選擇題目給的資料範圍中(最大者+5)開

因為可能會手殘用到陣列邊緣

所以通常建議+5開

## 
題目一定會給最機車的測資

所以就直接坦蕩蕩的開最大

不要因為客家空間反而吃虧ㄌ

## CODE
為了修改陣列大小方便

會用const int

```c++
const int maxn= xxx;
int arr[maxn],cnt[maxn],ans[maxn];
```
# 一些建議

## 程式短!=好

看看二分搜

## tab

- 清楚排版方便debug
- 隊友也好懂

## 左大括號換行的都毒瘤

## 命名
- 減少使用無用的名稱
- 雖然要打比較多字
- 但之後才看得懂

## 為什麼要打競程？

總是會有心累的時候

思考一下可以幫助你喔

# Q&A