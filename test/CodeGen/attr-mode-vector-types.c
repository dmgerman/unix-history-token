begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|byte
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
name|vec_t1
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|vec_t2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|SI
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|vec_t3
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|DI
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|vec_t4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|SF
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|128
argument_list|)
operator|)
argument_list|)
name|vec_t5
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|DF
argument_list|)
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
name|vec_t6
typedef|;
end_typedef

begin_function
name|void
name|check
parameter_list|()
block|{
comment|// CHECK: alloca<4 x i8>
name|vec_t1
name|v1
decl_stmt|;
comment|// CHECK: alloca<8 x i8>
name|vec_t2
name|v2
decl_stmt|;
comment|// CHECK: alloca<4 x i32>
name|vec_t3
name|v3
decl_stmt|;
comment|// CHECK: alloca<8 x i64>
name|vec_t4
name|v4
decl_stmt|;
comment|// CHECK: alloca<32 x float>
name|vec_t5
name|v5
decl_stmt|;
comment|// CHECK: alloca<32 x double>
name|vec_t6
name|v6
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: ret i32 4
end_comment

begin_function
name|int
name|check_size1
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|vec_t1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: ret i32 8
end_comment

begin_function
name|int
name|check_size2
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|vec_t2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: ret i32 16
end_comment

begin_function
name|int
name|check_size3
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|vec_t3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: ret i32 64
end_comment

begin_function
name|int
name|check_size4
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|vec_t4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: ret i32 128
end_comment

begin_function
name|int
name|check_size5
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|vec_t5
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: ret i32 256
end_comment

begin_function
name|int
name|check_size6
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
name|vec_t6
argument_list|)
return|;
block|}
end_function

end_unit

