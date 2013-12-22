begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown-unknown -S -o - %s -emit-llvm | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown-unknown -S -o - %s -emit-llvm | FileCheck %s
end_comment

begin_typedef
typedef|typedef
struct|struct
name|float4_s
block|{
name|float
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|w
decl_stmt|;
block|}
name|float4_t
typedef|;
end_typedef

begin_function_decl
name|float4_t
name|my_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-DAG: declare %struct.float4_s @my_function
end_comment

begin_function
name|float
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
name|float4_t
name|ret
decl_stmt|;
comment|// CHECK-DAG: call %struct.float4_s @my_function
name|ret
operator|=
name|my_function
argument_list|()
expr_stmt|;
return|return
name|ret
operator|.
name|x
return|;
block|}
end_function

end_unit

