begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Check that the 'sink' options work.  * RUN: llvmc -v -Wall %s -o %t |& grep "Wall"  * RUN: %abs_tmp | grep hello  * XFAIL: vg_leak  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"hello\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

