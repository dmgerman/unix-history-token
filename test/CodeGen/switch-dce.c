begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// PR9322 and rdar://6970405
end_comment

begin_comment
comment|// CHECK: @test1
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32 {{.*}}, 1
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|dead
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test1
parameter_list|()
block|{
switch|switch
condition|(
literal|1
condition|)
case|case
literal|1
case|:
operator|++
name|i
expr_stmt|;
switch|switch
condition|(
literal|0
condition|)
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test2
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32 {{.*}}, 2
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
switch|switch
condition|(
literal|4
condition|)
block|{
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|i
operator|+=
literal|2
expr_stmt|;
comment|// Fall off the end of the switch.
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test3
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32 {{.*}}, 2
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
switch|switch
condition|(
literal|4
condition|)
block|{
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
break|break;
case|case
literal|4
case|:
block|{
name|i
operator|+=
literal|2
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test4
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32 {{.*}}, 2
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
switch|switch
condition|(
literal|4
condition|)
block|{
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
break|break;
default|default:
block|{
name|i
operator|+=
literal|2
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_comment
comment|// This shouldn't crash codegen, but we don't have to optimize out the switch
end_comment

begin_comment
comment|// in this case.
end_comment

begin_function
name|void
name|test5
parameter_list|()
block|{
switch|switch
condition|(
literal|1
condition|)
block|{
name|int
name|x
decl_stmt|;
comment|// eliding var decl?
case|case
literal|1
case|:
name|x
operator|=
literal|4
expr_stmt|;
name|i
operator|=
name|x
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test6
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test6
parameter_list|()
block|{
comment|// Neither case is reachable.
switch|switch
condition|(
literal|40
condition|)
block|{
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
break|break;
case|case
literal|4
case|:
block|{
name|dead
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test7
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test7
parameter_list|()
block|{
switch|switch
condition|(
literal|4
condition|)
block|{
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
break|break;
block|{
case|case
literal|4
case|:
comment|// crazy brace scenario
operator|++
name|i
expr_stmt|;
block|}
break|break;
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test8
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test8
parameter_list|()
block|{
switch|switch
condition|(
literal|4
condition|)
block|{
case|case
literal|1
case|:
name|dead
argument_list|()
expr_stmt|;
break|break;
case|case
literal|4
case|:
operator|++
name|i
expr_stmt|;
comment|// Fall off the end of the switch.
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test9
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: add nsw i32
end_comment

begin_comment
comment|// CHECK: add nsw i32
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK-NOT: @dead
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test9
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|5
case|:
name|dead
argument_list|()
expr_stmt|;
case|case
literal|1
case|:
operator|++
name|i
expr_stmt|;
comment|// Fall through is fine.
case|case
literal|4
case|:
operator|++
name|i
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test10
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

begin_function
name|int
name|test10
parameter_list|(
name|void
parameter_list|)
block|{
switch|switch
condition|(
literal|8
condition|)
block|{
case|case
literal|8
case|:
break|break;
case|case
literal|4
case|:
break|break;
default|default:
name|dead
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test11
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test11
parameter_list|()
block|{
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|1
case|:
break|break;
case|case
literal|42
case|:
empty_stmt|;
name|int
name|x
decl_stmt|;
comment|// eliding var decl?
name|x
operator|=
literal|4
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|// CHECK: @test12
end_comment

begin_comment
comment|// CHECK-NOT: switch
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|void
name|test12
parameter_list|()
block|{
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|2
case|:
block|{
name|int
name|a
decl_stmt|;
comment|// Ok to skip this vardecl.
name|a
operator|=
literal|42
expr_stmt|;
block|}
case|case
literal|1
case|:
break|break;
case|case
literal|42
case|:
empty_stmt|;
name|int
name|x
decl_stmt|;
comment|// eliding var decl?
name|x
operator|=
literal|4
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|// Verify that case 42 only calls test14 once.
end_comment

begin_comment
comment|// CHECK: @test13
end_comment

begin_comment
comment|// CHECK: call void @test13(i32 97)
end_comment

begin_comment
comment|// CHECK-NEXT: br label %[[EPILOG2:[0-9.a-z]+]]
end_comment

begin_comment
comment|// CHECK: [[EPILOG2]]
end_comment

begin_comment
comment|// CHECK-NEXT: br label [[EPILOG:%[0-9.a-z]+]]
end_comment

begin_comment
comment|// CHECK: call void @test13(i32 42)
end_comment

begin_comment
comment|// CHECK-NEXT: br label [[EPILOG]]
end_comment

begin_function
name|void
name|test13
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
case|case
literal|42
case|:
name|test13
argument_list|(
literal|97
argument_list|)
expr_stmt|;
comment|// fallthrough
case|case
literal|11
case|:
break|break;
default|default:
name|test13
argument_list|(
literal|42
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

end_unit

