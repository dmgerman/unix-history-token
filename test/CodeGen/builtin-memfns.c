begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset.p0i8.i32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset.p0i8.i32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i32
end_comment

begin_comment
comment|// CHECK: call void @llvm.memmove.p0i8.p0i8.i32
end_comment

begin_comment
comment|// CHECK-NOT: __builtin
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|unsigned
name|char
name|a
init|=
literal|0x11223344
decl_stmt|;
name|unsigned
name|char
name|b
init|=
literal|0x11223344
decl_stmt|;
name|__builtin_bzero
argument_list|(
operator|&
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|__builtin_memset
argument_list|(
operator|&
name|a
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|__builtin_memcpy
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|__builtin_memmove
argument_list|(
operator|&
name|a
argument_list|,
operator|&
name|b
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

