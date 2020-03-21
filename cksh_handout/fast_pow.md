---
author: oxolane
title: 快速冪
data: 未知
---

# 計算次方

## 
如果給a跟b

請回傳a^b^

## 暴力作法

```c++
int a,b;
cin>>a>>b;
int ans=1;
rep(i,b)
    ans*=a;
//其實pow(a,b)也可以作到此事
```

時間複雜度：O(N)

## 能不能更快呢？

![](https://i.imgur.com/WrcSigs.jpg)

# 快速冪

## 利用倍增法來加速乘法！

## 先來看看例子吧
因為a^23^=a^16+4+2+1^=a^16^×a^4^×a^2^×a^1^

因此可以開一個k暫存${a^{2^x}}$以及ans存答案

每次動作如下

1. 如果目標拆解過後有出現k 則ans=ans*k

2. 把k平方

## 
a^23^=a^$(10111)_2$^=a^$(10000)_2$^×a^$(100)_2$^×a^$(10)_2$^×a^$(1)_2$^

講義好難解釋步驟 我用畫的解釋www

## CODE
```c++
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)
            ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
```

# 矩陣快速冪

## 先來看看題目吧
有一個數列$a__n$=x×$a__{n-1}$+y×$a__{n-2}$

給定x,y 求$a__n$?

## 導出轉移矩陣
${
\left[ \begin{array}{ccc}
a__{n-1} \\
a__{n-2}
\end{array} 
\right ]}$
×
${
\left[ \begin{array}{ccc}
x & y \\
1 & 0 
\end{array} 
\right ]}$
=
${
\left[ \begin{array}{ccc}
a__{n-1}×x+a__{n-1}×y \\
a__{n-1}×1+a__{n-2}×0
\end{array} 
\right ]}$
=
${
\left[ \begin{array}{ccc}
a__{n} \\
a__{n-1}
\end{array} 
\right ]}$

${
\left[ \begin{array}{ccc}
a__{n} \\
a__{n-1}
\end{array} 
\right ]}$
=
${
\left[ \begin{array}{ccc}
a__{1} \\
a__{2}
\end{array} 
\right ]}$
${
\left[ \begin{array}{ccc}
x & y \\
1 & 0 
\end{array} 
\right ]}^n$

## 目標轉移

所以我們只需要將快速冪的k改成矩陣

然後依樣畫葫蘆的完成快速冪

## CODE

## 自訂struct方便操作！
(也可以開矩陣 我以前都自己開)

```c++
struct mat{
    int arr[2][2];

};
```
## 矩陣乘法
```c++
mat muti(mat a,mat b){
    mat ret;
    rep(i,2) rep(j,2)
        ret.arr[i][j]=0;//歸零
    rep(i,2) rep(j,2) rep(k,2)//矩陣乘法
        ret.arr[j][i]+=a.arr[k][i]*b.arr[j][k];
    return ret;
}
```

## 類似快速冪
```c++
void mypow(mat a,int b){
    while(b){
        if(b&1)
            ans=muti(ans,a);//ans×a
        a=muti(a,a);//a×a
        b>>=1;
    }
    cout<<ans.arr[0][0]<<endl;
}
```

## 初始化&輸出入
```c++
mat ans;
int main(){
    mat a;int n;
    ans.arr[0][0]=ans.arr[1][0]=1;
    a.arr[0][1]=1,a.arr[1][1]=0;
    cin>>a.arr[0][0]>>a.arr[1][0]>>n;
    mypow(a,n);
    return 0;
}
```