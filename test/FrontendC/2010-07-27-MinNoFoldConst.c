begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | FileCheck %s
end_comment

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|bad
parameter_list|(
name|unsigned
name|int
name|v1
parameter_list|,
name|unsigned
name|int
name|v2
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%u\n"
argument_list|,
literal|1631381461u
operator|*
operator|(
operator|(
operator|(
name|v2
operator|-
literal|1273463329u
operator|<=
name|v1
operator|-
literal|1273463329u
operator|)
condition|?
name|v2
else|:
name|v1
operator|)
operator|-
literal|1273463329u
operator|)
operator|+
literal|121322179u
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Radar 8198362
end_comment

begin_comment
comment|// GCC FE wants to convert the above to
end_comment

begin_comment
comment|//   1631381461u * MIN(v2 - 1273463329u, v1 - 1273463329u)
end_comment

begin_comment
comment|// and then to
end_comment

begin_comment
comment|//   MIN(1631381461u * v2 - 4047041419, 1631381461u * v1 - 4047041419)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1631381461u * 1273463329u = 2077504466193943669, but 32-bit overflow clips
end_comment

begin_comment
comment|// this to 4047041419. This breaks the comparison implicit in the MIN().
end_comment

begin_comment
comment|// Two multiply operations suggests the bad optimization is happening;
end_comment

begin_comment
comment|// one multiplication, after the MIN(), is correct.
end_comment

begin_comment
comment|// CHECK: mul
end_comment

begin_comment
comment|// CHECK-NOT: mul
end_comment

begin_comment
comment|// CHECK: ret
end_comment

end_unit

