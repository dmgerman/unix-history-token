begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)clock.c	5.3 (Berkeley) %G%"
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
file|<machine/machlimits.h>
end_include

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

begin_function
name|clock_t
name|clock
parameter_list|()
block|{
name|struct
name|rusage
name|rusage
decl_stmt|;
name|clock_t
name|val
decl_stmt|;
if|if
condition|(
name|getrusage
argument_list|(
name|RUSAGE_SELF
argument_list|,
operator|&
name|rusage
argument_list|)
condition|)
return|return
operator|(
operator|(
name|clock_t
operator|)
operator|-
literal|1
operator|)
return|;
name|val
operator|=
operator|(
name|rusage
operator|.
name|ru_utime
operator|.
name|tv_sec
operator|+
name|rusage
operator|.
name|ru_stime
operator|.
name|tv_sec
operator|)
operator|*
name|CLK_TCK
expr_stmt|;
comment|/* 	 * Convert usec to clock ticks; could do (usec * CLK_TCK) / 1000000, 	 * but this would overflow if we switch to nanosec. 	 */
name|val
operator|+=
operator|(
name|rusage
operator|.
name|ru_utime
operator|.
name|tv_usec
operator|+
name|rusage
operator|.
name|ru_stime
operator|.
name|tv_usec
operator|)
operator|/
operator|(
literal|1000000
operator|/
name|CLK_TCK
operator|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

end_unit

