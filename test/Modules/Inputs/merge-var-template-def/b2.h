begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|B2_H
end_ifndef

begin_define
define|#
directive|define
name|B2_H
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|T
name|v
operator|>
expr|struct
name|S
block|{
specifier|static
name|constexpr
name|T
name|value
operator|=
name|v
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|T
name|v
operator|>
name|constexpr
name|T
name|S
operator|<
name|T
operator|,
name|v
operator|>
operator|::
name|value
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

