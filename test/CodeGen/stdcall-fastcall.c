begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm< %s | grep 'fastcallcc' | count 4
end_comment

begin_comment
comment|// RUN: clang-cc -emit-llvm< %s | grep 'stdcallcc' | count 4
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|f1
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f2
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|fastcall
operator|)
argument_list|)
name|f3
argument_list|(
name|void
argument_list|)
block|{
name|f1
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|stdcall
operator|)
argument_list|)
name|f4
argument_list|(
name|void
argument_list|)
block|{
name|f2
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|f3
argument_list|()
expr_stmt|;
name|f4
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

