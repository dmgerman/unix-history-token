begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/* $Header: iso_var.h,v 4.2 88/06/29 15:00:08 hagens Exp $ */
end_comment

begin_comment
comment|/* $Source: /usr/argo/sys/netiso/RCS/iso_var.h,v $ */
end_comment

begin_comment
comment|/*  *	Interface address, iso version. One of these structures is   *	allocated for each interface with an osi address. The ifaddr  *	structure conatins the protocol-independent part  *	of the structure, and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|iso_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
name|int
name|ia_flags
decl_stmt|;
name|struct
name|iso_ifaddr
modifier|*
name|ia_next
decl_stmt|;
comment|/* next in list of iso addresses */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ia_addr
end_ifndef

begin_define
define|#
directive|define
name|ia_addr
value|ia_ifa.ifa_addr
end_define

begin_endif
endif|#
directive|endif
endif|ia_addr
end_endif

begin_comment
comment|/*  *	Given a pointer to an iso_ifaddr (ifaddr),  *	return a pointer to the addr as a sockaddr_iso  */
end_comment

begin_define
define|#
directive|define
name|IA_SIS
parameter_list|(
name|ia
parameter_list|)
define|\
value|((struct sockaddr_iso *)(&((struct iso_ifaddr *)ia)->ia_addr))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IFA_ROUTE
end_ifndef

begin_define
define|#
directive|define
name|IFA_ROUTE
value|0x01
end_define

begin_comment
comment|/* routing entry installed */
end_comment

begin_endif
endif|#
directive|endif
endif|IFA_ROUTE
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|iso_ifaddr
modifier|*
name|iso_ifaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* linked list of iso address ifaces */
end_comment

begin_decl_stmt
name|struct
name|ifqueue
name|clnlintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clnl packet input queue */
end_comment

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

