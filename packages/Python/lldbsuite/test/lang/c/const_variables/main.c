begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|baaz
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
name|int32_t
name|index
decl_stmt|;
name|foo
argument_list|()
expr_stmt|;
name|index
operator|=
literal|512
expr_stmt|;
if|if
condition|(
name|bar
argument_list|()
condition|)
block|{
name|printf
argument_list|(
literal|"COMPILER PLEASE STOP HERE\n"
argument_list|)
expr_stmt|;
name|index
operator|=
literal|256
expr_stmt|;
block|}
name|baaz
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

