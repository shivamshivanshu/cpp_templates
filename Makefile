# make            debug build (warnings + sanitizers + _GLIBCXX_DEBUG)
# make run        build, then run ./a (io/input.txt -> io/output.txt)
# make release    optimized build, no sanitizers
# make reset      overwrite main.cpp with templates/template.cpp
# make clean      remove the binary
# make clean_all  remove the binary and the precompiled header
# Overrides: make FILE=b.cpp run   |   make CXX=g++-14

ifeq ($(origin CXX),default)
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Darwin)
    BREW_LLVM := $(shell brew --prefix llvm 2>/dev/null)
    ifneq ($(wildcard $(BREW_LLVM)/bin/clang++),)
      CXX := $(BREW_LLVM)/bin/clang++
    else
      CXX := clang++
    endif
  else
    CXX := g++
  endif
endif

FILE     := main.cpp
OUT      := a
TEMPLATE := templates/template.cpp
PCH_SRC  := stdc++.h
PCH_OUT  := stdc++.h.pch

WARN      := -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal \
             -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align \
             -Wno-unused-const-variable -Wno-unused-function
DEBUGDEFS := -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
SANITIZER := -fsanitize=address,undefined -fno-sanitize-recover -fstack-protector
EXTRA     := -DLOCAL_JUDGE
STD       := -std=c++23

# PCH and binary must share the same flags or the PCH is rejected.
DBGFLAGS  := $(STD) -g -O0 $(WARN) $(DEBUGDEFS) $(SANITIZER) $(EXTRA)
RELFLAGS  := $(STD) -O2 $(EXTRA)

.PHONY: all run release reset clean clean_all

all: $(PCH_OUT)
	@echo "\n[[INFO]] Building $(FILE) with $(notdir $(CXX)) ...\n"
	$(CXX) $(DBGFLAGS) -include-pch $(PCH_OUT) $(FILE) -o $(OUT)
	@echo "\n[[INFO]] Finished -> ./$(OUT)\n"

$(PCH_OUT): $(PCH_SRC) Makefile
	@echo "\n[[INFO]] Precompiling headers...\n"
	$(CXX) $(DBGFLAGS) -x c++-header $(PCH_SRC) -o $(PCH_OUT)

run: all
	@echo "[[INFO]] Running ./$(OUT)\n"
	@./$(OUT)
	@echo "[[INFO]] Done. See io/output.txt"

release:
	@echo "\n[[INFO]] Release build of $(FILE) ...\n"
	$(CXX) $(RELFLAGS) $(FILE) -o $(OUT)
	@echo "\n[[INFO]] Finished -> ./$(OUT)\n"

reset:
	cp $(TEMPLATE) $(FILE)
	@echo "[[INFO]] $(FILE) reset from $(TEMPLATE)"

clean:
	rm -f $(OUT)

clean_all: clean
	rm -f $(PCH_OUT)
