begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1989, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)nfsiod.c	8.1 (Berkeley) %G%"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucred.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfsv2.h>
end_include

begin_include
include|#
directive|include
file|<nfs/nfs.h>
end_include

begin_comment
comment|/* Global defs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|debug
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|reapchild
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Nfsiod does asynchronous buffered I/O on behalf of the NFS client.  * It does not have to be running for correct operation, but will improve  * throughput. The one optional argument is the number of children to fork.  */
end_comment

begin_function
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
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|int
name|cnt
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
operator|||
operator|(
name|cnt
operator|=
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
operator|)
operator|<=
literal|0
operator|||
name|cnt
operator|>
literal|20
condition|)
name|cnt
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|debug
operator|==
literal|0
condition|)
block|{
name|daemon
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGCHLD
argument_list|,
name|reapchild
argument_list|)
expr_stmt|;
name|openlog
argument_list|(
literal|"nfsiod:"
argument_list|,
name|LOG_PID
argument_list|,
name|LOG_DAEMON
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|cnt
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|fork
argument_list|()
operator|==
literal|0
condition|)
break|break;
if|if
condition|(
name|nfssvc
argument_list|(
name|NFSSVC_BIOD
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
operator|<
literal|0
condition|)
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"nfssvc failed %m"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|reapchild
parameter_list|()
block|{
while|while
condition|(
name|wait3
argument_list|(
operator|(
name|int
operator|*
operator|)
name|NULL
argument_list|,
name|WNOHANG
argument_list|,
operator|(
expr|struct
name|rusage
operator|*
operator|)
name|NULL
argument_list|)
condition|)
empty_stmt|;
block|}
end_function

end_unit

