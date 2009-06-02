begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -O0 -o - -mllvm -disable-llvm-optzns | grep bar
end_comment

begin_comment
comment|// Check that the gcc inliner is turned off.
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|__inline__
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|)
argument_list|)
name|int
name|bar
argument_list|(
name|int
name|x
argument_list|)
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|long
name|long
name|b
init|=
literal|1
decl_stmt|;
name|int
name|Y
init|=
name|bar
argument_list|(
literal|4
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|Y
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

