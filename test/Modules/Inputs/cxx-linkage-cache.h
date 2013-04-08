begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Reduced from a crash encountered with a modularized libc++, where
end_comment

begin_comment
comment|// we would try to compute the linkage of a declaration before we
end_comment

begin_comment
comment|// finish loading the relevant pieces of it.
end_comment

begin_decl_stmt
specifier|inline
name|namespace
name|D
block|{
name|template
operator|<
name|class
operator|>
expr|struct
name|U
block|{
name|friend
name|bool
name|f
argument_list|(
specifier|const
name|U
operator|&
argument_list|)
block|;   }
expr_stmt|;
name|template
name|class
name|U
operator|<
name|int
operator|>
expr_stmt|;
block|}
end_decl_stmt

end_unit

