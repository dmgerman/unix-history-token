begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple x86_64-apple-darwin9 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep 'float 0x7FF8000000000000, float 0x7FF8000000000000, float 0x7FF8000020000000, float 0x7FF8000000000000, float 0x7FF80001E0000000, float 0x7FF8001E00000000, float 0x7FF801E000000000, float 0x7FF81E0000000000, float 0x7FF9E00000000000, float 0x7FFFFFFFE0000000' %t
end_comment

begin_decl_stmt
name|float
name|n
index|[]
init|=
block|{
name|__builtin_nanf
argument_list|(
literal|"0"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|""
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"1"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0x7fc00000"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0x7fc0000f"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0x7fc000f0"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0x7fc00f00"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0x7fc0f000"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0x7fcf0000"
argument_list|)
block|,
name|__builtin_nanf
argument_list|(
literal|"0xffffffff"
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

end_unit

