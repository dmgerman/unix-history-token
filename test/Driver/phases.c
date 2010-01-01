begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Basic compilation for various types of files.
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -ccc-print-phases -x c %s -x objective-c %s -x c++ %s -x objective-c++ -x assembler %s -x assembler-with-cpp %s -x none %s 2>&1 | FileCheck -check-prefix=BASIC %s
end_comment

begin_comment
comment|// BASIC: 0: input, "{{.*}}phases.c", c
end_comment

begin_comment
comment|// BASIC: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// BASIC: 2: compiler, {1}, assembler
end_comment

begin_comment
comment|// BASIC: 3: assembler, {2}, object
end_comment

begin_comment
comment|// BASIC: 4: input, "{{.*}}phases.c", objective-c
end_comment

begin_comment
comment|// BASIC: 5: preprocessor, {4}, objective-c-cpp-output
end_comment

begin_comment
comment|// BASIC: 6: compiler, {5}, assembler
end_comment

begin_comment
comment|// BASIC: 7: assembler, {6}, object
end_comment

begin_comment
comment|// BASIC: 8: input, "{{.*}}phases.c", c++
end_comment

begin_comment
comment|// BASIC: 9: preprocessor, {8}, c++-cpp-output
end_comment

begin_comment
comment|// BASIC: 10: compiler, {9}, assembler
end_comment

begin_comment
comment|// BASIC: 11: assembler, {10}, object
end_comment

begin_comment
comment|// BASIC: 12: input, "{{.*}}phases.c", assembler
end_comment

begin_comment
comment|// BASIC: 13: assembler, {12}, object
end_comment

begin_comment
comment|// BASIC: 14: input, "{{.*}}phases.c", assembler-with-cpp
end_comment

begin_comment
comment|// BASIC: 15: preprocessor, {14}, assembler
end_comment

begin_comment
comment|// BASIC: 16: assembler, {15}, object
end_comment

begin_comment
comment|// BASIC: 17: input, "{{.*}}phases.c", c
end_comment

begin_comment
comment|// BASIC: 18: preprocessor, {17}, cpp-output
end_comment

begin_comment
comment|// BASIC: 19: compiler, {18}, assembler
end_comment

begin_comment
comment|// BASIC: 20: assembler, {19}, object
end_comment

begin_comment
comment|// BASIC: 21: linker, {3, 7, 11, 13, 16, 20}, image
end_comment

begin_comment
comment|// Universal linked image.
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -ccc-print-phases -x c %s -arch ppc -arch i386 2>&1 | FileCheck -check-prefix=ULI %s
end_comment

begin_comment
comment|// ULI: 0: input, "{{.*}}phases.c", c
end_comment

begin_comment
comment|// ULI: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// ULI: 2: compiler, {1}, assembler
end_comment

begin_comment
comment|// ULI: 3: assembler, {2}, object
end_comment

begin_comment
comment|// ULI: 4: linker, {3}, image
end_comment

begin_comment
comment|// ULI: 5: bind-arch, "ppc", {4}, image
end_comment

begin_comment
comment|// ULI: 6: bind-arch, "i386", {4}, image
end_comment

begin_comment
comment|// ULI: 7: lipo, {5, 6}, image
end_comment

begin_comment
comment|// Universal object file.
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -ccc-print-phases -c -x c %s -arch ppc -arch i386 2>&1 | FileCheck -check-prefix=UOF %s
end_comment

begin_comment
comment|// UOF: 0: input, "{{.*}}phases.c", c
end_comment

begin_comment
comment|// UOF: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// UOF: 2: compiler, {1}, assembler
end_comment

begin_comment
comment|// UOF: 3: assembler, {2}, object
end_comment

begin_comment
comment|// UOF: 4: bind-arch, "ppc", {3}, object
end_comment

begin_comment
comment|// UOF: 5: bind-arch, "i386", {3}, object
end_comment

begin_comment
comment|// UOF: 6: lipo, {4, 5}, object
end_comment

begin_comment
comment|// Arch defaulting
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -ccc-print-phases -c -x assembler %s 2>&1 | FileCheck -check-prefix=ARCH1 %s
end_comment

begin_comment
comment|// ARCH1: 2: bind-arch, "i386", {1}, object
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -ccc-print-phases -c -x assembler %s -m32 -m64 2>&1 | FileCheck -check-prefix=ARCH2 %s
end_comment

begin_comment
comment|// ARCH2: 2: bind-arch, "x86_64", {1}, object
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin9 -ccc-print-phases -c -x assembler %s 2>&1 | FileCheck -check-prefix=ARCH3 %s
end_comment

begin_comment
comment|// ARCH3: 2: bind-arch, "x86_64", {1}, object
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin9 -ccc-print-phases -c -x assembler %s -m64 -m32 2>&1 | FileCheck -check-prefix=ARCH4 %s
end_comment

begin_comment
comment|// ARCH4: 2: bind-arch, "i386", {1}, object
end_comment

begin_comment
comment|// Analyzer
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -ccc-print-phases --analyze %s 2>&1 | FileCheck -check-prefix=ANALYZE %s
end_comment

begin_comment
comment|// ANALYZE: 0: input, "{{.*}}phases.c", c
end_comment

begin_comment
comment|// ANALYZE: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// ANALYZE: 2: analyzer, {1}, plist
end_comment

begin_comment
comment|// Precompiler
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -ccc-print-phases -x c-header %s 2>&1 | FileCheck -check-prefix=PCH %s
end_comment

begin_comment
comment|// PCH: 0: input, "{{.*}}phases.c", c-header
end_comment

begin_comment
comment|// PCH: 1: preprocessor, {0}, c-header-cpp-output
end_comment

begin_comment
comment|// PCH: 2: precompiler, {1}, precompiled-header
end_comment

begin_comment
comment|// Darwin overrides the handling for .s
end_comment

begin_comment
comment|// RUN: touch %t.s
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -ccc-print-phases -c %t.s 2>&1 | FileCheck -check-prefix=DARWIN1 %s
end_comment

begin_comment
comment|// DARWIN1: 0: input, "{{.*}}.s", assembler
end_comment

begin_comment
comment|// DARWIN1: 1: assembler, {0}, object
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -ccc-print-phases -c %t.s 2>&1 | FileCheck -check-prefix=DARWIN2 %s
end_comment

begin_comment
comment|// DARWIN2: 0: input, "{{.*}}.s", assembler-with-cpp
end_comment

begin_comment
comment|// DARWIN2: 1: preprocessor, {0}, assembler
end_comment

begin_comment
comment|// DARWIN2: 2: assembler, {1}, object
end_comment

end_unit

