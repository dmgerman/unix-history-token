begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)nice.c	8.1 (Berkeley) %G%"
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
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * Backwards compatible nice.  */
end_comment

begin_function
name|int
name|nice
parameter_list|(
name|incr
parameter_list|)
name|int
name|incr
decl_stmt|;
block|{
name|int
name|prio
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|prio
operator|=
name|getpriority
argument_list|(
name|PRIO_PROCESS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|prio
operator|==
operator|-
literal|1
operator|&&
name|errno
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|setpriority
argument_list|(
name|PRIO_PROCESS
argument_list|,
literal|0
argument_list|,
name|prio
operator|+
name|incr
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

