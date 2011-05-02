begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-checker=core -analyzer-store=flat -verify %s
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|int
modifier|*
name|p
decl_stmt|;
name|x
operator|=
literal|1
expr_stmt|;
name|p
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|x
operator|!=
literal|1
condition|)
operator|*
name|p
operator|=
literal|1
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

