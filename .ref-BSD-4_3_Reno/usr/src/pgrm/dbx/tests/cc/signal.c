begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test of tracebacks from signal handlers.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
name|int
name|catch
argument_list|()
decl_stmt|,
name|secondcatch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|catch
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGQUIT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"back in main\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|catch
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"in catch\n"
argument_list|)
expr_stmt|;
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|secondcatch
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGQUIT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"back in catch\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|secondcatch
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"in secondcatch\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

