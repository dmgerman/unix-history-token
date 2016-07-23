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
end_define

begin_expr_stmt
name|template
operator|<
name|typename
operator|>
expr|struct
name|basic_string
block|{   struct
name|_Alloc_hider
block|{}
name|_M_dataplus
block|;
operator|~
name|basic_string
argument_list|()
block|{
name|_Alloc_hider
name|h
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern template class basic_string<char>;
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

