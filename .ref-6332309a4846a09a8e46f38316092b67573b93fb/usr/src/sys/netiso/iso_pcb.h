begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $Header: iso_pcb.h,v 4.3 88/06/29 15:00:01 hagens Exp $ */
end_comment

begin_comment
comment|/* $Source: /usr/argo/sys/netiso/RCS/iso_pcb.h,v $ */
end_comment

begin_define
define|#
directive|define
name|MAXX25CRUDLEN
value|16
end_define

begin_comment
comment|/* 16 bytes of call request user data */
end_comment

begin_comment
comment|/*  * Common structure pcb for argo protocol implementation.  */
end_comment

begin_struct
struct|struct
name|isopcb
block|{
name|struct
name|isopcb
modifier|*
name|isop_next
decl_stmt|,
modifier|*
name|isop_prev
decl_stmt|;
comment|/* pointers to other pcb's */
name|struct
name|isopcb
modifier|*
name|isop_head
decl_stmt|;
comment|/* pointer back to chain of pcbs for  								this protocol */
name|struct
name|socket
modifier|*
name|isop_socket
decl_stmt|;
comment|/* back pointer to socket */
name|struct
name|sockaddr_iso
name|isop_laddr
decl_stmt|;
define|#
directive|define
name|isop_lport
value|isop_laddr.siso_tsuffix
define|#
directive|define
name|isop_lportlen
value|isop_laddr.siso_tsuffixlen
name|struct
name|sockaddr_iso
name|isop_faddr
decl_stmt|;
define|#
directive|define
name|isop_fport
value|isop_faddr.siso_tsuffix
define|#
directive|define
name|isop_fportlen
value|isop_faddr.siso_tsuffixlen
name|struct
name|route
name|isop_route
decl_stmt|;
comment|/* CLNP routing entry */
name|struct
name|mbuf
modifier|*
name|isop_options
decl_stmt|;
comment|/* CLNP options */
name|struct
name|mbuf
modifier|*
name|isop_optindex
decl_stmt|;
comment|/* CLNP options index */
name|struct
name|mbuf
modifier|*
name|isop_clnpcache
decl_stmt|;
comment|/* CLNP cached hdr */
name|u_int
name|isop_chanmask
decl_stmt|;
comment|/* which ones used - max 32 supported */
name|u_int
name|isop_negchanmask
decl_stmt|;
comment|/* which ones used - max 32 supported */
name|int
name|isop_x25crud_len
decl_stmt|;
comment|/* x25 call request ud */
name|char
name|isop_x25crud
index|[
name|MAXX25CRUDLEN
index|]
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|isop_ifp
decl_stmt|;
comment|/* ESIS interface assoc w/sock */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sotoisopcb
parameter_list|(
name|so
parameter_list|)
value|((struct isopcb *)(so)->so_npcb)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|isopcb
modifier|*
name|iso_pcblookup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

