begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s
end_comment

begin_typedef
typedef|typedef
name|struct
name|foo
name|foo
typedef|;
end_typedef

begin_function
name|void
name|blah
parameter_list|(
name|int
name|foo
parameter_list|)
block|{
name|foo
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

