begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|var
init|=
literal|123
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|foo
init|=
literal|121
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|var2
index|[
literal|2
index|]
init|=
block|{
literal|123
block|,
literal|456
block|}
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|print_var
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"DLL sees var = %d\n"
argument_list|,
name|var
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|print_foo
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"DLL sees foo = %d\n"
argument_list|,
name|foo
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
function_decl|(
modifier|*
name|func_ptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|print_foo
function_decl|;
end_function_decl

end_unit

