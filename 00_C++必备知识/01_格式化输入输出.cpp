#include <bits/stdc++.h>
using namespace std;


int main(){
  //从控制台读取变量
  int a;
  string b;
  cin >> a >> b; //读取
  double x = 33.156;
  //输出到控制台

  //保留2位小数
  printf("%.2f\n", x);
  //保持占位符(默认右对齐)
  printf("%12f\n", x);
  printf("%-12f\n", x); //左对齐
  printf("读取到: a=%d, b=%s\n", a, b.c_str());
  return 0;
}