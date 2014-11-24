begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that instrumentation based profiling sets function attributes correctly.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-attributes.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang %s -o - -mllvm -disable-llvm-optzns -emit-llvm -S -fprofile-instr-use=%t.profdata | FileCheck %s
end_comment

begin_function_decl
specifier|extern
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: hot_100_percent(i32{{.*}}%i) [[HOT:#[0-9]+]]
end_comment

begin_function
name|void
name|hot_100_percent
parameter_list|(
name|int
name|i
parameter_list|)
block|{
while|while
condition|(
name|i
operator|>
literal|0
condition|)
name|i
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: hot_40_percent(i32{{.*}}%i) [[HOT]]
end_comment

begin_function
name|void
name|hot_40_percent
parameter_list|(
name|int
name|i
parameter_list|)
block|{
while|while
condition|(
name|i
operator|>
literal|0
condition|)
name|i
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: normal_func(i32{{.*}}%i) [[NORMAL:#[0-9]+]]
end_comment

begin_function
name|void
name|normal_func
parameter_list|(
name|int
name|i
parameter_list|)
block|{
while|while
condition|(
name|i
operator|>
literal|0
condition|)
name|i
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: cold_func(i32{{.*}}%i) [[COLD:#[0-9]+]]
end_comment

begin_function
name|void
name|cold_func
parameter_list|(
name|int
name|i
parameter_list|)
block|{
while|while
condition|(
name|i
operator|>
literal|0
condition|)
name|i
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: attributes [[HOT]] = { inlinehint nounwind {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[NORMAL]] = { nounwind {{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[COLD]] = { cold nounwind {{.*}} }
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
name|max
init|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max
condition|;
name|i
operator|++
control|)
name|hot_100_percent
argument_list|(
name|i
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max
operator|*
literal|4
operator|/
literal|10
condition|;
name|i
operator|++
control|)
name|hot_40_percent
argument_list|(
name|i
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max
operator|*
literal|2
operator|/
literal|10
condition|;
name|i
operator|++
control|)
name|normal_func
argument_list|(
name|i
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max
operator|/
literal|200
condition|;
name|i
operator|++
control|)
name|cold_func
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

