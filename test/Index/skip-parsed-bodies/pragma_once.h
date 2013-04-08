begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|some_val
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TS
block|{
name|int
name|tsmeth
argument_list|()
block|{
operator|++
name|some_val
block|;
return|return
name|undef_tsval
return|;
block|}
end_expr_stmt

unit|};
end_unit

