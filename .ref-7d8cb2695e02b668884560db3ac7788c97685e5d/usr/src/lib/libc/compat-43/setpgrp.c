begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)setpgrp.c	8.1 (Berkeley) %G%"
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
file|<unistd.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|setpgrp
argument_list|(
argument|pid_t pid
argument_list|,
argument|pid_t pgid
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|setpgrp
argument_list|(
argument|pid
argument_list|,
argument|pgid
argument_list|)
end_macro

begin_decl_stmt
name|pid_t
name|pid
decl_stmt|,
name|pgid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
return|return
operator|(
name|setpgid
argument_list|(
name|pid
argument_list|,
name|pgid
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

