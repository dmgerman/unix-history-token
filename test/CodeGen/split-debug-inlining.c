begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=limited -fno-split-dwarf-inlining -S -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -debug-info-kind=limited -S -emit-llvm -o - %s | FileCheck --check-prefix=ABSENT %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// Verify that disabling split debug inlining info is propagated to the debug
end_comment

begin_comment
comment|// info metadata.
end_comment

begin_comment
comment|// CHECK: !DICompileUnit({{.*}}, splitDebugInlining: false
end_comment

begin_comment
comment|// ABSENT-NOT: splitDebugInlining
end_comment

end_unit

