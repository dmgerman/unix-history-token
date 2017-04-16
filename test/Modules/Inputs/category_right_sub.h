begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|interface
name|Foo
argument_list|(
name|RightSub
argument_list|)
decl|<
name|P2
decl|> @
name|property
name|id
name|right_sub_prop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Foo
argument_list|()
block|{ @
name|public
name|int
name|right_sub_ivar
block|; }
expr|@
name|end
expr|@
name|protocol
name|P4
operator|-
operator|(
name|void
operator|)
name|p4_method
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
name|p4_prop
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Foo
argument_list|(
name|LeftP4
argument_list|)
operator|<
name|P4
operator|>
expr|@
name|end
comment|// A hidden extension
expr|@
name|interface
name|Foo
argument_list|()
expr|@
name|property
argument_list|(
argument|assign
argument_list|)
name|int
name|hiddenPropertyFromExtension
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

