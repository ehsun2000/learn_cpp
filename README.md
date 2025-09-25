# C++ 學習筆記

## 開發環境設置

### macOS 環境
- macOS 預裝 Xcode Command Line Tools
- `g++` 實際上是 `clang++` 的別名
- 版本：Apple clang version 16.0.0
- 位置：`/usr/bin/g++`

### VS Code 配置
了解 C++ 開發環境的配置層次：
1. **IntelliSense 配置**：`.vscode/c_cpp_properties.json`
2. **實際編譯配置**：Makefile 或編譯指令參數
3. **兩者必須保持一致**才能獲得最佳開發體驗

## 編譯與建置

### 基本編譯指令
```bash
# 基本編譯
g++ -o 程式名稱 檔案名稱.cpp && ./程式名稱

# 指定 C++ 標準版本
clang++ -std=c++23 -Wall -Wextra practice/PrintStandard.cpp -o practice/build/PrintStandard
```

### Makefile 自動化建置

#### 智能 Makefile（推薦）
在 `practice/` 目錄下的 Makefile 設計：
- 自動偵測所有 `.cpp` 檔案
- 統一使用 C++23 標準和編譯警告選項
- 自動編譯到 `build/` 目錄

```bash
# 進入 practice 目錄
cd practice/

# 查看可用的編譯目標
make

# 編譯任意檔案（自動編譯到 build/ 目錄）
make PrintStandard
make HelloWorld

# 執行
./build/PrintStandard

# 清理
make clean
```

**關鍵設計特性：**
- 使用 `$(wildcard *.cpp)` 自動發現所有源文件
- 通用規則：任何 `.cpp` 檔案都能直接用檔名編譯
- 統一編譯參數：`-std=c++23 -Wall -Wextra`

#### 專案根目錄 Makefile
```bash
# 編譯到指定路徑
make practice/build/PrintStandard
```

## 實作練習

### Hello World 程式
```cpp
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "Hello World!\n";
    return 0;
}
```

**程式結構：**
1. `#include <iostream>` - 包含輸入輸出功能
2. `int main()` - 程式入口點
3. `std::cout` - 標準輸出
4. `return 0` - 程式正常結束

### C++ 標準檢測程式
實作了 `PrintStandard.cpp`，檢測編譯器的 C++ 標準版本：

```cpp
// 核心功能：檢測編譯器標準
long getCPPStandard() {
    return __cplusplus;  // 編譯器預定義巨集
}
```

**標準版本對應：**
- `199711L` = Pre-C++11
- `201103L` = C++11  
- `201402L` = C++14
- `201703L` = C++17
- `202002L` = C++20
- `202302L` = C++23

### 變數初始化練習
實作了 `VariableAssignment.cpp`，展示各種變數初始化方法：

**傳統初始化方式：**
```cpp
int copyInitialized = 5;      // 複製初始化
int directInitialized(6);     // 直接初始化
```

**現代 C++11 清單初始化（推薦）：**
```cpp
int directListInitialized{5};    // 直接清單初始化（推薦）
int copyListInitialized = {6};   // 複製清單初始化（較少使用）
int valueInitialized{};          // 值初始化（初始化為 0）
```

**重要特性：**
- **防止窄化轉換**：清單初始化會阻止資料遺失的轉換
- **統一語法**：適用於所有類型的初始化
- **明確意圖**：`{}` 明確表達初始化意圖

**最佳實踐：**
- 使用直接清單初始化 `int value{42};`
- 避免未初始化變數
- 臨時變數使用值初始化 `int temp{};`
- C++17 可使用 `[[maybe_unused]]` 標記可能未使用的變數

## 重要學習心得

### 編譯器標準設定
- VS Code 的 `c_cpp_properties.json` 只影響 IntelliSense
- 實際編譯必須在編譯指令或 Makefile 中指定 `-std=c++23`
- 兩個配置不一致會造成開發困擾

### Makefile 自動化優勢
- 統一編譯參數和標準版本
- 避免重複輸入長指令
- 自動化建置和清理流程
- 提高開發效率

## C++ 生態系統

### 主要建置工具
1. **CMake** - 最流行的跨平台建置系統
2. **Conan** - C++ 套件管理工具（類似 Maven）
3. **vcpkg** - Microsoft 的套件管理工具
4. **Bazel** - Google 的建置工具
5. **Meson** - 現代化建置系統

### 推薦組合
- **CMake + Conan** - 對 Java 開發人員最友善
- 提供完整的依賴管理和建置自動化