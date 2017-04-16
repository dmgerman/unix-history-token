begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -f %t
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=debug.DumpDominators %s> %t 2>&1
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t %s
end_comment

begin_comment
comment|// Test the DominatorsTree implementation with various control flows
end_comment

begin_function
name|int
name|test1
parameter_list|()
block|{
name|int
name|x
init|=
literal|6
decl_stmt|;
name|int
name|y
init|=
name|x
operator|/
literal|2
decl_stmt|;
name|int
name|z
decl_stmt|;
while|while
condition|(
name|y
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|y
operator|<
name|x
condition|)
block|{
name|x
operator|=
name|x
operator|/
name|y
expr_stmt|;
name|y
operator|=
name|y
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
name|z
operator|=
name|x
operator|-
name|y
expr_stmt|;
block|}
name|x
operator|=
name|x
operator|-
literal|1
expr_stmt|;
name|x
operator|=
name|x
operator|-
literal|1
expr_stmt|;
block|}
name|z
operator|=
name|x
operator|+
name|y
expr_stmt|;
name|z
operator|=
literal|3
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: Immediate dominance tree (Node#,IDom#):
end_comment

begin_comment
comment|// CHECK: (0,1)
end_comment

begin_comment
comment|// CHECK: (1,7)
end_comment

begin_comment
comment|// CHECK: (2,3)
end_comment

begin_comment
comment|// CHECK: (3,6)
end_comment

begin_comment
comment|// CHECK: (4,6)
end_comment

begin_comment
comment|// CHECK: (5,6)
end_comment

begin_comment
comment|// CHECK: (6,7)
end_comment

begin_comment
comment|// CHECK: (7,8)
end_comment

begin_comment
comment|// CHECK: (8,9)
end_comment

begin_comment
comment|// CHECK: (9,9)
end_comment

begin_function
name|int
name|test2
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
name|x
operator|=
literal|10
expr_stmt|;
name|y
operator|=
literal|100
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
name|y
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
name|x
operator|<=
literal|0
condition|)
block|{
name|x
operator|++
expr_stmt|;
name|y
operator|++
expr_stmt|;
block|}
block|}
name|z
operator|=
name|y
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: Immediate dominance tree (Node#,IDom#):
end_comment

begin_comment
comment|// CHECK: (0,1)
end_comment

begin_comment
comment|// CHECK: (1,6)
end_comment

begin_comment
comment|// CHECK: (2,3)
end_comment

begin_comment
comment|// CHECK: (3,4)
end_comment

begin_comment
comment|// CHECK: (4,6)
end_comment

begin_comment
comment|// CHECK: (5,6)
end_comment

begin_comment
comment|// CHECK: (6,7)
end_comment

begin_comment
comment|// CHECK: (7,7)
end_comment

begin_function
name|int
name|test3
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|;
name|x
operator|=
name|y
operator|=
name|z
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|x
operator|>
literal|0
condition|)
block|{
while|while
condition|(
name|x
operator|>=
literal|0
condition|)
block|{
while|while
condition|(
name|y
operator|>=
name|x
condition|)
block|{
name|x
operator|=
name|x
operator|-
literal|1
expr_stmt|;
name|y
operator|=
name|y
operator|/
literal|2
expr_stmt|;
block|}
block|}
block|}
name|z
operator|=
name|y
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: Immediate dominance tree (Node#,IDom#):
end_comment

begin_comment
comment|// CHECK: (0,1)
end_comment

begin_comment
comment|// CHECK: (1,7)
end_comment

begin_comment
comment|// CHECK: (2,5)
end_comment

begin_comment
comment|// CHECK: (3,4)
end_comment

begin_comment
comment|// CHECK: (4,5)
end_comment

begin_comment
comment|// CHECK: (5,6)
end_comment

begin_comment
comment|// CHECK: (6,7)
end_comment

begin_comment
comment|// CHECK: (7,8)
end_comment

begin_comment
comment|// CHECK: (8,8)
end_comment

begin_function
name|int
name|test4
parameter_list|()
block|{
name|int
name|y
init|=
literal|3
decl_stmt|;
while|while
condition|(
name|y
operator|>
literal|0
condition|)
block|{
if|if
condition|(
name|y
operator|<
literal|3
condition|)
block|{
while|while
condition|(
name|y
operator|>
literal|0
condition|)
name|y
operator|++
expr_stmt|;
block|}
else|else
block|{
while|while
condition|(
name|y
operator|<
literal|10
condition|)
name|y
operator|++
expr_stmt|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: Immediate dominance tree (Node#,IDom#):
end_comment

begin_comment
comment|// CHECK: (0,1)
end_comment

begin_comment
comment|// CHECK: (1,10)
end_comment

begin_comment
comment|// CHECK: (2,9)
end_comment

begin_comment
comment|// CHECK: (3,4)
end_comment

begin_comment
comment|// CHECK: (4,5)
end_comment

begin_comment
comment|// CHECK: (5,9)
end_comment

begin_comment
comment|// CHECK: (6,7)
end_comment

begin_comment
comment|// CHECK: (7,8)
end_comment

begin_comment
comment|// CHECK: (8,9)
end_comment

begin_comment
comment|// CHECK: (9,10)
end_comment

begin_comment
comment|// CHECK: (10,11)
end_comment

begin_comment
comment|// CHECK: (11,12)
end_comment

begin_comment
comment|// CHECK: (12,12)
end_comment

begin_function
name|int
name|test5
parameter_list|()
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|z
decl_stmt|,
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|x
operator|=
literal|1
expr_stmt|;
name|y
operator|=
literal|2
expr_stmt|;
name|z
operator|=
literal|3
expr_stmt|;
name|a
operator|=
literal|4
expr_stmt|;
name|b
operator|=
literal|5
expr_stmt|;
name|c
operator|=
literal|6
expr_stmt|;
if|if
condition|(
name|x
operator|<
literal|10
condition|)
block|{
if|if
condition|(
name|y
operator|<
literal|10
condition|)
block|{
if|if
condition|(
name|z
operator|<
literal|10
condition|)
block|{
name|x
operator|=
literal|4
expr_stmt|;
block|}
else|else
block|{
name|x
operator|=
literal|5
expr_stmt|;
block|}
name|a
operator|=
literal|10
expr_stmt|;
block|}
else|else
block|{
name|x
operator|=
literal|6
expr_stmt|;
block|}
name|b
operator|=
literal|10
expr_stmt|;
block|}
else|else
block|{
name|x
operator|=
literal|7
expr_stmt|;
block|}
name|c
operator|=
literal|11
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: Immediate dominance tree (Node#,IDom#):
end_comment

begin_comment
comment|// CHECK: (0,1)
end_comment

begin_comment
comment|// CHECK: (1,10)
end_comment

begin_comment
comment|// CHECK: (2,10)
end_comment

begin_comment
comment|// CHECK: (3,9)
end_comment

begin_comment
comment|// CHECK: (4,9)
end_comment

begin_comment
comment|// CHECK: (5,8)
end_comment

begin_comment
comment|// CHECK: (6,8)
end_comment

begin_comment
comment|// CHECK: (7,8)
end_comment

begin_comment
comment|// CHECK: (8,9)
end_comment

begin_comment
comment|// CHECK: (9,10)
end_comment

begin_comment
comment|// CHECK: (10,11)
end_comment

begin_comment
comment|// CHECK: (11,11)
end_comment

end_unit

