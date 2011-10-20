begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -O2 %s -o /dev/null
end_comment

begin_comment
comment|// PR2292.
end_comment

begin_decl_stmt
name|__inline__
name|__attribute__
argument_list|(
operator|(
name|__pure__
operator|)
argument_list|)
name|int
name|g
argument_list|(
name|void
argument_list|)
block|{}
end_decl_stmt

begin_function
name|void
name|f
parameter_list|(
name|int
name|k
parameter_list|)
block|{
name|k
operator|=
name|g
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

