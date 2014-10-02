begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gcc __FUNCTION__ */
end_comment

begin_function
name|void
name|foo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|=
name|__FUNCTION__
expr_stmt|;
name|foo
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

