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
literal|"@(#) $Header: /tcpdump/master/tcpdump/setsignal.c,v 1.7 2000/07/11 00:49:03 assar Exp $ (LBL)"
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
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|"setsignal.h"
end_include

begin_comment
comment|/*  * An os independent signal() with BSD semantics, e.g. the signal  * catcher is restored following service of the signal.  *  * When sigset() is available, signal() has SYSV semantics and sigset()  * has BSD semantics and call interface. Unfortunately, Linux does not  * have sigset() so we use the more complicated sigaction() interface  * there.  *  * Did I mention that signals suck?  */
end_comment

begin_macro
name|RETSIGTYPE
argument_list|(
argument|*setsignal (int sig, RETSIGTYPE (*func)(int))
argument_list|)
end_macro

begin_expr_stmt
operator|(
name|int
operator|)
block|{
ifdef|#
directive|ifdef
name|HAVE_SIGACTION
block|struct
name|sigaction
name|old
block|,
name|new
block|;
name|memset
argument_list|(
operator|&
name|new
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|new
argument_list|)
argument_list|)
block|;
name|new
operator|.
name|sa_handler
operator|=
name|func
block|;
ifdef|#
directive|ifdef
name|SA_RESTART
name|new
operator|.
name|sa_flags
operator||=
name|SA_RESTART
block|;
endif|#
directive|endif
if|if
condition|(
name|sigaction
argument_list|(
name|sig
argument_list|,
operator|&
name|new
argument_list|,
operator|&
name|old
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
name|SIG_ERR
operator|)
return|;
end_expr_stmt

begin_return
return|return
operator|(
name|old
operator|.
name|sa_handler
operator|)
return|;
end_return

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SIGSET
end_ifdef

begin_return
return|return
operator|(
name|sigset
argument_list|(
name|sig
argument_list|,
name|func
argument_list|)
operator|)
return|;
end_return

begin_else
else|#
directive|else
end_else

begin_return
return|return
operator|(
name|signal
argument_list|(
name|sig
argument_list|,
name|func
argument_list|)
operator|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

unit|}
end_unit

