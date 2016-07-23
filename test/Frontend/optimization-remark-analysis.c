begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -O1 -fvectorize -target x86_64-unknown-unknown -emit-llvm -Rpass-analysis -S %s -o - 2>&1 | FileCheck %s --check-prefix=RPASS
end_comment

begin_comment
comment|// RUN: %clang -O1 -fvectorize -target x86_64-unknown-unknown -emit-llvm -S %s -o - 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RPASS: {{.*}}:7:8: remark: loop not vectorized: loop contains a switch statement
end_comment

begin_comment
comment|// CHECK-NOT: {{.*}}:7:8: remark: loop not vectorized: loop contains a switch statement
end_comment

begin_function
name|double
name|foo
parameter_list|(
name|int
name|N
parameter_list|,
name|int
modifier|*
name|Array
parameter_list|)
block|{
name|double
name|v
init|=
literal|0.0
decl_stmt|;
pragma|#
directive|pragma
name|clang
name|loop
name|vectorize
name|(
name|enable
name|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|N
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|Array
index|[
name|i
index|]
condition|)
block|{
case|case
literal|0
case|:
name|v
operator|+=
literal|1.0f
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|v
operator|-=
literal|0.5f
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|v
operator|*=
literal|2.0f
expr_stmt|;
break|break;
default|default:
name|v
operator|=
literal|0.0f
expr_stmt|;
block|}
block|}
return|return
name|v
return|;
block|}
end_function

end_unit

