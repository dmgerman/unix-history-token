begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang -ccc-host-triple i386-pc-linux-gnu -emit-llvm -o %t %s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep 'unable to pass LLVM bit-code files to linker' %t.log
end_comment

begin_comment
comment|// Check that -O4 is only honored as the effective -O option.
end_comment

begin_comment
comment|//<rdar://problem/7046672> clang/loader problem
end_comment

begin_comment
comment|// RUN: %clang -ccc-print-phases -c -O4 -O0 %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=O4_AND_O0 %s< %t
end_comment

begin_comment
comment|// O4_AND_O0: 0: input, "{{.*}}", c
end_comment

begin_comment
comment|// O4_AND_O0: 1: preprocessor, {0}, cpp-output
end_comment

begin_comment
comment|// O4_AND_O0: 2: compiler, {1}, assembler
end_comment

begin_comment
comment|// O4_AND_O0: 3: assembler, {2}, object
end_comment

end_unit

