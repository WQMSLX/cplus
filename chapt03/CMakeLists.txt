# 用于生成位置无关代码。位置无关代码，可以理解为代码无绝对跳转，跳转都为相对跳转。生成动态库时，需要加上-fPIC选项。

# 在 Linux 系统中，动态链接文件称为动态共享对象 (Dynamic Shared Objects，DSO)，一般是以.so 为扩展名的文件。
# 在 Windows 系统中，动态链接文件称为动态链接库 (Dynamic Linking Library)，一般是以 .dll 为扩展名。
set(POSITION_INDEPENDENT_CODE True)

# 如果你需要链接到 dl 库，在 Linux 上可以使用 -ldl 标志，不过在 CMake 中只需要在 target_link_libraries 命令中
# 使用内置的 CMake 变量 ${CMAKE_DL_LIBS} 。这里不需要模组或者使用 find_package 来寻找它。（这个命令包含了调用 dlopen 与 dlclose 的一切依赖）

# 不幸的是，想要链接到数学库没这么简单。如果你需要明确地链接到它，你可以使用 target_link_libraries(MyTarget PUBLIC m)，
# 但是使用 CMake 通用的 find_library 可能更好，如下是一个例子：
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(MyTarget PUBLIC ${MATH_LIBRARY})
endif()