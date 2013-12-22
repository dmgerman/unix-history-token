begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -triple i386-apple-macosx10.7.2< %s | FileCheck %s
end_comment

begin_comment
comment|// The preferred alignment for a long long on x86-32 is 8; make sure the
end_comment

begin_comment
comment|// alloca for x uses that alignment.
end_comment

begin_function
name|int
name|test
parameter_list|(
name|long
name|long
name|x
parameter_list|)
block|{
return|return
operator|(
name|int
operator|)
name|x
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test
end_comment

begin_comment
comment|// CHECK: alloca i64, align 8
end_comment

begin_comment
comment|// Make sure we honor the aligned attribute.
end_comment

begin_struct
struct|struct
name|X
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|test2
argument_list|(
expr|struct
name|X
name|x
name|__attribute
argument_list|(
operator|(
name|aligned
argument_list|(
literal|16
argument_list|)
operator|)
argument_list|)
argument_list|)
block|{
return|return
name|x
operator|.
name|z
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @test2
end_comment

begin_comment
comment|// CHECK: alloca %struct.X, align 16
end_comment

end_unit

