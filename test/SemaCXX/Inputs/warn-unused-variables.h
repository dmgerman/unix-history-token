begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that we don't warn about variables of internal-linkage type in
end_comment

begin_comment
comment|// headers, as the use may be in another TU.
end_comment

begin_decl_stmt
name|namespace
name|PR15558
block|{
name|namespace
block|{
name|class
name|A
block|{}
empty_stmt|;
block|}
name|class
name|B
block|{
specifier|static
name|A
name|a
decl_stmt|;
specifier|static
name|A
name|b
decl_stmt|;
specifier|static
specifier|const
name|int
name|x
init|=
sizeof|sizeof
argument_list|(
name|b
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

end_unit

