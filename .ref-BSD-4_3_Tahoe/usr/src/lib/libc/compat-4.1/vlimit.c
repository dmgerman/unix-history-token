begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)vlimit.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * (Almost) backwards compatible vlimit.  */
end_comment

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
file|<errno.h>
end_include

begin_comment
comment|/* LIM_NORAISE is not emulated */
end_comment

begin_define
define|#
directive|define
name|LIM_NORAISE
value|0
end_define

begin_comment
comment|/* if<> 0, can't raise limits */
end_comment

begin_define
define|#
directive|define
name|LIM_CPU
value|1
end_define

begin_comment
comment|/* max secs cpu time */
end_comment

begin_define
define|#
directive|define
name|LIM_FSIZE
value|2
end_define

begin_comment
comment|/* max size of file created */
end_comment

begin_define
define|#
directive|define
name|LIM_DATA
value|3
end_define

begin_comment
comment|/* max growth of data space */
end_comment

begin_define
define|#
directive|define
name|LIM_STACK
value|4
end_define

begin_comment
comment|/* max growth of stack */
end_comment

begin_define
define|#
directive|define
name|LIM_CORE
value|5
end_define

begin_comment
comment|/* max size of ``core'' file */
end_comment

begin_define
define|#
directive|define
name|LIM_MAXRSS
value|6
end_define

begin_comment
comment|/* max desired data+stack core usage */
end_comment

begin_define
define|#
directive|define
name|NLIMITS
value|6
end_define

begin_macro
name|vlimit
argument_list|(
argument|limit
argument_list|,
argument|value
argument_list|)
end_macro

begin_decl_stmt
name|int
name|limit
decl_stmt|,
name|value
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|rlimit
name|rlim
decl_stmt|;
if|if
condition|(
name|limit
operator|<=
literal|0
operator|||
name|limit
operator|>
name|NLIMITS
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
name|value
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|getrlimit
argument_list|(
name|limit
operator|-
literal|1
argument_list|,
operator|&
name|rlim
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|rlim
operator|.
name|rlim_cur
operator|)
return|;
block|}
name|rlim
operator|.
name|rlim_cur
operator|=
name|value
expr_stmt|;
name|rlim
operator|.
name|rlim_max
operator|=
name|RLIM_INFINITY
expr_stmt|;
return|return
operator|(
name|setrlimit
argument_list|(
name|limit
operator|-
literal|1
argument_list|,
operator|&
name|rlim
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

