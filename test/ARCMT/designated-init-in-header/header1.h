begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NS_DESIGNATED_INITIALIZER
value|__attribute__((objc_designated_initializer))
end_define

begin_decl_stmt
unit|@
name|class
name|NSString
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|interface
name|B1
operator|-
operator|(
name|id
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|S1
operator|:
name|B1
operator|-
operator|(
name|int
operator|)
name|prop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|setProp
operator|:
operator|(
name|int
operator|)
name|p
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|id
operator|)
name|s1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|initWithFoo
operator|:
operator|(
name|NSString
operator|*
operator|)
name|foo
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

