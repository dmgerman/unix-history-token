begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* STARTUP PROCEDURE FOR UNIX FORTRAN PROGRAMS */
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
name|xargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|arge
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|char
modifier|*
modifier|*
name|arge
decl_stmt|;
block|{
name|int
name|sigfdie
argument_list|()
decl_stmt|,
name|sigidie
argument_list|()
decl_stmt|;
name|xargc
operator|=
name|argc
expr_stmt|;
name|xargv
operator|=
name|argv
expr_stmt|;
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|sigfdie
argument_list|)
expr_stmt|;
comment|/* ignore underflow, enable overflow */
name|signal
argument_list|(
name|SIGIOT
argument_list|,
name|sigidie
argument_list|)
expr_stmt|;
name|MAIN__
argument_list|()
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|sigfdie
argument_list|()
block|{
name|sigdie
argument_list|(
literal|"Floating Exception"
argument_list|)
block|; }
specifier|static
name|sigidie
argument_list|()
block|{
name|sigdie
argument_list|(
literal|"IOT Trap"
argument_list|)
block|; }
specifier|static
name|sigdie
argument_list|(
name|s
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* print error message, then clear buffers */
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
comment|/* now get a core */
name|signal
argument_list|(
name|SIGIOT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

