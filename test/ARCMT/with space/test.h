begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|protocol
name|NSObject
operator|-
operator|(
name|oneway
name|void
operator|)
name|release
expr_stmt|;
end_expr_stmt

begin_function
unit|@
name|end
ifdef|#
directive|ifdef
name|PART1
specifier|static
specifier|inline
name|void
name|part1
parameter_list|(
name|id
name|p
parameter_list|)
block|{
index|[
name|p
name|release
index|]
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PART2
end_ifdef

begin_function
specifier|static
specifier|inline
name|void
name|part2
parameter_list|(
name|id
name|p
parameter_list|)
block|{
index|[
name|p
name|release
index|]
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

