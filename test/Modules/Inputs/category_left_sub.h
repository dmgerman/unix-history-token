begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|interface
name|Foo
argument_list|(
name|LeftSub
argument_list|)
decl|<
name|P1
decl|> -
argument_list|(
name|void
argument_list|)
name|left_sub
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|protocol
name|P3
operator|-
operator|(
name|void
operator|)
name|p3_method
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|property
argument_list|(
argument|retain
argument_list|)
end_macro

begin_decl_stmt
name|id
name|p3_prop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Foo
argument_list|(
name|LeftP3
argument_list|)
operator|<
name|P3
operator|>
expr|@
name|end
end_expr_stmt

end_unit

