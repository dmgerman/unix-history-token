begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|BEGIN
name|template
operator|<
name|typename
name|T
operator|=
name|void
operator|>
expr|struct
name|L
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|FriendL
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|friend
expr|struct
name|L
expr_stmt|;
block|}
struct|;
end_struct

begin_macro
name|END
end_macro

end_unit

