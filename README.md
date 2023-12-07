this branch adds tag compatibility to clang, 
currently enums aren't supported, but unions and structs both are more compatible.

this also goes slightly outside the standard by providing tag compatibility for unnamed types
here's an example 

```c
#define option_t(type) \
    struct { bool has_value; type value; }

option_t(int) dothing(struct { float v; } input);

typedef struct { float v; } a_t;
typedef struct { float v; } b_t;

union u { int i; float f; };

void example(union u);

int main(void) {
    option_t(int) value = dothing(&(struct { float v; }){0.5f});
    a_t a = (struct { float v; }){5};
    b_t b = (struct { float v; }){5};
    struct { float v; } unnamed_a = (a_t){5};
    struct { float v; } unnamed_b = (b_t){5};
    a = b; b = a;

    example((union { int i; float f; }){.i = 25});
}
```

# The LLVM Compiler Infrastructure

[![OpenSSF Scorecard](https://api.securityscorecards.dev/projects/github.com/llvm/llvm-project/badge)](https://securityscorecards.dev/viewer/?uri=github.com/llvm/llvm-project)

Welcome to the LLVM project!

This repository contains the source code for LLVM, a toolkit for the
construction of highly optimized compilers, optimizers, and run-time
environments.

The LLVM project has multiple components. The core of the project is
itself called "LLVM". This contains all of the tools, libraries, and header
files needed to process intermediate representations and convert them into
object files. Tools include an assembler, disassembler, bitcode analyzer, and
bitcode optimizer.

C-like languages use the [Clang](http://clang.llvm.org/) frontend. This
component compiles C, C++, Objective-C, and Objective-C++ code into LLVM bitcode
-- and from there into object files, using LLVM.

Other components include:
the [libc++ C++ standard library](https://libcxx.llvm.org),
the [LLD linker](https://lld.llvm.org), and more.

## Getting the Source Code and Building LLVM

Consult the
[Getting Started with LLVM](https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm)
page for information on building and running LLVM.

For information on how to contribute to the LLVM project, please take a look at
the [Contributing to LLVM](https://llvm.org/docs/Contributing.html) guide.

## Getting in touch

Join the [LLVM Discourse forums](https://discourse.llvm.org/), [Discord
chat](https://discord.gg/xS7Z362),
[LLVM Office Hours](https://llvm.org/docs/GettingInvolved.html#office-hours) or
[Regular sync-ups](https://llvm.org/docs/GettingInvolved.html#online-sync-ups).

The LLVM project has adopted a [code of conduct](https://llvm.org/docs/CodeOfConduct.html) for
participants to all modes of communication within the project.
