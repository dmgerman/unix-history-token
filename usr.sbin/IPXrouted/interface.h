begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 1995 John Hay.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)interface.h	8.1 (Berkeley) 6/5/93  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
end_comment

begin_comment
comment|/*  * An ``interface'' is similar to an ifnet structure,  * except it doesn't contain q'ing info, and it also  * handles ``logical'' interfaces (remote gateways  * that we want to keep polling even if they go down).  * The list of interfaces which we maintain is used  * in supplying the gratuitous routing table updates.  * We list only one address for  each interface, the AF_IPX one.  */
end_comment

begin_struct
struct|struct
name|interface
block|{
name|struct
name|interface
modifier|*
name|int_next
decl_stmt|;
name|struct
name|sockaddr
name|int_addr
decl_stmt|;
comment|/* address on this host */
union|union
block|{
name|struct
name|sockaddr
name|intu_broadaddr
decl_stmt|;
name|struct
name|sockaddr
name|intu_dstaddr
decl_stmt|;
block|}
name|int_intu
union|;
define|#
directive|define
name|int_broadaddr
value|int_intu.intu_broadaddr
comment|/* broadcast address */
define|#
directive|define
name|int_dstaddr
value|int_intu.intu_dstaddr
comment|/* other end of p-to-p link */
name|int
name|int_metric
decl_stmt|;
comment|/* init's routing entry */
name|int
name|int_flags
decl_stmt|;
comment|/* see below */
name|struct
name|ifdebug
name|int_input
decl_stmt|,
name|int_output
decl_stmt|;
comment|/* packet tracing stuff */
name|int
name|int_ipackets
decl_stmt|;
comment|/* input packets received */
name|int
name|int_opackets
decl_stmt|;
comment|/* output packets sent */
name|char
modifier|*
name|int_name
decl_stmt|;
comment|/* from kernel if structure */
name|u_short
name|int_transitions
decl_stmt|;
comment|/* times gone up-down */
comment|/* XXX IPX Specific entry */
struct|struct
name|sameq
block|{
name|struct
name|sameq
modifier|*
name|n
decl_stmt|;
comment|/* q of other pt-to-pt links */
name|struct
name|sameq
modifier|*
name|p
decl_stmt|;
comment|/* with same net # */
block|}
name|int_sq
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 0x1 to 0x10 are reused from the kernel's ifnet definitions,  * the others agree with the RTS_ flags defined elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|IFF_UP
value|0x1
end_define

begin_comment
comment|/* interface is up */
end_comment

begin_define
define|#
directive|define
name|IFF_BROADCAST
value|0x2
end_define

begin_comment
comment|/* broadcast address valid */
end_comment

begin_define
define|#
directive|define
name|IFF_DEBUG
value|0x4
end_define

begin_comment
comment|/* turn on debugging */
end_comment

begin_define
define|#
directive|define
name|IFF_ROUTE
value|0x8
end_define

begin_comment
comment|/* routing entry installed */
end_comment

begin_define
define|#
directive|define
name|IFF_POINTOPOINT
value|0x10
end_define

begin_comment
comment|/* interface is point-to-point link */
end_comment

begin_define
define|#
directive|define
name|IFF_PASSIVE
value|0x200000
end_define

begin_comment
comment|/* can't tell if up/down */
end_comment

begin_define
define|#
directive|define
name|IFF_INTERFACE
value|0x400000
end_define

begin_comment
comment|/* hardware interface */
end_comment

begin_define
define|#
directive|define
name|IFF_REMOTE
value|0x800000
end_define

begin_comment
comment|/* interface isn't on this machine */
end_comment

begin_function_decl
name|struct
name|interface
modifier|*
name|if_ifwithaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|interface
modifier|*
name|if_ifwithdstaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|interface
modifier|*
name|if_ifwithnet
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|interface
modifier|*
name|if_iflookup
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

