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

begin_function_decl
specifier|extern
name|void
name|sig_die
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|G77_abort_0
parameter_list|(
name|void
parameter_list|)
block|{
name|sig_die
argument_list|(
literal|"Fortran abort routine called"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* not reached */
block|}
end_function

end_unit

