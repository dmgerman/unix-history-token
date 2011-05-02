begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-pc-linux-gnu -emit-llvm< %s| FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test1
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
name|test1
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

begin_comment
comment|// rdar://9289468
end_comment

begin_comment
comment|// CHECK: @test2
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy.p0i8.p0i8.i32
end_comment

begin_function
name|char
modifier|*
name|test2
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|char
modifier|*
name|b
parameter_list|)
block|{
return|return
name|__builtin_memcpy
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test3
end_comment

begin_comment
comment|// CHECK: call void @llvm.memset
end_comment

begin_function
name|void
name|test3
parameter_list|(
name|char
modifier|*
name|P
parameter_list|)
block|{
name|__builtin___memset_chk
argument_list|(
name|P
argument_list|,
literal|42
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test4
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|char
modifier|*
name|P
parameter_list|,
name|char
modifier|*
name|Q
parameter_list|)
block|{
name|__builtin___memcpy_chk
argument_list|(
name|P
argument_list|,
name|Q
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test5
end_comment

begin_comment
comment|// CHECK: call void @llvm.memmove
end_comment

begin_function
name|void
name|test5
parameter_list|(
name|char
modifier|*
name|P
parameter_list|,
name|char
modifier|*
name|Q
parameter_list|)
block|{
name|__builtin___memmove_chk
argument_list|(
name|P
argument_list|,
name|Q
argument_list|,
literal|128
argument_list|,
literal|128
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test6
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy
end_comment

begin_function
name|int
name|test6
parameter_list|(
name|char
modifier|*
name|X
parameter_list|)
block|{
return|return
name|__builtin___memcpy_chk
argument_list|(
name|X
argument_list|,
name|X
argument_list|,
literal|42
argument_list|,
literal|42
argument_list|)
operator|!=
literal|0
return|;
block|}
end_function

end_unit

