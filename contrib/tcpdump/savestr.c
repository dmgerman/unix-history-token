begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/Attic/savestr.c,v 1.6 2000/07/11 00:49:02 assar Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_OS_PROTO_H
end_ifdef

begin_include
include|#
directive|include
file|"os-proto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"savestr.h"
end_include

begin_comment
comment|/* A replacement for strdup() that cuts down on malloc() overhead */
end_comment

begin_function
name|char
modifier|*
name|savestr
parameter_list|(
specifier|register
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
specifier|register
name|u_int
name|size
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|static
name|char
modifier|*
name|strptr
init|=
name|NULL
decl_stmt|;
specifier|static
name|u_int
name|strsize
init|=
literal|0
decl_stmt|;
name|size
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|size
operator|>
name|strsize
condition|)
block|{
name|strsize
operator|=
literal|1024
expr_stmt|;
if|if
condition|(
name|strsize
operator|<
name|size
condition|)
name|strsize
operator|=
name|size
expr_stmt|;
name|strptr
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|strsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|strptr
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"savestr: malloc\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|strptr
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|p
operator|=
name|strptr
expr_stmt|;
name|strptr
operator|+=
name|size
expr_stmt|;
name|strsize
operator|-=
name|size
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

end_unit

