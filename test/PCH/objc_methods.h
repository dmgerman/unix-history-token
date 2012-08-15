begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For use with the methods.m test */
end_comment

begin_expr_stmt
unit|@
name|interface
name|TestPCH
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|instancetype
operator|)
name|instMethod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|class
name|TestForwardClassDecl
expr_stmt|;
end_expr_stmt

begin_comment
comment|// FIXME: @compatibility_alias  AliasForTestPCH TestPCH;
end_comment

begin_comment
comment|// http://llvm.org/PR12689
end_comment

begin_expr_stmt
unit|@
name|interface
name|PR12689
expr|@
name|end
expr|@
name|implementation
name|PR12689
operator|-
operator|(
name|void
operator|)
name|mugi
operator|:
operator|(
name|int
operator|)
name|x
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|23
case|:
block|{
block|}
end_expr_stmt

begin_expr_stmt
unit|} }
operator|-
operator|(
name|void
operator|)
name|bonk
operator|:
operator|(
name|int
operator|)
name|x
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|42
case|:
block|{
block|}
end_expr_stmt

begin_expr_stmt
unit|} } @
name|end
expr|@
name|interface
name|PR12689_2
expr|@
name|end
expr|@
name|implementation
name|PR12689_2
operator|-
operator|(
name|void
operator|)
name|mugi
operator|:
operator|(
name|int
operator|)
name|x
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|23
case|:
index|[
name|self
name|bonk
operator|:
name|x
index|]
expr_stmt|;
break|break;
case|case
literal|82
case|:
break|break;
block|}
end_expr_stmt

begin_expr_stmt
unit|} -
operator|(
name|void
operator|)
name|bonk
operator|:
operator|(
name|int
operator|)
name|x
block|{ }
expr|@
name|end
end_expr_stmt

end_unit

