begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * $Header: iso_usrreq.c,v 4.2 88/06/29 15:00:06 hagens Exp $   * $Source: /usr/argo/sys/netiso/RCS/iso_usrreq.c,v $   *	@(#)iso_usrreq.c	7.3 (Berkeley) %G% *  *  * iso_usrreq.c : support for iso address family ioctls only.  * (which support ifconfig, for example)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: iso_usrreq.c,v 4.2 88/06/29 15:00:06 hagens Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISO
end_ifdef

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"../net/if.h"
end_include

begin_include
include|#
directive|include
file|"../net/route.h"
end_include

begin_include
include|#
directive|include
file|"iso.h"
end_include

begin_include
include|#
directive|include
file|"clnp.h"
end_include

begin_include
include|#
directive|include
file|"clnp_stat.h"
end_include

begin_include
include|#
directive|include
file|"argo_debug.h"
end_include

begin_comment
comment|/*  * FUNCTION:		iso_usrreq  *  * PURPOSE:			Provide a means of getting from soo_ioctl to iso_control  *  * RETURNS:			unix error code  *  * SIDE EFFECTS:	  *  * NOTES:			Only PRU_CONTROL causes anything to occur. PRU_ATTACH  *					and PRU_DETACH are noops so socket and close don't return  *					an error code.  */
end_comment

begin_macro
name|iso_usrreq
argument_list|(
argument|so
argument_list|,
argument|req
argument_list|,
argument|m
argument_list|,
argument|nam
argument_list|,
argument|rights
argument_list|,
argument|control
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket: used only to get to this code */
end_comment

begin_decl_stmt
name|int
name|req
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* request */
end_comment

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data for request */
end_comment

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|nam
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optional name */
end_comment

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rights
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optional rights */
end_comment

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* optional control info */
end_comment

begin_block
block|{
name|int
name|error
decl_stmt|;
switch|switch
condition|(
name|req
condition|)
block|{
case|case
name|PRU_CONTROL
case|:
name|error
operator|=
name|iso_control
argument_list|(
name|so
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
operator|(
name|caddr_t
operator|)
name|nam
argument_list|,
operator|(
expr|struct
name|ifnet
operator|*
operator|)
name|rights
argument_list|)
expr_stmt|;
break|break;
case|case
name|PRU_ATTACH
case|:
case|case
name|PRU_DETACH
case|:
name|error
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
name|error
operator|=
name|EOPNOTSUPP
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
endif|ISO
end_endif

end_unit

