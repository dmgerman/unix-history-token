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
literal|"@(#)killpg.c	5.3 (Berkeley) %G%"
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * Backwards-compatible killpg().  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|killpg
argument_list|(
argument|pid_t pgid
argument_list|,
argument|int sig
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|killpg
argument_list|(
argument|pgid
argument_list|,
argument|sig
argument_list|)
end_macro

begin_decl_stmt
name|pid_t
name|pgid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sig
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
if|if
condition|(
name|pgid
operator|==
literal|1
condition|)
block|{
name|errno
operator|=
name|ESRCH
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|kill
argument_list|(
operator|-
name|pgid
argument_list|,
name|sig
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

