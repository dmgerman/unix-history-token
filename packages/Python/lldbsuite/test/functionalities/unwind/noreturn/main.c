begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function_decl
specifier|static
name|void
name|func_a
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|func_b
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noreturn
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|static
name|void
name|func_c
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|void
name|func_c
parameter_list|(
name|void
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|func_b
parameter_list|(
name|void
parameter_list|)
block|{
name|func_c
argument_list|()
expr_stmt|;
while|while
condition|(
literal|1
condition|)
empty_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|func_a
parameter_list|(
name|void
parameter_list|)
block|{
name|func_b
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|func_a
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

