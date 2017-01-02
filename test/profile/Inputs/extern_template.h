begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Test
block|{
name|Test
argument_list|()
operator|:
name|M
argument_list|(
literal|10
argument_list|)
block|{}
name|void
name|doIt
argument_list|(
argument|int N
argument_list|)
block|{
comment|// CHECK: [[@LINE]]| 2|  void doIt
if|if
condition|(
name|N
operator|>
literal|10
condition|)
block|{
comment|// CHECK: [[@LINE]]| 2|    if (N> 10) {
name|M
operator|+=
literal|2
expr_stmt|;
comment|// CHECK: [[@LINE]]| 1|      M += 2;
block|}
else|else
comment|// CHECK: [[@LINE]]| 1|    } else
name|M
operator|-=
literal|2
expr_stmt|;
comment|// CHECK: [[@LINE]]| 1|      M -= 2;
block|}
name|T
name|M
expr_stmt|;
end_expr_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|USE
end_ifdef

begin_extern
extern|extern template struct Test<int>;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEF
end_ifdef

begin_macro
name|template
end_macro

begin_expr_stmt
unit|struct
name|Test
operator|<
name|int
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

