begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)wrapup.c	4.1	(Berkeley)	%G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"lrnref.h"
end_include

begin_macro
name|wrapup
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* this routine does not use 'system' because it wants 	 interrupts turned off */
name|int
name|retval
decl_stmt|,
name|pid
decl_stmt|,
name|pidw
decl_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|chdir
argument_list|(
literal|".."
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pid
operator|=
name|fork
argument_list|()
operator|)
operator|==
literal|0
condition|)
block|{
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|execl
argument_list|(
literal|"/bin/rm"
argument_list|,
literal|"rm"
argument_list|,
literal|"-r"
argument_list|,
name|dir
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|execl
argument_list|(
literal|"/usr/bin/rm"
argument_list|,
literal|"rm"
argument_list|,
literal|"-r"
argument_list|,
name|dir
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Can't find 'rm' command.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Bye.\n"
argument_list|)
expr_stmt|;
comment|/* not only does this reassure user but  			it stalls for time while deleting directory */
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
comment|/* printf("Wantd %d got %d val %d\n",pid, pidw, retval); */
name|exit
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

