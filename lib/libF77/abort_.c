begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|VOID
name|sig_die
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|int
name|abort_
argument_list|()
else|#
directive|else
specifier|extern
name|void
name|sig_die
argument_list|(
name|char
operator|*
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|abort_
parameter_list|(
name|void
parameter_list|)
endif|#
directive|endif
block|{
name|sig_die
argument_list|(
literal|"Fortran abort routine called"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function

end_unit

