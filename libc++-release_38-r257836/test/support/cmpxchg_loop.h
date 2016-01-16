begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<atomic>
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|A
operator|,
name|class
name|T
operator|>
name|bool
name|cmpxchg_weak_loop
argument_list|(
argument|A& atomic
argument_list|,
argument|T& expected
argument_list|,
argument|T desired
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|atomic
operator|.
name|compare_exchange_weak
argument_list|(
name|expected
argument_list|,
name|desired
argument_list|)
operator|==
name|true
condition|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    return
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|A
operator|,
name|class
name|T
operator|>
name|bool
name|cmpxchg_weak_loop
argument_list|(
argument|A& atomic
argument_list|,
argument|T& expected
argument_list|,
argument|T desired
argument_list|,
argument|std::memory_order success
argument_list|,
argument|std::memory_order failure
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|atomic
operator|.
name|compare_exchange_weak
argument_list|(
name|expected
argument_list|,
name|desired
argument_list|,
name|success
argument_list|,
name|failure
argument_list|)
operator|==
name|true
condition|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    return
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|A
operator|,
name|class
name|T
operator|>
name|bool
name|c_cmpxchg_weak_loop
argument_list|(
argument|A* atomic
argument_list|,
argument|T* expected
argument_list|,
argument|T desired
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|std
operator|::
name|atomic_compare_exchange_weak
argument_list|(
name|atomic
argument_list|,
name|expected
argument_list|,
name|desired
argument_list|)
operator|==
name|true
condition|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    return
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|A
operator|,
name|class
name|T
operator|>
name|bool
name|c_cmpxchg_weak_loop
argument_list|(
argument|A* atomic
argument_list|,
argument|T* expected
argument_list|,
argument|T desired
argument_list|,
argument|std::memory_order success
argument_list|,
argument|std::memory_order failure
argument_list|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|std
operator|::
name|atomic_compare_exchange_weak_explicit
argument_list|(
name|atomic
argument_list|,
name|expected
argument_list|,
name|desired
argument_list|,
name|success
argument_list|,
name|failure
argument_list|)
operator|==
name|true
condition|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    return
name|false
expr_stmt|;
end_expr_stmt

unit|}
end_unit

