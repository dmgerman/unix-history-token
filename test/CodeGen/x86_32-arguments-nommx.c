begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -target-feature -mmx -target-feature +sse2 -triple i686-pc-linux-gnu -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// no-mmx should put mmx into memory
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|i32v2
typedef|;
end_typedef

begin_function
name|int
name|a
parameter_list|(
name|i32v2
name|x
parameter_list|)
block|{
return|return
name|x
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @a(i64 %x.coerce)
end_comment

begin_comment
comment|// but SSE2 vectors should still go into an SSE2 register
end_comment

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
name|i32v4
typedef|;
end_typedef

begin_function
name|int
name|b
parameter_list|(
name|i32v4
name|x
parameter_list|)
block|{
return|return
name|x
index|[
literal|0
index|]
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @b(<4 x i32> %x)
end_comment

end_unit

