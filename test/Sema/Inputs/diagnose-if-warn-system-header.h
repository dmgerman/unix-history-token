begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_function
specifier|inline
name|int
name|system_header_func
parameter_list|(
name|int
name|x
parameter_list|)
function|__attribute__
parameter_list|(
function|(diagnose_if
parameter_list|(
function|x == x
operator|,
function|"system header warning"
operator|,
function|"warning"
end_function

begin_comment
unit|)))
comment|// expected-note {{from 'diagnose_if' attribute}}
end_comment

begin_block
block|{
return|return
literal|0
return|;
block|}
end_block

begin_function
name|void
name|test_system_header
parameter_list|()
block|{
name|system_header_func
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{system header warning}}
block|}
end_function

end_unit

