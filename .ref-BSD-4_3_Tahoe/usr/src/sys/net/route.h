begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)route.h	7.4 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Kernel resident routing tables.  *   * The routing tables are initialized when interface addresses  * are set by making entries for all directly connected interfaces.  */
end_comment

begin_comment
comment|/*  * A route consists of a destination address and a reference  * to a routing entry.  These are often held by protocols  * in their control blocks, e.g. inpcb.  */
end_comment

begin_struct
struct|struct
name|route
block|{
name|struct
name|rtentry
modifier|*
name|ro_rt
decl_stmt|;
name|struct
name|sockaddr
name|ro_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * We distinguish between routes to hosts and routes to networks,  * preferring the former if available.  For each route we infer  * the interface to use from the gateway address supplied when  * the route was entered.  Routes that forward packets through  * gateways are marked so that the output routines know to address the  * gateway rather than the ultimate destination.  */
end_comment

begin_struct
struct|struct
name|rtentry
block|{
name|u_long
name|rt_hash
decl_stmt|;
comment|/* to speed lookups */
name|struct
name|sockaddr
name|rt_dst
decl_stmt|;
comment|/* key */
name|struct
name|sockaddr
name|rt_gateway
decl_stmt|;
comment|/* value */
name|short
name|rt_flags
decl_stmt|;
comment|/* up/down?, host/net */
name|short
name|rt_refcnt
decl_stmt|;
comment|/* # held references */
name|u_long
name|rt_use
decl_stmt|;
comment|/* raw # packets forwarded */
name|struct
name|ifnet
modifier|*
name|rt_ifp
decl_stmt|;
comment|/* the answer: interface to use */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTF_UP
value|0x1
end_define

begin_comment
comment|/* route useable */
end_comment

begin_define
define|#
directive|define
name|RTF_GATEWAY
value|0x2
end_define

begin_comment
comment|/* destination is a gateway */
end_comment

begin_define
define|#
directive|define
name|RTF_HOST
value|0x4
end_define

begin_comment
comment|/* host entry (net otherwise) */
end_comment

begin_define
define|#
directive|define
name|RTF_DYNAMIC
value|0x10
end_define

begin_comment
comment|/* created dynamically (by redirect) */
end_comment

begin_define
define|#
directive|define
name|RTF_MODIFIED
value|0x20
end_define

begin_comment
comment|/* modified dynamically (by redirect) */
end_comment

begin_comment
comment|/*  * Routing statistics.  */
end_comment

begin_struct
struct|struct
name|rtstat
block|{
name|short
name|rts_badredirect
decl_stmt|;
comment|/* bogus redirect calls */
name|short
name|rts_dynamic
decl_stmt|;
comment|/* routes created by redirects */
name|short
name|rts_newgateway
decl_stmt|;
comment|/* routes modified by redirects */
name|short
name|rts_unreach
decl_stmt|;
comment|/* lookups which failed */
name|short
name|rts_wildcard
decl_stmt|;
comment|/* lookups satisfied by a wildcard */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|RTFREE
parameter_list|(
name|rt
parameter_list|)
define|\
value|if ((rt)->rt_refcnt == 1) \ 		rtfree(rt); \ 	else \ 		(rt)->rt_refcnt--;
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|RTHASHSIZ
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RTHASHSIZ
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|RTHASHSIZ
operator|&
operator|(
name|RTHASHSIZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|RTHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h)& (RTHASHSIZ - 1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RTHASHMOD
parameter_list|(
name|h
parameter_list|)
value|((h) % RTHASHSIZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rthost
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|rtnet
index|[
name|RTHASHSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rtstat
name|rtstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

