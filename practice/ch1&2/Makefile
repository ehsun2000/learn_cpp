CXX = clang++
CXXFLAGS = -std=c++23 -Wall -Wextra
BUILD_DIR = build

# 找出所有 .cpp 檔案，自動產生對應的執行檔名
SOURCES = $(wildcard *.cpp)
TARGETS = $(SOURCES:.cpp=)

# 預設目標：顯示可用的執行檔
all:
	@echo "Available targets: $(TARGETS)"
	@echo "Usage: make <target>"

# 通用編譯規則：執行檔名對應到 build/執行檔名
$(TARGETS): %: $(BUILD_DIR)/%

# 特殊規則：Preprocessor 需要編譯兩個檔案
$(BUILD_DIR)/Preprocessor: Preprocessor.cpp Preprocessor2.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# 編譯規則：build/執行檔名 <- 原始碼.cpp  
$(BUILD_DIR)/%: %.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# 清理編譯檔案
clean:
	rm -f $(BUILD_DIR)/*

.PHONY: clean all $(TARGETS)