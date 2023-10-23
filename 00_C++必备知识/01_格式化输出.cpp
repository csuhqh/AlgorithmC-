#include <bits/stdc++.h>
using namespace std;


int main(){
  double x = 33.156;
  //保留2位小数
  printf("%.2f\n", x);
  //保持占位符(默认右对齐)
  printf("%12f\n", x);
  printf("%-12f\n", x); //左对齐
  return 0;
}