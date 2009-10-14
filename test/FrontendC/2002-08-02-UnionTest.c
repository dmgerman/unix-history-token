begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* In this testcase, the return value of foo() is being promotedto a register  * which breaks stuff  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_union
union|union
name|X
block|{
name|char
name|X
decl_stmt|;
name|void
modifier|*
name|B
decl_stmt|;
name|int
name|a
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|,
name|d
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|X
name|foo
parameter_list|()
block|{
name|union
name|X
name|Global
decl_stmt|;
name|Global
operator|.
name|B
operator|=
operator|(
name|void
operator|*
operator|)
literal|123
expr_stmt|;
comment|/* Interesting part */
return|return
name|Global
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|union
name|X
name|test
init|=
name|foo
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"0x%p"
argument_list|,
name|test
operator|.
name|B
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

