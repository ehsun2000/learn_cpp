# C++ 學習筆記

## 編譯器環境

### macOS 預設環境
- macOS 預裝 Xcode Command Line Tools
- `g++` 實際上是 `clang++` 的別名
- 版本：Apple clang version 16.0.0
- 位置：`/usr/bin/g++`

### 基本編譯指令
```bash
# 編譯並執行
g++ -o 程式名稱 檔案名稱.cpp && ./程式名稱

# 範例
g++ -o HelloWorld HellowWorld.cpp && ./HelloWorld
```

## C++ 建置工具（類似 Java Maven）

### 主要工具比較
1. **CMake** - 最流行的跨平台建置系統
2. **Conan** - C++ 套件管理工具（類似 Maven 的依賴管理）
3. **vcpkg** - Microsoft 的 C++ 套件管理工具
4. **Bazel** - Google 的建置工具
5. **Meson** - 現代化的建置系統

### 推薦組合
- **CMake + Conan** - 對 Java 開發人員最友善的組合
- 提供依賴管理和建置自動化
- 類似 Maven 的開發體驗

## 基本程式結構

### Hello World 範例
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "Hello World!\n";
    return 0;
}
```

### 程式結構說明
1. `#include <iostream>` - 包含輸入輸出功能的標頭檔
2. `int main()` - 程式入口點
3. `std::cout` - 標準輸出
4. `return 0` - 程式正常結束的回傳值