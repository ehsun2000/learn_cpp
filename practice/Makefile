CXX = clang++
CXXFLAGS = -std=c++23 -Wall -Wextra
BUILD_DIR = build

# 找出所有章節目錄
CH_DIRS = $(wildcard ch*)

# 預設目標：顯示可用的章節和使用方式
all:
	@echo "Available chapters: $(notdir $(CH_DIRS))"
	@echo "Usage:"
	@echo "  make list               - List all available targets"
	@echo "  make <chapter>/<target> - Build specific target (e.g., make ch3/DebugQuestion1)"
	@echo "  make clean              - Clean all build files"
	@echo "  make clean-<chapter>    - Clean specific chapter build files"

# 列出所有可編譯的目標
list:
	@find . -name "ch*" -type d | while read dir; do \
		dir=$${dir#./}; \
		echo "Chapter $$dir:"; \
		find "$$dir" -name "*.cpp" -type f | while read cpp; do \
			target=$$(basename "$$cpp" .cpp); \
			echo "  $$dir/$$target"; \
		done; \
		echo; \
	done

# 跨章節編譯規則：<chapter>/<target>
%:
	@chapter="$$(echo '$@' | cut -d'/' -f1)"; \
	target="$$(echo '$@' | cut -d'/' -f2)"; \
	if [ ! -d "$$chapter" ]; then \
		echo "Chapter directory $$chapter does not exist"; \
		exit 1; \
	fi; \
	if [ ! -f "$$chapter/$$target.cpp" ]; then \
		echo "Source file $$target.cpp not found in $$chapter"; \
		exit 1; \
	fi; \
	mkdir -p $(BUILD_DIR)/"$$chapter"; \
	echo "Building $$chapter/$$target..."; \
	$(CXX) $(CXXFLAGS) "$$chapter/$$target.cpp" -o $(BUILD_DIR)/"$$chapter"/"$$target"; \
	echo "Built: $(BUILD_DIR)/$$chapter/$$target"

# 特殊規則：ch1&2/Preprocessor 需要編譯兩個檔案
ch1&2/Preprocessor:
	@mkdir -p $(BUILD_DIR)/ch1\&2
	@echo "Building ch1&2/Preprocessor (multiple files)..."
	$(CXX) $(CXXFLAGS) ch1\&2/Preprocessor.cpp ch1\&2/Preprocessor2.cpp -o $(BUILD_DIR)/ch1\&2/Preprocessor
	@echo "Built: $(BUILD_DIR)/ch1&2/Preprocessor"

# 清理所有編譯檔案
clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned all build files"

# 清理特定章節
clean-%:
	rm -rf $(BUILD_DIR)/$*
	@echo "Cleaned build files for $*"

.PHONY: clean clean-% all list