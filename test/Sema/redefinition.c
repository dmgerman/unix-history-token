begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_function
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-error {{redefinition of 'f'}}
end_comment

begin_comment
comment|//<rdar://problem/6097326>
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|x
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|int
name|x
init|=
literal|1
decl_stmt|;
end_decl_stmt

end_unit

