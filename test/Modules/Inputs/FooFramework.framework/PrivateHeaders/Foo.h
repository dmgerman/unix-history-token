begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|__attribute__
argument_list|(
operator|(
name|objc_root_class
operator|)
argument_list|)
expr|@
name|interface
name|NSObject
operator|+
operator|(
name|instancetype
operator|)
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|instancetype
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|instancetype
operator|)
name|retain
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|release
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|Foo
operator|:
name|NSObject
expr|@
name|end
end_expr_stmt

end_unit

