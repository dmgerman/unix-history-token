begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1987, 1990 The Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

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
literal|"@(#)update.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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

begin_function
name|main
parameter_list|()
block|{
name|struct
name|itimerval
name|value
decl_stmt|;
name|void
name|mysync
parameter_list|()
function_decl|;
name|daemon
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|mysync
argument_list|)
expr_stmt|;
name|value
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
literal|30
expr_stmt|;
name|value
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
name|value
operator|.
name|it_value
operator|=
name|value
operator|.
name|it_interval
expr_stmt|;
if|if
condition|(
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|value
argument_list|,
name|NULL
argument_list|)
condition|)
block|{
name|perror
argument_list|(
literal|"update: setitimer"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
init|;
condition|;
control|)
name|sigpause
argument_list|(
name|sigblock
argument_list|(
literal|0L
argument_list|)
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_function
name|void
name|mysync
parameter_list|()
block|{
operator|(
name|void
operator|)
name|sync
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

