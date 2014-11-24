begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wno-gcc-compat -emit-llvm -o - %s | FileCheck %s
end_comment

begin_function
name|void
name|pr8880_cg_1
parameter_list|(
name|int
modifier|*
name|iptr
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @pr8880_cg_1(
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|// CHECK: br label %[[OUTER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
comment|// CHECK: [[OUTER_COND]]
comment|// CHECK: label %[[OUTER_BODY:[0-9A-Za-z$._]+]], label %[[OUTER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_BODY]]
comment|// CHECK: br label %[[INNER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|j
operator|=
literal|3
init|;
name|j
operator|<
literal|22
condition|;
operator|(
name|void
operator|)
operator|(
block|{
operator|++
name|j
block|;
break|break;
name|j
expr|;
control|}
block|)
end_function

begin_block
unit|)
block|{
comment|// CHECK: [[INNER_COND]]
comment|// CHECK: label %[[INNER_BODY:[0-9A-Za-z$._]+]], label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_BODY]]
operator|*
name|iptr
operator|=
literal|7
expr_stmt|;
comment|// CHECK: store i32 7,
comment|// CHECK: br label %[[INNER_INC:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_INC]]
comment|// break in 3rd expression of inner loop causes branch to end of inner loop
comment|// CHECK: br label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_END]]
block|}
end_block

begin_comment
comment|// CHECK: br label %[[OUTER_INC:[0-9A-Za-z$._]+]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_INC]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_COND]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_END]]
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_macro
unit|}  void
name|pr8880_cg_2
argument_list|(
argument|int *iptr
argument_list|)
end_macro

begin_block
block|{
comment|// CHECK-LABEL: define void @pr8880_cg_2(
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|// CHECK: br label %[[OUTER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
comment|// CHECK: [[OUTER_COND]]
comment|// CHECK: label %[[OUTER_BODY:[0-9A-Za-z$._]+]], label %[[OUTER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_BODY]]
comment|// CHECK: br label %[[INNER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|j
operator|=
literal|3
init|;
name|j
operator|<
literal|22
condition|;
operator|(
name|void
operator|)
operator|(
block|{
operator|++
name|j
block|;
continue|continue;
name|j
expr|;
control|}
block|)
end_block

begin_block
unit|)
block|{
comment|// CHECK: [[INNER_COND]]
comment|// CHECK: label %[[INNER_BODY:[0-9A-Za-z$._]+]], label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_BODY]]
operator|*
name|iptr
operator|=
literal|7
expr_stmt|;
comment|// CHECK: store i32 7,
comment|// CHECK: br label %[[INNER_INC:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_INC]]
comment|// continue in 3rd expression of inner loop causes branch to inc of inner loop
comment|// CHECK: br label %[[INNER_INC]]
comment|// CHECK: [[INNER_END]]
block|}
end_block

begin_comment
comment|// CHECK: br label %[[OUTER_INC:[0-9A-Za-z$._]+]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_INC]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_COND]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_END]]
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_macro
unit|}  void
name|pr8880_cg_3
argument_list|(
argument|int *iptr
argument_list|)
end_macro

begin_block
block|{
comment|// CHECK-LABEL: define void @pr8880_cg_3(
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|// CHECK: br label %[[OUTER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
comment|// CHECK: [[OUTER_COND]]
comment|// CHECK: label %[[OUTER_BODY:[0-9A-Za-z$._]+]], label %[[OUTER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_BODY]]
comment|// CHECK: br label %[[INNER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|j
operator|=
literal|3
init|;
operator|(
block|{
break|break;
name|j
expr|;
control|}
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|j
operator|++
end_expr_stmt

begin_block
unit|)
block|{
comment|// break in 2nd expression of inner loop causes branch to end of inner loop
comment|// CHECK: [[INNER_COND]]
comment|// CHECK: br label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: label %[[INNER_BODY:[0-9A-Za-z$._]+]], label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_BODY]]
operator|*
name|iptr
operator|=
literal|7
expr_stmt|;
comment|// CHECK: store i32 7,
comment|// CHECK: br label %[[INNER_INC:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_INC]]
comment|// CHECK: br label %[[INNER_COND]]
block|}
end_block

begin_comment
comment|// CHECK: [[INNER_END]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_INC:[0-9A-Za-z$._]+]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_INC]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_COND]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_END]]
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_macro
unit|}  void
name|pr8880_cg_4
argument_list|(
argument|int *iptr
argument_list|)
end_macro

