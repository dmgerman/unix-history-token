begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* extension */
end_comment

begin_function
name|void
name|a
parameter_list|(
name|void
parameter_list|)
block|{
name|double
name|__logbw
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|__extension__
argument_list|(
argument|({ __typeof((__logbw)) x_ = (__logbw); !__builtin_isinf((x_))&& !__builtin_isnan((x_)); })
argument_list|)
condition|)
name|__logbw
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

