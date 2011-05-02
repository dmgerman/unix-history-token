begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm -o - %s| FileCheck %s
end_comment

begin_comment
comment|// rdar://9122143
end_comment

begin_comment
comment|// CHECK: declare void @func(i64, double)
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_str
block|{
union|union
block|{
name|long
name|double
name|a
decl_stmt|;
name|long
name|c
decl_stmt|;
block|}
union|;
block|}
name|str
typedef|;
end_typedef

begin_function_decl
name|void
name|func
parameter_list|(
name|str
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|str
name|ss
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f9122143
parameter_list|()
block|{
name|func
argument_list|(
name|ss
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

