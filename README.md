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
make Preprocessor    # 特殊：編譯多個檔案

# 執行
./build/PrintStandard

# 清理
make clean
```

**關鍵設計特性：**
- 使用 `$(wildcard *.cpp)` 自動發現所有源文件
- 通用規則：任何 `.cpp` 檔案都能直接用檔名編譯
- 特殊規則：支援多檔案專案（如 Preprocessor.cpp + Preprocessor2.cpp）
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

### 輸入輸出練習
實作了 `IOStream.cpp`，學習 C++ 基本輸入輸出操作：

**基本輸出：**
```cpp
std::cout << "Hello, IOStream!" << std::endl;
std::cout << "The answer is " << 1234 << std::endl;
```

**效能優化：**
```cpp
// 避免使用 std::endl，優先使用 '\n'
std::cout << "This is line 1." << std::endl; // 較慢，會清空緩衝區
std::cout << "This is line 2." << '\n';      // 較快，只輸出換行
```

**使用者輸入：**
```cpp
int userInput{};
std::cout << "Please enter an int: ";
std::cin >> userInput;
std::cout << "You entered: " << userInput << '\n';

// 多重輸入
int num1{}, num2{};
std::cin >> num1 >> num2;  // 可用空格或換行分隔
```

### 函數練習
實作了 `Function.cpp`，學習函數的定義與使用：

**函數呼叫順序：**
```cpp
void functionA() {
    cout << "Starting function A..." << '\n';
    functionB();  // 呼叫其他函數
    cout << "Ending function A..." << '\n';
}
```

**參數處理：**
```cpp
// 有返回值的函數
int getValueFromUser() {
    int userInput{};
    cin >> userInput;
    return userInput;
}

// void 函數
void printValue(int value) {
    cout << "The value is: " << value << '\n';
}

// 未使用參數的處理方式
void unNamedParamFunction(int, double) { }  // 不命名
void googleStyleFunction(int /*param1*/, double /*param2*/) { }  // Google 風格
```

### 命名規範練習
實作了 `Common.cpp`，學習 C++ 命名最佳實踐：

**推薦命名方式：**
```cpp
// 兩種風格都可接受
int functionValue{};      // camelCase
int function_value{};     // snake_case
```

**應避免的命名：**
```cpp
int _functionValue{};     // 避免：底線開頭為系統保留
int ccount{};             // 避免：縮寫不清楚
int time{};               // 避免：過於通用
```

**推薦的描述性命名：**
```cpp
int numChars{};           // 清楚：字元數量（包含空白和標點）
```

### 使用者輸入練習
實作了 `DoubleInt.cpp`，簡單的互動程式：

```cpp
std::cout << "Please inter an Integer: " << '\n';
int intValue{};
std::cin >> intValue;
std::cout << "Double value! Result is: " << intValue * 2 << '\n';
```

### 前置處理器練習
實作了 `Preprocessor.cpp` 和 `Preprocessor2.cpp`，學習巨集和條件編譯：

**巨集定義：**
```cpp
#define MY_NAME "Charles Zheng"
#define PRINT_CPP "C++ is a powerful language."
#define PRINT  // 空巨集，用於條件編譯
```

**條件編譯：**
```cpp
#ifdef PRINT_CPP
    std::cout << PRINT_CPP << '\n';
#endif

#ifdef PRINT
    std::cout << "Printing!\n";
#endif
#ifndef PRINT
    std::cout << "Not printing!\n";
#endif
```

**編譯特性：**
- 支援多檔案編譯：`make Preprocessor`
- 自動編譯 `Preprocessor.cpp` 和 `Preprocessor2.cpp`
- 展示前置處理器指令的實際應用

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