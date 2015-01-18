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

begin_function
name|float4_t
name|my_function
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define %struct.float4_s @my_function
name|float4_t
name|t
decl_stmt|;
return|return
name|t
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
comment|// CHECK-LABEL: @bar
comment|// CHECK: call %struct.float4_s @my_function
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

begin_function
name|void
name|foo
parameter_list|(
name|float4_t
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @foo
comment|// CHECK: %struct.float4_s* byval %x
block|}
end_function

begin_function
name|void
name|fooN
parameter_list|(
name|float4_t
name|x
parameter_list|,
name|float4_t
name|y
parameter_list|,
name|float4_t
name|z
parameter_list|)
block|{
comment|// CHECK-LABEL: @fooN
comment|// CHECK: %struct.float4_s* byval %x
comment|// CHECK: %struct.float4_s* byval %y
comment|// CHECK: %struct.float4_s* byval %z
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
name|nested_s
block|{
name|unsigned
name|long
name|long
name|x
decl_stmt|;
name|float
name|z
index|[
literal|64
index|]
decl_stmt|;
name|float4_t
name|t
decl_stmt|;
block|}
name|nested_t
typedef|;
end_typedef

begin_function
name|void
name|baz
parameter_list|(
name|nested_t
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @baz
comment|// CHECK: %struct.nested_s* byval %x)
block|}
end_function

end_unit

