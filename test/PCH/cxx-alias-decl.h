begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for PCH test cxx-alias-decl.cpp
end_comment

begin_struct
struct|struct
name|S
block|{}
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
expr|struct
name|T
block|{
name|template
operator|<
name|typename
name|V
operator|>
name|using
name|A
operator|=
name|T
operator|<
name|V
operator|>
block|; }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|using
name|A
init|=
name|int
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|using
name|B
operator|=
name|S
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|using
name|C
operator|=
name|T
operator|<
name|U
operator|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|,
name|typename
name|V
operator|>
name|using
name|D
operator|=
name|typename
name|T
operator|<
name|U
operator|>
operator|::
name|template
name|A
operator|<
name|V
operator|>
expr_stmt|;
end_expr_stmt

end_unit

