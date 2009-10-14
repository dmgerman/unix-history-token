begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|interface
name|Base
block|{
name|int
name|my_var
decl_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|my_var
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|my_method
operator|:
operator|(
name|int
operator|)
name|param
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|void
operator|)
name|my_method
operator|:
operator|(
name|int
operator|)
name|param
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Sub
operator|:
name|Base
operator|-
operator|(
name|void
operator|)
name|my_method
operator|:
operator|(
name|int
operator|)
name|param
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

