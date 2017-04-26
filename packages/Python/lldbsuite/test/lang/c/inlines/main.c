begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|inline
name|void
name|test1
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|inline
name|void
name|test2
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|test2
parameter_list|(
name|int
name|b
parameter_list|)
block|{
name|printf
argument_list|(
literal|"test2(%d)\n"
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|//% self.expect("expression b", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["42"])
block|{
name|int
name|c
init|=
name|b
operator|*
literal|2
decl_stmt|;
name|printf
argument_list|(
literal|"c=%d\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|//% self.expect("expression b", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["42"])
comment|//% self.expect("expression c", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["84"])
block|}
block|}
end_function

begin_function
name|void
name|test1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|printf
argument_list|(
literal|"test1(%d)\n"
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|test2
argument_list|(
name|a
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|//% self.dbg.HandleCommand("step")
comment|//% self.expect("expression b", DATA_TYPES_DISPLAYED_CORRECTLY, substrs = ["24"])
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|test2
argument_list|(
literal|42
argument_list|)
expr_stmt|;
name|test1
argument_list|(
literal|23
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

