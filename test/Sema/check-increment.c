begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
modifier|*
name|pint
typedef|;
end_typedef

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|a
index|[
literal|5
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|pint
name|p
init|=
name|a
decl_stmt|;
name|p
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
operator|*
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

