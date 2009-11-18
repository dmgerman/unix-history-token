begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown --emit-llvm-bc -o - %s | opt --std-compile-opts | llvm-dis> %t
end_comment

begin_comment
comment|// RUN: grep "ret i32" %t | count 2
end_comment

begin_comment
comment|// RUN: grep "ret i32 0" %t | count 2
end_comment

begin_comment
comment|//<rdar://problem/6113085>
end_comment

begin_struct
struct|struct
name|s0
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|f0
parameter_list|()
block|{
name|struct
name|s0
name|x
init|=
block|{
literal|0
block|}
decl_stmt|;
return|return
name|x
operator|.
name|y
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Optimizer isn't smart enough to reduce this since we use    memset. Hrm. */
end_comment

begin_endif
unit|int f1() {   struct s0 x[2] = { {0} };   return x[1].x; }
endif|#
directive|endif
end_endif

begin_function
name|int
name|f2
parameter_list|()
block|{
name|int
name|x
index|[
literal|2
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
return|return
name|x
index|[
literal|1
index|]
return|;
block|}
end_function

end_unit

