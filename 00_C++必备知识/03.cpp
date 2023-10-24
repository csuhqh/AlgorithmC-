#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// 定义一个比较函数对象类型
struct CMP {
    bool operator() (const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};
//利用lambda
auto CMP2 = [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) { 
            if (a.first == b.first) {
              return a.second < b.second;
            }
            return a.first < b.first; //less， 从小到大排序
        };
//利用class
class CMP3{
  public:
      bool operator() (const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

int main() {
    std::vector<std::pair<int, std::string>> vec = {{5, "apple"}, {3, "banana"}, {5, "cherry"}};
    std::sort(vec.begin(), vec.end(), CMP3()); //使用CMP1()或CMP2或CMP3()
    
    for (const auto& p : vec) {
        std::cout << p.first << ", " << p.second << std::endl;
    }

    return 0;
}
