begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test if PGO sample use preparation passes are executed correctly.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure that instcombine is executed after simplifycfg and sroa so that
end_comment

begin_comment
comment|// "a< 255" will not be converted to a * 256< 255 * 256.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O2 -fprofile-sample-use=%S/Inputs/pgo-sample.prof %s -emit-llvm -o - 2>&1 | FileCheck %s
end_comment

begin_function_decl
name|void
name|bar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|z
parameter_list|)
block|{
name|int
name|m
decl_stmt|;
for|for
control|(
name|m
operator|=
literal|0
init|;
name|m
operator|<
name|x
condition|;
name|m
operator|++
control|)
block|{
name|int
name|a
init|=
operator|(
operator|(
operator|(
name|y
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator|*
name|z
operator|)
operator|/
literal|256
decl_stmt|;
name|bar
argument_list|(
name|a
operator|<
literal|255
condition|?
name|a
else|:
literal|255
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// CHECK-NOT: icmp slt i32 %mul, 65280
end_comment

end_unit

