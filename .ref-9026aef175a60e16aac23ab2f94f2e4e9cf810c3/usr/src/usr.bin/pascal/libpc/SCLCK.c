begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)SCLCK.c	8.2 (Berkeley) %G%"
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
name|long
name|SCLCK
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
name|ru
operator|.
name|ru_stime
operator|.
name|tv_sec
operator|*
literal|1000
operator|+
name|ru
operator|.
name|ru_stime
operator|.
name|tv_usec
operator|/
literal|1000
operator|)
return|;
block|}
end_function

end_unit

