begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  The following test program tries the pathconf(2) routine.  It should **  be run in a non-NFS-mounted directory (e.g., /tmp) and on remote (NFS) **  mounted directories running both NFS-v2 and NFS-v3 from systems that **  both do and do not permit file giveaway. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|EX_OK
end_ifdef

begin_undef
undef|#
directive|undef
name|EX_OK
end_undef

begin_comment
comment|/* unistd.h may have another use for this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EX_OK */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: t_pathconf.c,v 8.5 1999/08/28 00:25:28 gshapiro Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|fd
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
name|tbuf
index|[
literal|100
index|]
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
if|if
condition|(
name|geteuid
argument_list|()
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"*** Run me as a non-root user! ***\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_USAGE
argument_list|)
expr_stmt|;
block|}
name|strcpy
argument_list|(
name|tbuf
argument_list|,
literal|"TXXXXXX"
argument_list|)
expr_stmt|;
name|fd
operator|=
name|mkstemp
argument_list|(
name|tbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"*** Could not create test file %s\n"
argument_list|,
name|tbuf
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_CANTCREAT
argument_list|)
expr_stmt|;
block|}
name|errno
operator|=
literal|0
expr_stmt|;
name|i
operator|=
name|pathconf
argument_list|(
literal|"."
argument_list|,
name|_PC_CHOWN_RESTRICTED
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"pathconf(.) returns %2d, errno = %d\n"
argument_list|,
name|i
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|i
operator|=
name|pathconf
argument_list|(
name|tbuf
argument_list|,
name|_PC_CHOWN_RESTRICTED
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"pathconf(%s) returns %2d, errno = %d\n"
argument_list|,
name|tbuf
argument_list|,
name|i
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|i
operator|=
name|fpathconf
argument_list|(
name|fd
argument_list|,
name|_PC_CHOWN_RESTRICTED
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"fpathconf(%s) returns %2d, errno = %d\n"
argument_list|,
name|tbuf
argument_list|,
name|i
argument_list|,
name|errno
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|==
literal|0
operator|&&
name|i
operator|>=
literal|0
condition|)
block|{
comment|/* so it claims that it doesn't work -- try anyhow */
name|printf
argument_list|(
literal|"  fpathconf claims that chown is safe "
argument_list|)
expr_stmt|;
if|if
condition|(
name|fchown
argument_list|(
name|fd
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
operator|>=
literal|0
condition|)
name|printf
argument_list|(
literal|"*** but fchown works anyhow! ***\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"and fchown agrees\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* well, let's see what really happens */
name|printf
argument_list|(
literal|"  fpathconf claims that chown is not safe "
argument_list|)
expr_stmt|;
if|if
condition|(
name|fchown
argument_list|(
name|fd
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
operator|>=
literal|0
condition|)
name|printf
argument_list|(
literal|"as indeed it is not\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"*** but in fact it is safe ***\n"
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|tbuf
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EX_OK
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

