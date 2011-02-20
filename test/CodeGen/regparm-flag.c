begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -mregparm 4 %s -emit-llvm -o %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|,
name|int
name|e
parameter_list|,
name|int
name|f
parameter_list|,
name|int
name|g
parameter_list|,
name|int
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|()
block|{
comment|// CHECK: call void @f1(i32 inreg 1, i32 inreg 2, i32 inreg 3, i32 inreg 4,
comment|// CHECK: i32 5, i32 6, i32 7, i32 8)
name|f1
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|,
literal|7
argument_list|,
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare void @f1(i32 inreg, i32 inreg, i32 inreg, i32 inreg,
end_comment

begin_comment
comment|// CHECK: i32, i32, i32, i32)
end_comment

end_unit

