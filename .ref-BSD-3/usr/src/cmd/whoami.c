begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_comment
comment|/*  * whoami  */
end_comment

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|struct
name|passwd
modifier|*
name|pp
decl_stmt|;
name|pp
operator|=
name|getpwuid
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|pp
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Intruder alert.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|pp
operator|->
name|pw_name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

