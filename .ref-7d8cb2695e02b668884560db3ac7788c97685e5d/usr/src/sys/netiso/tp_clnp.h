begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tp_clnp.h	7.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_clnp.h,v 5.1 88/10/12 12:16:36 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_clnp.h,v $  *  * AF_ISO net-dependent structures and include files  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TP_CLNP__
end_ifndef

begin_define
define|#
directive|define
name|__TP_CLNP__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SOCK_STREAM
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCK_STREAM */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTFREE
end_ifndef

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netiso/iso.h>
end_include

begin_include
include|#
directive|include
file|<netiso/clnp.h>
end_include

begin_include
include|#
directive|include
file|<netiso/iso_pcb.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|IF_DEQUEUE
end_ifndef

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netiso/iso_var.h>
end_include

begin_decl_stmt
name|struct
name|isopcb
name|tp_isopcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of active inpcbs for tp ; for tp with dod ip */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TP_CLNP__ */
end_comment

end_unit

