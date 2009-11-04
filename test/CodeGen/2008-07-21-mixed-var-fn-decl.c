begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|g0
decl_stmt|,
name|f0
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|f1
argument_list|()
decl_stmt|,
name|g1
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @g0 = common global i32 0, align 4
end_comment

begin_comment
comment|// CHECK: @g1 = common global i32 0, align 4
end_comment

end_unit

