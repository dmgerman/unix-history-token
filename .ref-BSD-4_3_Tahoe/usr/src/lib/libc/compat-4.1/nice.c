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
literal|"@(#)nice.c	5.2 (Berkeley) 3/9/86"
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

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_comment
comment|/*  * Backwards compatible nice.  */
end_comment

begin_macro
name|nice
argument_list|(
argument|incr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|incr
decl_stmt|;
end_decl_stmt

begin_block
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
end_block

end_unit

