begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|DEREF
parameter_list|(
name|p
parameter_list|)
value|*p = 0xDEADBEEF
end_define

begin_function
name|void
name|has_bug
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|DEREF
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

