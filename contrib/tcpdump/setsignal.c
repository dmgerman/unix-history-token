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
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/setsignal.c,v 1.11 2003/11/16 09:36:42 guy Exp $ (LBL)"
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
file|<tcpdump-stdinc.h>
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
comment|/*  * An OS-independent signal() with, whenever possible, partial BSD  * semantics, i.e. the signal handler is restored following service  * of the signal, but system calls are *not* restarted, so that if  * "pcap_breakloop()" is called in a signal handler in a live capture,  * the read/recvfrom/whatever in the live capture doesn't get restarted,  * it returns -1 and sets "errno" to EINTR, so we can break out of the  * live capture loop.  *  * We use "sigaction()" if available.  We don't specify that the signal  * should restart system calls, so that should always do what we want.  *  * Otherwise, if "sigset()" is available, it probably has BSD semantics  * while "signal()" has traditional semantics, so we use "sigset()"; it  * might cause system calls to be restarted for the signal, however.  * I don't know whether, in any systems where it did cause system calls to  * be restarted, there was a way to ask it not to do so; there may no  * longer be any interesting systems without "sigaction()", however,  * and, if there are, they might have "sigvec()" with SV_INTERRUPT  * (which I think first appeared in 4.3BSD).  *  * Otherwise, we use "signal()" - which means we might get traditional  * semantics, wherein system calls don't get restarted *but* the  * signal handler is reset to SIG_DFL and the signal is not blocked,  * so that a subsequent signal would kill the process immediately.  *  * Did I mention that signals suck?  At least in POSIX-compliant systems  * they suck far less, as those systems have "sigaction()".  */
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

