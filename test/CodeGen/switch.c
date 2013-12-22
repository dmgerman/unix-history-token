begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -O3 %s -emit-llvm -o - | FileCheck %s
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
comment|// CHECK-LABEL: define i32 @foo4t()
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
comment|// CHECK-LABEL: define void @foo5()
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
comment|// CHECK-LABEL: define void @foo6()
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
comment|// CHECK-LABEL: define void @foo7()
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

begin_comment
comment|// CHECK-LABEL: define i32 @f8(
end_comment

begin_comment
comment|// CHECK: ret i32 3
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f8
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
return|return
literal|3
return|;
case|case
literal|0xFFFFFFFF
operator|...
literal|1
case|:
comment|// This range should be empty because x is unsigned.
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|// Ensure that default after a case range is not ignored.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f9()
end_comment

begin_comment
comment|// CHECK: ret i32 10
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
specifier|static
name|int
name|f9_0
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|10
operator|...
literal|0xFFFFFFFF
case|:
return|return
literal|0
return|;
default|default:
return|return
literal|10
return|;
block|}
block|}
end_function

begin_function
name|int
name|f9
parameter_list|()
block|{
return|return
name|f9_0
argument_list|(
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Ensure that this doesn't compile to infinite loop in g() due to
end_comment

begin_comment
comment|// miscompilation of fallthrough from default to a (tested) case
end_comment

begin_comment
comment|// range.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f10()
end_comment

begin_comment
comment|// CHECK: ret i32 10
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
specifier|static
name|int
name|f10_0
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
name|x
operator|+=
literal|1
expr_stmt|;
case|case
literal|10
operator|...
literal|0xFFFFFFFF
case|:
return|return
literal|0
return|;
block|}
block|}
end_function

begin_function
name|int
name|f10
parameter_list|()
block|{
name|f10_0
argument_list|(
literal|1
argument_list|)
expr_stmt|;
return|return
literal|10
return|;
block|}
end_function

begin_comment
comment|// This generated incorrect code because of poor switch chaining.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f11(
end_comment

begin_comment
comment|// CHECK: ret i32 3
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f11
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
return|return
literal|3
return|;
case|case
literal|10
operator|...
literal|0xFFFFFFFF
case|:
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|// This just asserted because of the way case ranges were calculated.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f12(
end_comment

begin_comment
comment|// CHECK: ret i32 3
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f12
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
default|default:
return|return
literal|3
return|;
case|case
literal|10
operator|...
operator|-
literal|1
case|:
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|// Make sure return is not constant (if empty range is skipped or miscompiled)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define i32 @f13(
end_comment

begin_comment
comment|// CHECK: ret i32 %
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_function
name|int
name|f13
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|2
case|:
comment|// fallthrough empty range
case|case
literal|10
operator|...
literal|9
case|:
return|return
literal|10
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|// Don't delete a basic block that we want to introduce later references to.
end_comment

begin_comment
comment|// This isn't really specific to switches, but it's easy to show with them.
end_comment

begin_comment
comment|// rdar://problem/8837067
end_comment

begin_function
name|int
name|f14
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
comment|// case range so that the case block has no predecessors
case|case
literal|0
operator|...
literal|15
case|:
comment|// any expression which doesn't introduce a new block
operator|(
name|void
operator|)
literal|0
expr_stmt|;
comment|// kaboom
default|default:
return|return
name|x
return|;
block|}
block|}
end_function

end_unit