begin_block
block|{
comment|// CHECK-LABEL: define void @pr8880_cg_4(
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|// CHECK: br label %[[OUTER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|!=
literal|10
condition|;
name|i
operator|++
control|)
comment|// CHECK: [[OUTER_COND]]
comment|// CHECK: label %[[OUTER_BODY:[0-9A-Za-z$._]+]], label %[[OUTER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_BODY]]
comment|// CHECK: br label %[[INNER_COND:[0-9A-Za-z$._]+]]
for|for
control|(
name|j
operator|=
literal|3
init|;
operator|(
block|{
continue|continue;
name|j
expr|;
control|}
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|j
operator|++
end_expr_stmt

begin_block
unit|)
block|{
comment|// continue in 2nd expression of inner loop causes branch to inc of inner loop
comment|// CHECK: [[INNER_COND]]
comment|// CHECK: br label %[[INNER_INC:[0-9A-Za-z$._]+]]
comment|// CHECK: label %[[INNER_BODY:[0-9A-Za-z$._]+]], label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_BODY]]
operator|*
name|iptr
operator|=
literal|7
expr_stmt|;
comment|// CHECK: store i32 7,
comment|// CHECK: br label %[[INNER_INC]]
comment|// CHECK: [[INNER_INC]]
comment|// CHECK: br label %[[INNER_COND]]
block|}
end_block

begin_comment
comment|// CHECK: [[INNER_END]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_INC:[0-9A-Za-z$._]+]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_INC]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_COND]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_END]]
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_macro
unit|}  void
name|pr8880_cg_5
argument_list|(
argument|int x
argument_list|,
argument|int *iptr
argument_list|)
end_macro

begin_block
block|{
comment|// CHECK-LABEL: define void @pr8880_cg_5(
name|int
name|y
init|=
literal|5
decl_stmt|;
comment|// CHECK: br label %[[OUTER_COND:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_COND]]
while|while
condition|(
operator|--
name|x
condition|)
block|{
comment|// CHECK: label %[[OUTER_BODY:[0-9A-Za-z$._]+]], label %[[OUTER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_BODY]]
comment|// CHECK: br label %[[INNER_COND:[0-9A-Za-z$._]+]]
while|while
condition|(
operator|(
block|{
break|break;
operator|--
name|y
expr_stmt|;
block|}
block|)
block|)
end_block

begin_block
block|{
comment|// CHECK: [[INNER_COND]]
comment|// CHECK: br label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: label %[[INNER_BODY:[0-9A-Za-z$._]+]], label %[[INNER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_BODY]]
operator|*
name|iptr
operator|=
literal|7
expr_stmt|;
comment|// CHECK: store i32 7,
block|}
end_block

begin_comment
comment|// CHECK: br label %[[INNER_COND]]
end_comment

begin_comment
unit|}
comment|// CHECK: [[INNER_END]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_COND]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_END]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
unit|}
name|void
name|pr8880_cg_6
parameter_list|(
name|int
name|x
parameter_list|,
name|int
modifier|*
name|iptr
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @pr8880_cg_6(
name|int
name|y
init|=
literal|5
decl_stmt|;
comment|// CHECK: br label %[[OUTER_COND:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_COND]]
while|while
condition|(
operator|--
name|x
condition|)
block|{
comment|// CHECK: label %[[OUTER_BODY:[0-9A-Za-z$._]+]], label %[[OUTER_END:[0-9A-Za-z$._]+]]
comment|// CHECK: [[OUTER_BODY]]
comment|// CHECK: br label %[[INNER_BODY:[0-9A-Za-z$._]+]]
comment|// CHECK: [[INNER_BODY]]
do|do
block|{
comment|// CHECK: store i32 7,
operator|*
name|iptr
operator|=
literal|7
expr_stmt|;
comment|// CHECK: br label %[[INNER_COND:[0-9A-Za-z$._]+]]
block|}
do|while
condition|(
operator|(
block|{
break|break;
operator|--
name|y
expr_stmt|;
block|}
block|)
block|)
function|;
end_function

begin_comment
comment|// CHECK: [[INNER_COND]]
end_comment

begin_comment
comment|// CHECK: br label %[[INNER_END:[0-9A-Za-z$._]+]]
end_comment

begin_comment
comment|// CHECK: label %[[INNER_BODY:[0-9A-Za-z$._]+]], label %[[INNER_END]]
end_comment

begin_comment
unit|}
comment|// CHECK: [[INNER_END]]
end_comment

begin_comment
comment|// CHECK: br label %[[OUTER_COND]]
end_comment

begin_comment
comment|// CHECK: [[OUTER_END]]
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

unit|}
end_unit

