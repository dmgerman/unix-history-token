begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_pragma
pragma|#
directive|pragma
name|weak
name|undef_func
end_pragma

begin_function_decl
specifier|extern
name|int
name|undef_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|ptr_to_func
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|undef_func
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|ptr_to_func
operator|==
name|NULL
condition|)
name|printf
argument_list|(
literal|"PASSED\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

