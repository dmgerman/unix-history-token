begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** **  This file has been modified to get it to compile more easily **  on pre-4.4BSD systems.  Rich $alz, June 1991. */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* NULL */
end_comment

begin_define
define|#
directive|define
name|void
value|char
end_define

begin_define
define|#
directive|define
name|size_t
value|int
end_define

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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

begin_endif
unit|static char sccsid[] = "@(#)memchr.c	5.5 (Berkeley) 5/15/90";
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
modifier|*
name|memchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
specifier|const
name|void
modifier|*
name|s
decl_stmt|;
specifier|register
name|unsigned
name|char
name|c
decl_stmt|;
specifier|register
name|size_t
name|n
decl_stmt|;
block|{
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
specifier|register
specifier|const
name|unsigned
name|char
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|s
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|*
name|p
operator|++
operator|==
name|c
condition|)
return|return
operator|(
operator|(
name|void
operator|*
operator|)
operator|(
name|p
operator|-
literal|1
operator|)
operator|)
return|;
block|}
do|while
condition|(
operator|--
name|n
operator|!=
literal|0
condition|)
do|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

