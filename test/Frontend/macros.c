begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DA= -DB=1 -verify -fsyntax-only %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_decl_stmt
name|int
name|a
index|[
operator|(
name|B
name|A
operator|)
operator|==
literal|1
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR13747 - Don't warn about unused results with statement exprs in macros.
end_comment

begin_function_decl
name|void
name|stuff
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|({ stuff(x,y,z); x; })
end_define

begin_function
name|void
name|foo
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|memset
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// No warning!
block|}
end_function

end_unit

