# Competitive Programming Templates

Personal C++ competitive-programming workspace. Clone, and start solving.

## Layout

```
main.cpp              # scratch file you edit per problem
templates/
  template.cpp        # pristine base template (source of truth)
stdc++.h              # local precompiled-header source (libc++ has no <bits/stdc++.h>)
io/
  input.txt           # stdin  (read under LOCAL_JUDGE)
  output.txt          # stdout (written under LOCAL_JUDGE; gitignored)
Makefile
.clangd               # editor (clangd) config, kept in sync with the Makefile
```

`main.cpp` includes `stdc++.h` when compiled locally (the `LOCAL_JUDGE` macro,
defined by the Makefile) and falls back to `<bits/stdc++.h>` on online judges.

## Usage

```sh
make            # build main.cpp (warnings + ASan/UBSan + _GLIBCXX_DEBUG)
make run        # build, then run ./a using io/input.txt -> io/output.txt
make release    # optimized build, no sanitizers (closest to the judge)
make reset      # overwrite main.cpp with templates/template.cpp
make clean      # remove the binary
make clean_all  # remove the binary and the precompiled header
```

Override the source file or compiler from the command line:

```sh
make FILE=b.cpp run
make CXX=g++-14
```

## Requirements

- **macOS:** Homebrew LLVM (`brew install llvm`) — auto-detected. Falls back to `clang++`.
- **Linux:** `g++` (default) or any `clang++`/`g++` via `make CXX=...`.

A C++23-capable compiler is required (the template uses concepts, `<print>`, etc.).
