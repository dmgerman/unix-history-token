begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)fork_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * fork a copy of this process  *  * calling sequence:  *	integer fork  *	ierror = fork()  * where:  *	ierror will be	- child pid if parent and successful  *			- 0 if child  *			- -errno if unsuccessful  */
end_comment

begin_include
include|#
directive|include
file|"../libI77/fiodefs.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|fork_
parameter_list|()
block|{
name|long
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MXUNIT
condition|;
name|i
operator|++
control|)
name|flush_
argument_list|(
operator|&
name|i
argument_list|)
expr_stmt|;
name|i
operator|=
operator|(
name|long
operator|)
name|fork
argument_list|()
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
return|return
operator|(
call|(
name|long
call|)
argument_list|(
operator|-
name|errno
argument_list|)
operator|)
return|;
return|return
operator|(
name|i
operator|)
return|;
block|}
end_function

end_unit

