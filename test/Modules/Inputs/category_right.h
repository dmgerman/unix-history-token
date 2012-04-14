begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|__experimental_modules_import
name|category_top
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|@
name|interface
name|Foo
argument_list|(
name|Right1
argument_list|)
decl|-
argument_list|(
name|void
argument_list|)
name|right1
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Foo
argument_list|(
name|Right2
argument_list|)
operator|-
operator|(
name|void
operator|)
name|right2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Foo
argument_list|(
name|Duplicate
argument_list|)
comment|// expected-warning {{duplicate definition of category}}
expr|@
name|end
end_expr_stmt

end_unit

