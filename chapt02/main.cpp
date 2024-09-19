#include <iostream>
#include "config/version.h"
# define LOG(x) std::cout << x << std::endl; 

// 验证加载配置文件
int main(){
    LOG("start server...");
    //  printf("Project Version: %s\n", USE_FEATURE_X);
    //LOG(USE_FEATURE_X);
   
    LOG(MAX_FILE_SIZE);
    LOG("stop server...");
    return 0;
}

