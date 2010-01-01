begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
modifier|*
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|void
name|test2
argument_list|(
specifier|const
expr|struct
block|{
name|int
name|a
block|;}
operator|*
name|x
argument_list|)
block|{
name|x
operator|->
name|a
operator|=
literal|10
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|arr
index|[
literal|10
index|]
typedef|;
end_typedef

begin_function
name|void
name|test3
parameter_list|()
block|{
specifier|const
name|arr
name|b
decl_stmt|;
specifier|const
name|int
name|b2
index|[
literal|10
index|]
decl_stmt|;
name|b
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
name|b2
index|[
literal|4
index|]
operator|=
literal|1
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
block|}
end_function

end_unit

