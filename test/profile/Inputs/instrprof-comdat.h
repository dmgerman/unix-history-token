begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Template instantiations are placed into comdat sections. Check that
end_comment

begin_comment
comment|// coverage data from different instantiations are mapped back to the correct
end_comment

begin_comment
comment|// source regions.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|FOO
block|{
name|public
operator|:
name|FOO
argument_list|()
operator|:
name|t
argument_list|(
literal|0
argument_list|)
block|{}
name|T
name|DoIt
argument_list|(
argument|T ti
argument_list|)
block|;
name|private
operator|:
name|T
name|t
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|T
name|FOO
operator|<
name|T
operator|>
operator|::
name|DoIt
argument_list|(
argument|T ti
argument_list|)
block|{
comment|// HEADER: [[@LINE]]|  2|template
for|for
control|(
name|T
name|I
init|=
literal|0
init|;
name|I
operator|<
name|ti
condition|;
name|I
operator|++
control|)
block|{
comment|// HEADER: [[@LINE]]| 22|  for (T
name|t
operator|+=
name|I
expr_stmt|;
comment|// HEADER: [[@LINE]]| 20|    t += I;
if|if
condition|(
name|I
operator|>
name|ti
operator|/
literal|2
condition|)
comment|// HEADER: [[@LINE]]| 20|    if (I> ti
name|t
operator|-=
literal|1
expr_stmt|;
comment|// HEADER: [[@LINE]]|  8|      t -= 1;
block|}
end_expr_stmt

begin_comment
comment|// HEADER: [[@LINE]]| 10|  }
end_comment

begin_comment
comment|// HEADER: [[@LINE]]|  1|
end_comment

begin_return
return|return
name|t
return|;
end_return

begin_comment
comment|// HEADER: [[@LINE]]|  1|  return t;
end_comment

unit|}
end_unit

