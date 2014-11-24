begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|S
block|{
name|__attribute__
argument_list|(
argument|(always_inline)
argument_list|)
specifier|static
name|int
name|f
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|__attribute__
argument_list|(
argument|(always_inline, visibility(
literal|"hidden"
argument|))
argument_list|)
specifier|static
name|int
name|g
argument_list|()
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_extern
unit|};
extern|extern template struct S<int>;
end_extern

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|min
argument_list|(
argument|T a
argument_list|,
argument|T b
argument_list|)
block|{
return|return
name|a
operator|<
name|b
operator|?
name|a
operator|:
name|b
return|;
block|}
end_expr_stmt

begin_extern
extern|extern decltype(min(1
operator|,
extern|2
end_extern

begin_expr_stmt
unit|))
name|instantiate_min_decl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CtorInit
block|{
specifier|static
name|int
name|f
argument_list|()
block|{
return|return
literal|0
return|;
block|}
name|int
name|a
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CtorInit
argument_list|()
operator|:
name|a
argument_list|(
argument|f()
argument_list|)
block|{}
end_expr_stmt

unit|};
end_unit

