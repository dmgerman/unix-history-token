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
literal|"@(#)clock.c	5.4 (Berkeley) %G%"
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
file|<sys/param.h>
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

begin_comment
comment|/*  * Convert usec to clock ticks; could do (usec * CLK_TCK) / 1000000,  * but this would overflow if we switch to nanosec.  */
end_comment

begin_define
define|#
directive|define
name|CONVTCK
parameter_list|(
name|r
parameter_list|)
value|(r.tv_sec * CLK_TCK + r.tv_usec / (1000000 / CLK_TCK))
end_define

begin_function
name|clock_t
name|clock
parameter_list|()
block|{
name|struct
name|rusage
name|ru
decl_stmt|;
if|if
condition|(
name|getrusage
argument_list|(
name|RUSAGE_SELF
argument_list|,
operator|&
name|ru
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
return|return
operator|(
call|(
name|clock_t
call|)
argument_list|(
operator|(
name|CONVTCK
argument_list|(
name|ru
operator|.
name|ru_utime
argument_list|)
operator|+
name|CONVTCK
argument_list|(
name|ru
operator|.
name|ru_stime
argument_list|)
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

