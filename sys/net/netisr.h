begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)netisr.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETISR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETISR_H_
end_define

begin_comment
comment|/*  * The networking code runs off software interrupts.  *  * You can switch into the network by doing splnet() and return by splx().  * The software interrupt level for the network is higher than the software  * level for the clock (so you can enter the network in routines called  * at timeout time).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|mtpr(SIRR, 12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Each ``pup-level-1'' input queue has a bit in a ``netisr'' status  * word which is used to de-multiplex a single software  * interrupt used for scheduling the network code to calls  * on the lowest level routine of each protocol.  */
end_comment

begin_define
define|#
directive|define
name|NETISR_RAW
value|0
end_define

begin_comment
comment|/* same as AF_UNSPEC */
end_comment

begin_define
define|#
directive|define
name|NETISR_IP
value|2
end_define

begin_comment
comment|/* same as AF_INET */
end_comment

begin_define
define|#
directive|define
name|NETISR_IMP
value|3
end_define

begin_comment
comment|/* same as AF_IMPLINK */
end_comment

begin_define
define|#
directive|define
name|NETISR_NS
value|6
end_define

begin_comment
comment|/* same as AF_NS */
end_comment

begin_define
define|#
directive|define
name|NETISR_ISO
value|7
end_define

begin_comment
comment|/* same as AF_ISO */
end_comment

begin_define
define|#
directive|define
name|NETISR_CCITT
value|10
end_define

begin_comment
comment|/* same as AF_CCITT */
end_comment

begin_define
define|#
directive|define
name|NETISR_ATALK
value|16
end_define

begin_comment
comment|/* same as AF_APPLETALK */
end_comment

begin_define
define|#
directive|define
name|NETISR_ARP
value|18
end_define

begin_comment
comment|/* same as AF_LINK */
end_comment

begin_define
define|#
directive|define
name|NETISR_IPX
value|23
end_define

begin_comment
comment|/* same as AF_IPX */
end_comment

begin_define
define|#
directive|define
name|NETISR_ISDN
value|26
end_define

begin_comment
comment|/* same as AF_E164 */
end_comment

begin_define
define|#
directive|define
name|NETISR_PPP
value|27
end_define

begin_comment
comment|/* PPP soft interrupt */
end_comment

begin_define
define|#
directive|define
name|NETISR_NATM
value|29
end_define

begin_comment
comment|/* same as AF_NATM */
end_comment

begin_define
define|#
directive|define
name|NETISR_NETGRAPH
value|31
end_define

begin_comment
comment|/* same as AF_NETGRAPH */
end_comment

begin_define
define|#
directive|define
name|schednetisr
parameter_list|(
name|anisr
parameter_list|)
value|{ netisr |= 1<<(anisr); setsoftnet(); }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
specifier|volatile
name|unsigned
name|int
name|netisr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scheduling bits for network */
end_comment

begin_typedef
typedef|typedef
name|void
name|netisr_t
name|__P
typedef|((
name|void
typedef|));
end_typedef

begin_struct
struct|struct
name|netisrtab
block|{
name|int
name|nit_num
decl_stmt|;
name|netisr_t
modifier|*
name|nit_isr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|register_netisr
name|__P
argument_list|(
operator|(
name|int
operator|,
name|netisr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|netisr_sysinit
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NETISR_SET
parameter_list|(
name|num
parameter_list|,
name|isr
parameter_list|)
define|\
value|static struct netisrtab nisr_##num = { num, isr }; \ 	SYSINIT(nisr_##num, SI_SUB_CPU, SI_ORDER_ANY, netisr_sysinit,&nisr_##num)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

