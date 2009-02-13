begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991 Regents of The University of Michigan.  * All Rights Reserved.  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby granted,  * provided that the above copyright notice appears in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation, and that the name of The University  * of Michigan not be used in advertising or publicity pertaining to  * distribution of the software without specific, written prior  * permission. This software is supplied as is without expressed or  * implied warranties of any kind.  *  *	Research Systems Unix Group  *	The University of Michigan  *	c/o Mike Clark  *	535 W. William Street  *	Ann Arbor, Michigan  *	+1-313-763-0525  *	netatalk@itd.umich.edu  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATALK_AT_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETATALK_AT_VAR_H_
end_define

begin_comment
comment|/*  * For phase2, we need to keep not only our address on an interface, but also  * the legal networks on the interface.  */
end_comment

begin_struct
struct|struct
name|at_ifaddr
block|{
name|struct
name|ifaddr
name|aa_ifa
decl_stmt|;
name|struct
name|sockaddr_at
name|aa_addr
decl_stmt|;
name|struct
name|sockaddr_at
name|aa_broadaddr
decl_stmt|;
name|struct
name|sockaddr_at
name|aa_netmask
decl_stmt|;
name|int
name|aa_flags
decl_stmt|;
name|u_short
name|aa_firstnet
decl_stmt|;
name|u_short
name|aa_lastnet
decl_stmt|;
name|int
name|aa_probcnt
decl_stmt|;
name|struct
name|callout
name|aa_callout
decl_stmt|;
name|struct
name|at_ifaddr
modifier|*
name|aa_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|aa_ifp
value|aa_ifa.ifa_ifp
end_define

begin_define
define|#
directive|define
name|aa_dstaddr
value|aa_broadaddr;
end_define

begin_struct
struct|struct
name|at_aliasreq
block|{
name|char
name|ifra_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|struct
name|sockaddr_at
name|ifra_addr
decl_stmt|;
name|struct
name|sockaddr_at
name|ifra_broadaddr
decl_stmt|;
name|struct
name|sockaddr_at
name|ifra_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifra_dstaddr
value|ifra_broadaddr
end_define

begin_define
define|#
directive|define
name|AA_SAT
parameter_list|(
name|aa
parameter_list|)
value|(&(aa->aa_addr))
end_define

begin_define
define|#
directive|define
name|satosat
parameter_list|(
name|sa
parameter_list|)
value|((struct sockaddr_at *)(sa))
end_define

begin_define
define|#
directive|define
name|AFA_ROUTE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AFA_PROBING
value|0x0002
end_define

begin_define
define|#
directive|define
name|AFA_PHASE2
value|0x0004
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|at_ifaddr
modifier|*
name|at_ifaddr_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATALK_AT_VAR_H_ */
end_comment

end_unit

