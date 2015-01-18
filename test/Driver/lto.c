begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -flto causes a switch to llvm-bc object files.
end_comment

begin_comment
comment|// RUN: %clang -ccc-print-phases -c %s -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '2: compiler, {1}, ir' %t.log
end_comment

begin_comment
comment|// RUN: grep '3: backend, {2}, lto-bc' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-print-phases %s -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '0: input, ".*lto.c", c' %t.log
end_comment

begin_comment
comment|// RUN: grep '1: preprocessor, {0}, cpp-output' %t.log
end_comment

begin_comment
comment|// RUN: grep '2: compiler, {1}, ir' %t.log
end_comment

begin_comment
comment|// RUN: grep '3: backend, {2}, lto-bc' %t.log
end_comment

begin_comment
comment|// RUN: grep '4: linker, {3}, image' %t.log
end_comment

begin_comment
comment|// llvm-bc and llvm-ll outputs need to match regular suffixes
end_comment

begin_comment
comment|// (unfortunately).
end_comment

begin_comment
comment|// RUN: %clang %s -flto -save-temps -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.i" "-x" "c" ".*lto\.c"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.bc" .*".*lto\.i"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.o" .*".*lto\.bc"' %t.log
end_comment

begin_comment
comment|// RUN: grep '".*a\.\(out\|exe\)" .*".*lto\.o"' %t.log
end_comment

begin_comment
comment|// RUN: %clang %s -flto -S -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.s" "-x" "c" ".*lto\.c"' %t.log
end_comment

begin_comment
comment|// RUN: not %clang %s -emit-llvm 2>&1 | FileCheck --check-prefix=LLVM-LINK %s
end_comment

begin_comment
comment|// LLVM-LINK: -emit-llvm cannot be used when linking
end_comment

end_unit

