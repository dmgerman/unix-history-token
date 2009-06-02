begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For use with the objc_property.m PCH test */
end_comment

begin_decl_stmt
unit|@
name|interface
name|TestProperties
block|{
name|int
name|value
decl_stmt|;
name|float
name|percentage
decl_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|property
name|int
name|value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|property
name|float
name|percentage
decl_stmt|;
end_decl_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

