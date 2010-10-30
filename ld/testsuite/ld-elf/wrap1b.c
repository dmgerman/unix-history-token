begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|void
name|par
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|__real_par
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"__real_par \n"
argument_list|)
expr_stmt|;
name|par
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__wrap_par
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"__wrap_par \n"
argument_list|)
expr_stmt|;
name|__real_par
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

