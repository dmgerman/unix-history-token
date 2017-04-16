begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file tests the -Rpass family of flags (-Rpass, -Rpass-missed
end_comment

begin_comment
comment|// and -Rpass-analysis) with the inliner. The test is designed to
end_comment

begin_comment
comment|// always trigger the inliner, so it should be independent of the
end_comment

begin_comment
comment|// optimization level.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -Rpass-analysis=inline -Rpass-missed=inline -O0 -emit-llvm-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -Rpass-analysis=inline -Rpass-missed=inline -O0 -emit-llvm-only -debug-info-kind=line-tables-only -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -emit-llvm -o - 2>/dev/null | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that we can override -Rpass= with -Rno-pass.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -emit-llvm -o - 2>&1 | FileCheck %s --check-prefix=CHECK-REMARKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -Rno-pass -emit-llvm -o - 2>&1 | FileCheck %s --check-prefix=CHECK-NO-REMARKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -Rno-everything -emit-llvm -o - 2>&1 | FileCheck %s --check-prefix=CHECK-NO-REMARKS
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass=inline -Rno-everything -Reverything -emit-llvm -o - 2>&1 | FileCheck %s --check-prefix=CHECK-REMARKS
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: -Reverything should imply -Rpass=.*.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Reverything -emit-llvm -o - 2>/dev/null | FileCheck %s --check-prefix=CHECK-NO-REMARKS
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: -Rpass should either imply -Rpass=.* or should be rejected.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -Rpass -emit-llvm -o - 2>/dev/null | FileCheck %s --check-prefix=CHECK-NO-REMARKS
end_comment

begin_comment
comment|// CHECK-REMARKS: remark:
end_comment

begin_comment
comment|// CHECK-NO-REMARKS-NOT: remark:
end_comment

begin_comment
comment|// -Rpass should produce source location annotations, exclusively (just
end_comment

begin_comment
comment|// like -gmlt).
end_comment

begin_comment
comment|// CHECK: , !dbg !
end_comment

begin_comment
comment|// CHECK-NOT: DW_TAG_base_type
end_comment

begin_comment
comment|// The CU should be marked NoDebug (to prevent writing debug info to
end_comment

begin_comment
comment|// the final output).
end_comment

begin_comment
comment|// CHECK: !llvm.dbg.cu = !{![[CU:.*]]}
end_comment

begin_comment
comment|// CHECK: ![[CU]] = distinct !DICompileUnit({{.*}}emissionKind: NoDebug
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_function_decl
name|float
name|foz
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|float
name|foz
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|*
name|y
return|;
block|}
end_function

begin_comment
comment|// The negative diagnostics are emitted twice because the inliner runs
end_comment

begin_comment
comment|// twice.
end_comment

begin_comment
comment|//
end_comment

begin_function
name|int
name|bar
parameter_list|(
name|int
name|j
parameter_list|)
block|{
comment|// expected-remark@+4 {{foz not inlined into bar because it should never be inlined (cost=never)}}
comment|// expected-remark@+3 {{foz not inlined into bar because it should never be inlined (cost=never)}}
comment|// expected-remark@+2 {{foo should always be inlined}}
comment|// expected-remark@+1 {{foo inlined into bar}}
return|return
name|foo
argument_list|(
name|j
argument_list|,
name|j
operator|-
literal|2
argument_list|)
operator|*
name|foz
argument_list|(
name|j
operator|-
literal|2
argument_list|,
name|j
argument_list|)
return|;
block|}
end_function

end_unit

