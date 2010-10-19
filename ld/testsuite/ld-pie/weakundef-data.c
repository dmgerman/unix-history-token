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
name|undef_data
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|undef_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|ptr_to_data
init|=
operator|&
name|undef_data
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|ptr_to_data
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

