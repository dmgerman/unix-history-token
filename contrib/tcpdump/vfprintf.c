begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#) $Header: /tcpdump/master/tcpdump/vfprintf.c,v 1.4 2000/07/01 03:39:12 assar Exp $ (LBL)"
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
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_comment
comment|/*  * Stock 4.3 doesn't have vfprintf.  * This routine is due to Chris Torek.  */
end_comment

begin_macro
name|vfprintf
argument_list|(
argument|f
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|va_list
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|ret
decl_stmt|;
if|if
condition|(
operator|(
name|f
operator|->
name|_flag
operator|&
name|_IOWRT
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|f
operator|->
name|_flag
operator|&
name|_IORW
condition|)
name|f
operator|->
name|_flag
operator||=
name|_IOWRT
expr_stmt|;
else|else
return|return
name|EOF
return|;
block|}
name|ret
operator|=
name|_doprnt
argument_list|(
name|fmt
argument_list|,
name|args
argument_list|,
name|f
argument_list|)
expr_stmt|;
return|return
name|ferror
argument_list|(
name|f
argument_list|)
condition|?
name|EOF
else|:
name|ret
return|;
block|}
end_block

end_unit

