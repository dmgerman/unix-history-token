begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -gline-tables-only -S -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Checks that clang with "-gline-tables-only" emits metadata for
end_comment

begin_comment
comment|// compile unit, subprogram and file.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: ret i32 0, !dbg
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: !llvm.dbg.cu = !{!0}
end_comment

begin_comment
comment|// CHECK: DW_TAG_compile_unit
end_comment

begin_comment
comment|// CHECK: {{.*main.* DW_TAG_subprogram}}
end_comment

begin_comment
comment|// CHECK: DW_TAG_file_type
end_comment

end_unit

