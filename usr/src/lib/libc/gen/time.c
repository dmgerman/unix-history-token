begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)time.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Backwards compatible time call.  */
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

begin_function
name|long
name|time
parameter_list|(
name|t
parameter_list|)
name|time_t
modifier|*
name|t
decl_stmt|;
block|{
name|struct
name|timeval
name|tt
decl_stmt|;
if|if
condition|(
name|gettimeofday
argument_list|(
operator|&
name|tt
argument_list|,
operator|(
expr|struct
name|timezone
operator|*
operator|)
literal|0
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
if|if
condition|(
name|t
condition|)
operator|*
name|t
operator|=
name|tt
operator|.
name|tv_sec
expr_stmt|;
return|return
operator|(
name|tt
operator|.
name|tv_sec
operator|)
return|;
block|}
end_function

end_unit

