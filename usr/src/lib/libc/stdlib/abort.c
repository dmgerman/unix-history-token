begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	abort.c	4.1	85/01/24	*/
end_comment

begin_comment
comment|/* C library -- abort */
end_comment

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_macro
name|abort
argument_list|()
end_macro

begin_block
block|{
name|sigblock
argument_list|(
operator|~
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|sigsetmask
argument_list|(
operator|~
name|sigmask
argument_list|(
name|SIGILL
argument_list|)
argument_list|)
expr_stmt|;
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGILL
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

