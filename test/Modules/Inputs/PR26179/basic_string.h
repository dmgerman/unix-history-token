begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_STRING
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_STRING
value|1
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|basic_string
block|{
specifier|static
name|T
name|_S_empty_rep_storage
index|[]
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|basic_string
operator|<
name|T
operator|>
operator|::
name|_S_empty_rep_storage
index|[
sizeof|sizeof
argument_list|(
name|T
argument_list|)
index|]
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

