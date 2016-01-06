begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|c
init|=
literal|1
decl_stmt|;
name|int
function_decl|(
modifier|^
name|add
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
init|=
lambda|^
name|int
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|a
operator|+
name|b
operator|+
name|c
return|;
comment|// Set breakpoint 0 here.
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
function_decl|(
modifier|^
name|neg
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
lambda|^
name|int
parameter_list|(
name|int
name|a
parameter_list|)
block|{
end_function_decl

begin_return
return|return
operator|-
name|a
return|;
end_return

begin_expr_stmt
unit|};
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|add
argument_list|(
literal|3
argument_list|,
literal|4
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|neg
argument_list|(
operator|-
literal|5
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Set breakpoint 1 here.
end_comment

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

