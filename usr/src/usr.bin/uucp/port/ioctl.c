begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)ioctl.c	8.1 (Berkeley) 6/6/93"
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
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/*******  *	ioctl(fn, com, ttbuf)	for machines without ioctl  *	int fn, com;  *	struct sgttyb *ttbuf;  *  *	return codes - same as stty and gtty  */
end_comment

begin_expr_stmt
name|ioctl
argument_list|(
name|fn
argument_list|,
name|com
argument_list|,
name|ttbuf
argument_list|)
specifier|register
name|int
name|fn
operator|,
name|com
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|sgttyb
modifier|*
name|ttbuf
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|sgttyb
name|tb
decl_stmt|;
switch|switch
condition|(
name|com
condition|)
block|{
case|case
name|TIOCHPCL
case|:
name|gtty
argument_list|(
name|fn
argument_list|,
operator|&
name|tb
argument_list|)
expr_stmt|;
name|tb
operator|.
name|sg_flags
operator||=
literal|1
expr_stmt|;
return|return
operator|(
name|stty
argument_list|(
name|fn
argument_list|,
operator|&
name|tb
argument_list|)
operator|)
return|;
case|case
name|TIOCGETP
case|:
return|return
operator|(
name|gtty
argument_list|(
name|fn
argument_list|,
name|ttbuf
argument_list|)
operator|)
return|;
case|case
name|TIOCSETP
case|:
return|return
operator|(
name|stty
argument_list|(
name|fn
argument_list|,
name|ttbuf
argument_list|)
operator|)
return|;
case|case
name|TIOCEXCL
case|:
case|case
name|TIOCNXCL
case|:
default|default:
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_block

end_unit

