begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -g %s -emit-llvm -o %t -fblocks
end_comment

begin_comment
comment|// RUN: grep "func.start" %t | count 4
end_comment

begin_comment
comment|// RUN: clang-cc -g %s -triple i386-unknown-unknown -emit-llvm -o %t -fblocks -fblock-introspection
end_comment

begin_comment
comment|// RUN: grep "v8@?0i4" %t | count 1
end_comment

begin_comment
comment|// RUN: clang-cc -g %s -triple i386-unknown-unknown -emit-llvm -o %t -fblocks
end_comment

begin_comment
comment|// RUN: grep "v8@?0i4" %t | count 0
end_comment

begin_comment
comment|// 1 declaration, 1 bar, 1 test_block_dbg and 1 for the block.
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|int
name|bar
argument_list|(
name|int
name|va
argument_list|,
name|int
name|vb
argument_list|)
block|{
return|return
operator|(
name|va
operator|==
name|vb
operator|)
return|;
block|}
end_decl_stmt

begin_function
name|int
name|test_block_dbg
parameter_list|()
block|{
specifier|extern
name|int
name|g
decl_stmt|;
specifier|static
name|int
name|i
init|=
literal|1
decl_stmt|;
lambda|^
parameter_list|(
name|int
name|j
parameter_list|)
block|{
name|i
operator|=
name|bar
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|i
operator|+
name|g
return|;
block|}
end_function

end_unit

