begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-pc-linux-gnu -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@llvm.memset.i32' %t
end_comment

begin_comment
comment|// RUN: grep '@llvm.memcpy.i32' %t
end_comment

begin_comment
comment|// RUN: grep '@llvm.memmove.i32' %t
end_comment

begin_comment
comment|// RUN: grep __builtin %t | count 0
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

