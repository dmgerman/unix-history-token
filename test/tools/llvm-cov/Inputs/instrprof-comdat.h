begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// HEADER:  2| [[@LINE]]|template
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
comment|// HEADER: 22| [[@LINE]]|  for (T
name|t
operator|+=
name|I
expr_stmt|;
comment|// HEADER: 20| [[@LINE]]|    t += I;
if|if
condition|(
name|I
operator|>
name|ti
operator|/
literal|2
condition|)
comment|// HEADER: 20| [[@LINE]]|    if (I> ti
name|t
operator|-=
literal|1
expr_stmt|;
comment|// HEADER:  8| [[@LINE]]|      t -= 1;
block|}
end_expr_stmt

begin_comment
comment|// HEADER: 20| [[@LINE]]|  }
end_comment

begin_comment
comment|// HEADER:  2| [[@LINE]]|
end_comment

begin_return
return|return
name|t
return|;
end_return

begin_comment
comment|// HEADER:  2| [[@LINE]]|  return t;
end_comment

begin_comment
unit|}
comment|// To generate the binaries which correspond to this file, you must first
end_comment

begin_comment
comment|// compile a program with two calls to Foo<int>::DoIt(10) for each desired
end_comment

begin_comment
comment|// architecture. Collect a raw profile from any one of these binaries, index
end_comment

begin_comment
comment|// it, and check it in along with the executables.
end_comment

end_unit

