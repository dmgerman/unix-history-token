begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|sigjmp_buf
name|B
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
name|sigsetjmp
argument_list|(
name|B
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

