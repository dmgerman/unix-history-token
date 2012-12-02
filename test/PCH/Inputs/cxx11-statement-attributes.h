begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// To be used with cxx11-statement-attributes.cpp.
end_comment

begin_expr_stmt
name|template
operator|<
specifier|const
name|int
name|N
operator|>
name|int
name|f
argument_list|(
argument|int n
argument_list|)
block|{
switch|switch
condition|(
name|n
operator|*
name|N
condition|)
block|{
case|case
literal|0
case|:
name|n
operator|+=
literal|15
expr_stmt|;
index|[
index|[
name|clang
operator|::
name|fallthrough
index|]
index|]
expr_stmt|;
comment|// This shouldn't generate a warning.
case|case
literal|1
case|:
name|n
operator|+=
literal|20
expr_stmt|;
index|[
index|[
name|clang
operator|::
name|fallthrough
index|]
index|]
expr_stmt|;
comment|// This should generate a warning: "fallthrough annotation does not directly precede switch label".
break|break;
block|}
end_expr_stmt

begin_return
return|return
name|n
return|;
end_return

unit|}
end_unit

