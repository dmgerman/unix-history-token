begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bsd-interf.c: test BSD interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* whole file */
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_function
name|void
name|test_berk_search
parameter_list|(
name|pattern
parameter_list|,
name|string
parameter_list|)
specifier|const
name|char
modifier|*
name|pattern
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|return_value
init|=
name|re_comp
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
if|if
condition|(
name|return_value
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"This didn't compile: `%s'.\n"
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  The error message was: `%s'.\n"
argument_list|,
name|return_value
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|test_should_match
operator|&&
name|re_exec
argument_list|(
name|string
argument_list|)
operator|!=
name|strlen
argument_list|(
name|string
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"Should have matched but didn't:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  The pattern was: %s.\n"
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
if|if
condition|(
name|string
condition|)
name|printf
argument_list|(
literal|"  The string was: `%s'.'n"
argument_list|,
name|string
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"  The string was empty.\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|test_bsd_interface
parameter_list|()
block|{
name|test_berk_search
argument_list|(
literal|"a"
argument_list|,
literal|"ab"
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

end_unit

