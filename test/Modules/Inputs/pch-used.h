begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|import
name|cstd
operator|.
name|stdio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|import
name|other_constants
operator|.
name|dbl_max
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
name|SPXTrace
parameter_list|()
block|{
name|fprintf
argument_list|(
name|__stderrp
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

