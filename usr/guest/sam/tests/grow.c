begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_macro
name|catch
argument_list|(
argument|s
argument_list|,
argument|code
argument_list|,
argument|scp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|,
name|code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sigcontext
modifier|*
name|scp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|main
parameter_list|()
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|catch
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
name|sigpause
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

