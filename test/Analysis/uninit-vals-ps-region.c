begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -analyze -checker-simple -analyzer-store=region -verify %s
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|s
name|global
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|g
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|f4
parameter_list|()
block|{
name|int
name|a
decl_stmt|;
if|if
condition|(
name|global
operator|.
name|data
operator|==
literal|0
condition|)
name|a
operator|=
literal|3
expr_stmt|;
if|if
condition|(
name|global
operator|.
name|data
operator|==
literal|0
condition|)
comment|// When the true branch is feasible 'a = 3'.
name|g
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

end_unit

