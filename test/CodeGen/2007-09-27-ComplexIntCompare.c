begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_comment
comment|// PR1708
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
name|abort
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|s
block|{
specifier|_Complex
name|unsigned
name|short
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s
name|gs
init|=
block|{
literal|100 + 200i
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|s
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{
return|return
name|gs
return|;
block|}
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
if|if
condition|(
name|foo
argument_list|()
operator|.
name|x
operator|!=
name|gs
operator|.
name|x
condition|)
name|abort
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

