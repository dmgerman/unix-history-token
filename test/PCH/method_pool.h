begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For use with the method_pool.m test */
end_comment

begin_comment
comment|/* Whitespace below is significant */
end_comment

begin_expr_stmt
unit|@
name|interface
name|TestMethodPool1
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|double
operator|)
name|instMethod
operator|:
operator|(
name|int
operator|)
name|foo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|TestMethodPool2
operator|-
operator|(
name|char
operator|)
name|instMethod
operator|:
operator|(
name|int
operator|)
name|foo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|implementation
name|TestMethodPool1
operator|+
name|alloc
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|double
operator|)
name|instMethod
operator|:
operator|(
name|int
operator|)
name|foo
block|{
return|return
name|foo
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|implementation
name|TestMethodPool2
operator|-
operator|(
name|char
operator|)
name|instMethod
operator|:
operator|(
name|int
operator|)
name|foo
block|{
return|return
name|foo
return|;
block|}
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

end_unit

