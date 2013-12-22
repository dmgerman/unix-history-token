begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|int
name|using_decl_type
typedef|;
end_typedef

begin_decl_stmt
name|int
name|using_decl_var
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|UsingDecl
block|{
name|using
operator|::
name|using_decl_type
expr_stmt|;
name|using
operator|::
name|using_decl_var
expr_stmt|;
name|namespace
name|A
block|{
typedef|typedef
name|int
name|inner
typedef|;
block|}
name|using
name|A
operator|::
name|inner
expr_stmt|;
block|}
end_decl_stmt

end_unit

