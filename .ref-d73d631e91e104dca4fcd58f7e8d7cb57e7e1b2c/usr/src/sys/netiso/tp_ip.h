begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_ip.h,v 5.1 88/10/12 12:19:47 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_ip.h,v $  *  * internet IP-dependent structures and include files  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TP_IP__
end_ifndef

begin_define
define|#
directive|define
name|__TP_IP__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SOCK_STREAM
end_ifndef

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_endif
endif|#
directive|endif
endif|SOCK_STREAM
end_endif

begin_include
include|#
directive|include
file|"../netinet/in.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in_systm.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/ip.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/in_pcb.h"
end_include

begin_include
include|#
directive|include
file|"../netinet/ip_var.h"
end_include

begin_decl_stmt
name|struct
name|inpcb
name|tp_inpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of active inpcbs for tp ; for tp with dod ip */
end_comment

begin_endif
endif|#
directive|endif
endif|__TP_IP__
end_endif

end_unit

