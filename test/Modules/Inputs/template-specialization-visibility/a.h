begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|A_H
end_ifndef

begin_define
define|#
directive|define
name|A_H
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|S
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
block|{   struct
name|S
block|;   enum
name|E
operator|:
name|int
block|; }
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

