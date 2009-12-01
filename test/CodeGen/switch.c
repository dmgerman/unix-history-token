begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -O3 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
operator|-
literal|1
case|:
name|j
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|j
operator|=
literal|2
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|j
operator|=
literal|3
expr_stmt|;
break|break;
default|default:
name|j
operator|=
literal|42
expr_stmt|;
break|break;
block|}
name|j
operator|=
name|j
operator|+
literal|1
expr_stmt|;
return|return
name|j
return|;
block|}
end_function

begin_function
name|int
name|foo2
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|1
case|:
name|j
operator|=
literal|2
expr_stmt|;
break|break;
case|case
literal|2
operator|...
literal|10
case|:
name|j
operator|=
literal|3
expr_stmt|;
break|break;
default|default:
name|j
operator|=
literal|42
expr_stmt|;
break|break;
block|}
name|j
operator|=
name|j
operator|+
literal|1
expr_stmt|;
return|return
name|j
return|;
block|}
end_function

begin_function
name|int
name|foo3
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
default|default:
name|j
operator|=
literal|42
expr_stmt|;
break|break;
case|case
literal|111
case|:
name|j
operator|=
literal|111
expr_stmt|;
break|break;
case|case
literal|0
operator|...
literal|100
case|:
name|j
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|222
case|:
name|j
operator|=
literal|222
expr_stmt|;
break|break;
block|}
return|return
name|j
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|foo4
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|int
name|j
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|111
case|:
name|j
operator|=
literal|111
expr_stmt|;
break|break;
case|case
literal|0
operator|...
literal|100
case|:
name|j
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|222
case|:
name|j
operator|=
literal|222
expr_stmt|;
break|break;
default|default:
name|j
operator|=
literal|42
expr_stmt|;
break|break;
case|case
literal|501
operator|...
literal|600
case|:
name|j
operator|=
literal|5
expr_stmt|;
break|break;
block|}
return|return
name|j
return|;
block|}
end_function

begin_comment
comment|// CHECK: define i32 @foo4t()
end_comment

begin_comment
comment|// CHECK: ret i32 376
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|foo4t
parameter_list|()
block|{
comment|// 111 + 1 + 222 + 42 = 376
return|return
name|foo4
argument_list|(
literal|111
argument_list|)
operator|+
name|foo4
argument_list|(
literal|99
argument_list|)
operator|+
name|foo4
argument_list|(
literal|222
argument_list|)
operator|+
name|foo4
argument_list|(
literal|601
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: define void @foo5()
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|foo5
parameter_list|()
block|{
switch|switch
condition|(
literal|0
condition|)
block|{
default|default:
if|if
condition|(
literal|0
condition|)
block|{          }
block|}
block|}
end_function

begin_comment
comment|// CHECK: define void @foo6()
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|foo6
parameter_list|()
block|{
switch|switch
condition|(
literal|0
condition|)
block|{     }
block|}
end_function

begin_comment
comment|// CHECK: define void @foo7()
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|void
name|foo7
parameter_list|()
block|{
switch|switch
condition|(
literal|0
condition|)
block|{
name|foo7
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

