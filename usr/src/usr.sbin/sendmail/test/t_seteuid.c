begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  This program checks to see if your version of seteuid works. **  Compile it, make it setuid root, and run it as yourself (NOT as **  root).  If it won't compile or outputs any MAYDAY messages, don't **  define USESETEUID in conf.h. ** **	NOTE:  It is not sufficient to have seteuid in your library. **	You must also have saved uids that function properly. ** **  Compilation is trivial -- just "cc t_seteuid.c". */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|seteuid
parameter_list|(
name|e
parameter_list|)
value|setresuid(-1, e, -1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|()
block|{
name|uid_t
name|realuid
init|=
name|getuid
argument_list|()
decl_stmt|;
name|printuids
argument_list|(
literal|"initial uids"
argument_list|,
name|realuid
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"re-run setuid root\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|seteuid
argument_list|(
literal|1
argument_list|)
operator|<
literal|0
condition|)
name|printf
argument_list|(
literal|"seteuid(1) failure\n"
argument_list|)
expr_stmt|;
name|printuids
argument_list|(
literal|"after seteuid(1)"
argument_list|,
name|realuid
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|1
condition|)
name|printf
argument_list|(
literal|"MAYDAY!  Wrong effective uid\n"
argument_list|)
expr_stmt|;
comment|/* do activity here */
if|if
condition|(
name|seteuid
argument_list|(
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|printf
argument_list|(
literal|"seteuid(0) failure\n"
argument_list|)
expr_stmt|;
name|printuids
argument_list|(
literal|"after seteuid(0)"
argument_list|,
name|realuid
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"MAYDAY!  Wrong effective uid\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|getuid
argument_list|()
operator|!=
name|realuid
condition|)
name|printf
argument_list|(
literal|"MAYDAY!  Wrong real uid\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|seteuid
argument_list|(
literal|2
argument_list|)
operator|<
literal|0
condition|)
name|printf
argument_list|(
literal|"seteuid(2) failure\n"
argument_list|)
expr_stmt|;
name|printuids
argument_list|(
literal|"after seteuid(2)"
argument_list|,
name|realuid
argument_list|,
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|2
condition|)
name|printf
argument_list|(
literal|"MAYDAY!  Wrong effective uid\n"
argument_list|)
expr_stmt|;
comment|/* do activity here */
if|if
condition|(
name|seteuid
argument_list|(
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|printf
argument_list|(
literal|"seteuid(0) failure\n"
argument_list|)
expr_stmt|;
name|printuids
argument_list|(
literal|"after seteuid(0)"
argument_list|,
name|realuid
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"MAYDAY!  Wrong effective uid\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|getuid
argument_list|()
operator|!=
name|realuid
condition|)
name|printf
argument_list|(
literal|"MAYDAY!  Wrong real uid\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|printuids
argument_list|(
argument|str
argument_list|,
argument|r
argument_list|,
argument|e
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|r
decl_stmt|,
name|e
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"%s (should be %d/%d): r/euid=%d/%d\n"
argument_list|,
name|str
argument_list|,
name|r
argument_list|,
name|e
argument_list|,
name|getuid
argument_list|()
argument_list|,
name|geteuid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

