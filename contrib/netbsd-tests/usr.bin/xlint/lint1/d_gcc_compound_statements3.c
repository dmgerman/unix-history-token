begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GCC compound statements with void type */
end_comment

begin_function
name|void
name|main
parameter_list|(
name|void
parameter_list|)
block|{
operator|(
block|{
name|void
operator|*
name|v
block|;
name|__asm__
specifier|volatile
operator|(
literal|"noop"
operator|)
block|; 	}
operator|)
expr_stmt|;
block|}
end_function

end_unit

