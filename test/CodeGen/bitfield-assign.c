begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Check that the result of a bitfield assignment is properly    truncated and does not generate a redundant load. */
end_comment

begin_comment
comment|/* Check that we get one load for each simple assign and two for the    compound assign (load the old value before the add then load again    to store back). Also check that our g0 pattern is good. */
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -O0 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep 'load ' %t | count 5
end_comment

begin_comment
comment|// RUN: grep "@g0" %t | count 4
end_comment

begin_comment
comment|// Check that we got the right value.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-unknown -O3 -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep 'load ' %t | count 0
end_comment

begin_comment
comment|// RUN: grep "@g0" %t | count 0
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|f0
range|:
literal|2
decl_stmt|;
name|_Bool
name|f1
range|:
literal|1
decl_stmt|;
name|unsigned
name|f2
range|:
literal|2
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|g0
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|f0
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s0
name|s
decl_stmt|;
if|if
condition|(
operator|(
name|s
operator|.
name|f0
operator|=
literal|3
operator|)
operator|!=
operator|-
literal|1
condition|)
name|g0
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s0
name|s
decl_stmt|;
if|if
condition|(
operator|(
name|s
operator|.
name|f1
operator|=
literal|3
operator|)
operator|!=
literal|1
condition|)
name|g0
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s0
name|s
decl_stmt|;
if|if
condition|(
operator|(
name|s
operator|.
name|f2
operator|=
literal|3
operator|)
operator|!=
literal|3
condition|)
name|g0
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|s0
name|s
decl_stmt|;
comment|// Just check this one for load counts.
name|s
operator|.
name|f0
operator|+=
literal|3
expr_stmt|;
block|}
end_function

end_unit

