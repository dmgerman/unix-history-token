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
name|A
block|{
name|template
operator|<
name|typename
name|I
operator|>
name|A
argument_list|(
argument|I i1
argument_list|,
argument|I i2
argument_list|)
block|{   }
name|A
argument_list|(
argument|double
argument_list|)
block|{}
name|A
argument_list|(
argument|double
argument_list|,
argument|double
argument_list|)
block|{}
name|A
argument_list|(
argument|double
argument_list|,
argument|int
argument_list|)
block|{}
name|A
argument_list|(
argument|int
argument_list|,
argument|double
argument_list|)
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|T1
name|fff
argument_list|(
argument|T2* t
argument_list|)
block|{
return|return
name|T1
argument_list|(
name|t
argument_list|,
name|t
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|A
operator|<
name|int
operator|>
name|ff
argument_list|(
argument|int i
argument_list|)
block|{
return|return
name|fff
operator|<
name|A
operator|<
name|int
operator|>>
operator|(
operator|&
name|i
operator|)
return|;
block|}
end_expr_stmt

begin_struct
struct|struct
name|Aggregate
block|{
name|int
name|member
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
name|Aggregate
operator|,
name|Aggregate
operator|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

