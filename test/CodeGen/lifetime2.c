begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -S -emit-llvm -o - -O2 -disable-llvm-passes %s | FileCheck %s -check-prefixes=CHECK,O2
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -emit-llvm -o - -O2 -disable-lifetime-markers %s \
end_comment

begin_comment
comment|// RUN:       | FileCheck %s -check-prefixes=CHECK,O0
end_comment

begin_comment
comment|// RUN: %clang_cc1 -S -emit-llvm -o - -O0 %s | FileCheck %s -check-prefixes=CHECK,O0
end_comment

begin_function_decl
specifier|extern
name|int
name|bar
parameter_list|(
name|char
modifier|*
name|A
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK-LABEL: @foo
end_comment

begin_comment
comment|// O0-NOT: @llvm.lifetime.start
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|n
parameter_list|)
block|{
if|if
condition|(
name|n
condition|)
block|{
comment|// O2: @llvm.lifetime.start
name|char
name|A
index|[
literal|100
index|]
decl_stmt|;
return|return
name|bar
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
block|}
else|else
block|{
comment|// O2: @llvm.lifetime.start
name|char
name|A
index|[
literal|100
index|]
decl_stmt|;
return|return
name|bar
argument_list|(
name|A
argument_list|,
literal|2
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @no_goto_bypass
end_comment

begin_function
name|void
name|no_goto_bypass
parameter_list|()
block|{
comment|// O2: @llvm.lifetime.start.p0i8(i64 1
name|char
name|x
decl_stmt|;
name|l1
label|:
name|bar
argument_list|(
operator|&
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|char
name|y
index|[
literal|5
index|]
decl_stmt|;
name|bar
argument_list|(
name|y
argument_list|,
literal|5
argument_list|)
expr_stmt|;
goto|goto
name|l1
goto|;
comment|// Infinite loop
comment|// O2-NOT: @llvm.lifetime.end.p0i8(
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @goto_bypass
end_comment

begin_function
name|void
name|goto_bypass
parameter_list|()
block|{
block|{
comment|// O2-NOT: @llvm.lifetime.start.p0i8(i64 1
comment|// O2-NOT: @llvm.lifetime.end.p0i8(i64 1
name|char
name|x
decl_stmt|;
name|l1
label|:
name|bar
argument_list|(
operator|&
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
goto|goto
name|l1
goto|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @no_switch_bypass
end_comment

begin_function
name|void
name|no_switch_bypass
parameter_list|(
name|int
name|n
parameter_list|)
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|1
case|:
block|{
comment|// O2: @llvm.lifetime.start.p0i8(i64 1
comment|// O2: @llvm.lifetime.end.p0i8(i64 1
name|char
name|x
decl_stmt|;
name|bar
argument_list|(
operator|&
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
literal|2
case|:
name|n
operator|=
name|n
expr_stmt|;
comment|// O2: @llvm.lifetime.start.p0i8(i64 5
comment|// O2: @llvm.lifetime.end.p0i8(i64 5
name|char
name|y
index|[
literal|5
index|]
decl_stmt|;
name|bar
argument_list|(
name|y
argument_list|,
literal|5
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @switch_bypass
end_comment

begin_function
name|void
name|switch_bypass
parameter_list|(
name|int
name|n
parameter_list|)
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
literal|1
case|:
name|n
operator|=
name|n
expr_stmt|;
comment|// O2-NOT: @llvm.lifetime.start.p0i8(i64 1
comment|// O2-NOT: @llvm.lifetime.end.p0i8(i64 1
name|char
name|x
decl_stmt|;
name|bar
argument_list|(
operator|&
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|bar
argument_list|(
operator|&
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @indirect_jump
end_comment

begin_function
name|void
name|indirect_jump
parameter_list|(
name|int
name|n
parameter_list|)
block|{
name|char
name|x
decl_stmt|;
comment|// O2-NOT: @llvm.lifetime
name|void
modifier|*
name|T
index|[]
init|=
block|{
operator|&&
name|L
block|}
decl_stmt|;
goto|goto *
name|T
index|[
name|n
index|]
goto|;
name|L
label|:
name|bar
argument_list|(
operator|&
name|x
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// O2-LABEL: @jump_backward_over_declaration(
end_comment

begin_comment
comment|// O2: %[[p:.*]] = alloca i32*
end_comment

begin_comment
comment|// O2: %[[v0:.*]] = bitcast i32** %[[p]] to i8*
end_comment

begin_comment
comment|// O2: call void @llvm.lifetime.start.p0i8(i64 {{.*}}, i8* %[[v0]])
end_comment

begin_comment
comment|// O2-NOT: call void @llvm.lifetime.start.p0i8(
end_comment

begin_function_decl
specifier|extern
name|void
name|foo2
parameter_list|(
name|int
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|jump_backward_over_declaration
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
name|label1
label|:
if|if
condition|(
name|p
condition|)
block|{
name|foo2
argument_list|(
operator|*
name|p
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|int
name|i
init|=
literal|999
decl_stmt|;
if|if
condition|(
name|a
operator|!=
literal|2
condition|)
block|{
name|p
operator|=
operator|&
name|i
expr_stmt|;
goto|goto
name|label1
goto|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

end_unit

