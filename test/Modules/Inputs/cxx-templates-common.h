begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SomeTemplate
block|{}
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|DefinedInCommon
block|{
name|void
name|f
parameter_list|()
function_decl|;
struct|struct
name|Inner
block|{}
struct|;
name|friend
name|void
name|FoundByADL
parameter_list|(
name|DefinedInCommon
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CommonTemplate
block|{   enum
name|E
block|{
name|a
operator|=
literal|1
block|,
name|b
operator|=
literal|2
block|,
name|c
operator|=
literal|3
block|}
block|; }
expr_stmt|;
end_expr_stmt

end_unit

