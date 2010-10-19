begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
specifier|static
name|void
name|preinit_0
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"preinit array 0\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|preinit_1
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"preinit array 1\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|preinit_2
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"preinit array 2\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|void
argument_list|(
argument|*const preinit_array []
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|void
operator|)
name|__attribute__
argument_list|(
operator|(
name|section
argument_list|(
literal|".preinit_array"
argument_list|)
operator|,
name|aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
operator|)
argument_list|)
operator|=
block|{
operator|&
name|preinit_0
block|,
operator|&
name|preinit_1
block|,
operator|&
name|preinit_2
block|}
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

