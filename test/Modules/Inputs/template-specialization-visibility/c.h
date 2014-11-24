begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|C_H
end_ifndef

begin_define
define|#
directive|define
name|C_H
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|S
block|{
name|int
name|n
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
expr|struct
name|T
operator|<
name|U
operator|>
operator|::
name|S
block|{
name|int
name|n
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
expr|enum
name|T
operator|<
name|U
operator|>
operator|::
name|E
operator|:
name|int
block|{
name|e
block|}
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

