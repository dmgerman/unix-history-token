begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/machdep.c,v 1.13 2003/12/15 03:53:21 guy Exp $ (LBL)"
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

begin_comment
comment|/*  * XXX - all we need, on platforms other than DEC OSF/1 (a/k/a Digital UNIX,  * a/k/a Tru64 UNIX), is "size_t", which is a standard C type; what do we  * need to do to get it defined?  This is clearly wrong, as we shouldn't  * have to include UNIX or Windows system header files to get it.  */
end_comment

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___ATTRIBUTE__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___ATTRIBUTE__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_include
include|#
directive|include
file|<sys/sysinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SNPRINTF
argument_list|)
end_if

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SNPRINTF) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __osf__ */
end_comment

begin_include
include|#
directive|include
file|"machdep.h"
end_include

begin_function
name|int
name|abort_on_misalignment
parameter_list|(
name|char
modifier|*
name|ebuf
name|_U_
parameter_list|,
name|size_t
name|ebufsiz
name|_U_
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__osf__
specifier|static
name|int
name|buf
index|[
literal|2
index|]
init|=
block|{
name|SSIN_UACPROC
block|,
name|UAC_SIGBUS
block|}
decl_stmt|;
if|if
condition|(
name|setsysinfo
argument_list|(
name|SSI_NVPAIRS
argument_list|,
operator|(
name|caddr_t
operator|)
name|buf
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|ebuf
argument_list|,
name|ebufsiz
argument_list|,
literal|"setsysinfo: errno %d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

