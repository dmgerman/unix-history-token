begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)ualarm.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|USPS
value|1000000
end_define

begin_comment
comment|/* # of microseconds in a second */
end_comment

begin_comment
comment|/*  * Generate a SIGALRM signal in ``usecs'' microseconds.  * If ``reload'' is non-zero, keep generating SIGALRM  * every ``reload'' microseconds after the first signal.  */
end_comment

begin_function
name|unsigned
name|ualarm
parameter_list|(
name|usecs
parameter_list|,
name|reload
parameter_list|)
specifier|register
name|unsigned
name|usecs
decl_stmt|;
specifier|register
name|unsigned
name|reload
decl_stmt|;
block|{
name|struct
name|itimerval
name|new
decl_stmt|,
name|old
decl_stmt|;
name|new
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|reload
operator|%
name|USPS
expr_stmt|;
name|new
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|reload
operator|/
name|USPS
expr_stmt|;
name|new
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|usecs
operator|%
name|USPS
expr_stmt|;
name|new
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|usecs
operator|/
name|USPS
expr_stmt|;
if|if
condition|(
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|new
argument_list|,
operator|&
name|old
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|old
operator|.
name|it_value
operator|.
name|tv_sec
operator|*
name|USPS
operator|+
name|old
operator|.
name|it_value
operator|.
name|tv_usec
operator|)
return|;
comment|/* else */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

