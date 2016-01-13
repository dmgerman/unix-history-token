begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that closedir(NULL) is ok.
end_comment

begin_comment
comment|// RUN: %clang -O2 %s -o %t&& %run %t
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|closedir
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

