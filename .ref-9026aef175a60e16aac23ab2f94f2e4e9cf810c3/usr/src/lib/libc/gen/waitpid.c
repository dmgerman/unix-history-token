begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)waitpid.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_function
name|pid_t
if|#
directive|if
name|__STDC__
name|waitpid
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
modifier|*
name|istat
parameter_list|,
name|int
name|options
parameter_list|)
else|#
directive|else
function|waitpid
parameter_list|(
name|pid
parameter_list|,
name|istat
parameter_list|,
name|options
parameter_list|)
name|pid_t
name|pid
decl_stmt|;
name|int
modifier|*
name|istat
decl_stmt|;
name|int
name|options
decl_stmt|;
endif|#
directive|endif
block|{
return|return
operator|(
name|wait4
argument_list|(
name|pid
argument_list|,
name|istat
argument_list|,
name|options
argument_list|,
operator|(
expr|struct
name|rusage
operator|*
operator|)
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

