begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_undef
undef|#
directive|undef
name|abs
end_undef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function_decl
name|void
name|f_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|s_stop
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|ftnlen
name|n
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"STOP "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
name|putc
argument_list|(
operator|*
name|s
operator|++
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" statement executed\n"
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|NO_ONEXIT
name|f_exit
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* We cannot avoid (useless) compiler diagnostics here:		*/
comment|/* some compilers complain if there is no return statement,	*/
comment|/* and others complain that this one cannot be reached.		*/
return|return
literal|0
return|;
comment|/* NOT REACHED */
block|}
end_function

end_unit

