---
author: oxolane
title: 大數
data: 未知
---

# 大數

## 
在比賽中 題目不一定會保證測資小於2^63^-1

為了解決無法存取的問題

我們可以用一維陣列模擬數字

在這裡設定$a_i$是數字的第i+1位數

## 大數輸入

可以利用char或string相將數字讀入之後再轉到陣列

```c++
int main(){
    int a[maxn];
    string str;
    cin>>str;
    rep(i,sz(str))
        a[i]=str[i]-'0';
}
```
## 大數輸出

找到數字第一位之後就可以開始輸出

```c++
int main(){
    bool key=0;//紀錄找到非0了沒
    for(int i=maxn-1;i>=0;i--){
        if(a[i])
            key=true;
        if(key)
            cout<<a[i];
    }
    cout<<endl;
}

```

## 加法

因為各位數字相加可以保證小於20

所以先相加完之後一起進位就完成了

```c++
int a[maxn],b[maxn],c[maxn];
rep(i,maxn)
    a[i]=b[i]+c[i];
rep1(i,maxn) if(a[i]>9)
    a[i]+=a[i-1]/10,a[i-1]%=10;
```      

## 大數乘int

```c++
int a[maxn],muti,ans[maxn];
rep(i,maxn)
    ans[i]=a[i]*muti;
rep1(i,maxn)
    ans[i]+=(ans[i-1]/10),ans[i-1]%=10;
```

# 大數排序

## 題目
給你一個數列A 且10^10^<$a_i$<10^100^

請從小到大排序之後輸出

## string
利用ASCII的0~9會按照大小排序

將數字填入string中

在利用sort支援string排序的功能完成

## 21<9?
直接實做之後會發現

因為字串排序是從每個數字最前面的開始看

所以會出現43<5之類的問題 

## 
->如果我們在數字前面補0就解決了！

## CODE
```c++
#define sz ((int)s.size())
int main(){
    string str[10];
    int mx=0;
    rep(i,n){
        cin>>str[i];
        mx=max(mx,sz(str[i]));//紀錄最大位數
    }
    rep(i,n)if(str[i]<mx)
        rep(j,mx-sz(str[i]))//位數差距
            str[i]='0'+str[i];
}
```