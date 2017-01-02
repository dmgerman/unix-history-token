begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|T_H
end_ifndef

begin_define
define|#
directive|define
name|T_H
end_define

begin_expr_stmt
name|template
operator|<
name|typename
name|ValueType
operator|>
expr|struct
name|VarStreamArray
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ValueType
operator|>
expr|struct
name|VarStreamArrayIterator
block|{
name|VarStreamArrayIterator
argument_list|(
argument|VarStreamArray<ValueType>
argument_list|)
block|{}
name|bool
name|HasError
block|{}
block|; }
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// T_H
end_comment

end_unit

