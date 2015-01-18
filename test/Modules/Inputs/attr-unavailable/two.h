begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|interface
name|A
operator|-
operator|(
name|void
operator|)
name|method1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|B
operator|-
operator|(
name|void
operator|)
name|method1
name|__attribute__
argument_list|(
operator|(
name|unavailable
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

