begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -emit-llvm, -flto, and -O4 all cause a switch to llvm-bc object
end_comment

begin_comment
comment|// files.
end_comment

begin_comment
comment|// RUN: clang -ccc-print-phases -c %s -flto 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '2: compiler, {1}, llvm-bc' %t.log
end_comment

begin_comment
comment|// RUN: clang -ccc-print-phases -c %s -O4 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '2: compiler, {1}, llvm-bc' %t.log
end_comment

begin_comment
comment|// and -emit-llvm doesn't alter pipeline (unfortunately?).
end_comment

begin_comment
comment|// RUN: clang -ccc-print-phases %s -emit-llvm 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '0: input, ".*lto.c", c' %t.log
end_comment

begin_comment
comment|// RUN: grep '1: preprocessor, {0}, cpp-output' %t.log
end_comment

begin_comment
comment|// RUN: grep '2: compiler, {1}, llvm-bc' %t.log
end_comment

begin_comment
comment|// RUN: grep '3: linker, {2}, image' %t.log
end_comment

begin_comment
comment|// llvm-bc and llvm-ll outputs need to match regular suffixes
end_comment

begin_comment
comment|// (unfortunately).
end_comment

begin_comment
comment|// RUN: clang %s -emit-llvm -save-temps -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.i" "-x" "c" ".*lto\.c"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.o" .*".*lto\.i"' %t.log
end_comment

begin_comment
comment|// RUN: grep '".*a.out" .*".*lto\.o"' %t.log
end_comment

begin_comment
comment|// RUN: clang %s -emit-llvm -S -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" ".*lto\.s" "-x" "c" ".*lto\.c"' %t.log
end_comment

end_unit

