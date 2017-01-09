begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O2 %s | FileCheck %s -check-prefixes=CHECK,O2
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O2 -Xclang -disable-lifetime-markers %s \
end_comment

begin_comment
comment|// RUN:       | FileCheck %s -check-prefixes=CHECK,O0
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm -o - -O0 %s | FileCheck %s -check-prefixes=CHECK,O0
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
comment|// O2: @llvm.lifetime.start(i64 1
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
comment|// O2: @llvm.lifetime.start(i64 5
comment|// O2: @llvm.lifetime.end(i64 5
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
comment|// O2-NOT: @llvm.lifetime.end(i64 1
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
comment|// O2-NOT: @llvm.lifetime.start(i64 1
comment|// O2-NOT: @llvm.lifetime.end(i64 1
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
comment|// O2: @llvm.lifetime.start(i64 1
comment|// O2: @llvm.lifetime.end(i64 1
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
comment|// O2: @llvm.lifetime.start(i64 5
comment|// O2: @llvm.lifetime.end(i64 5
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
comment|// O2-NOT: @llvm.lifetime.start(i64 1
comment|// O2-NOT: @llvm.lifetime.end(i64 1
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

end_unit

