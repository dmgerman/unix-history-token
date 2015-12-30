begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|import
name|top
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|f
argument_list|(
argument|int k
argument_list|,
argument|...
argument_list|)
block|{
name|va_list
name|va
block|;
name|__builtin_va_start
argument_list|(
name|va
argument_list|,
name|k
argument_list|)
block|; }
end_expr_stmt

end_unit

