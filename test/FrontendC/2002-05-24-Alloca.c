begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|char
modifier|*
name|C
init|=
operator|(
name|char
operator|*
operator|)
name|alloca
argument_list|(
name|argc
argument_list|)
decl_stmt|;
name|strcpy
argument_list|(
name|C
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

