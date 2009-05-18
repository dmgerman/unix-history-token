begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)netisr.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
comment|/*  * The netisr (network interrupt service routine) provides a deferred  * execution evironment in which (generally inbound) network processing can  * take place.  Protocols register handlers and, optionally, packet queues;  * when packets are delivered to the queue, the protocol handler will be  * executed directly, or via deferred dispatch depending on the  * circumstances.  *  * Historically, this was implemented by the BSD software ISR facility; it is  * now implemented via a software ithread (SWI).  */
end_comment

begin_define
define|#
directive|define
name|NETISR_POLL
value|0
end_define

begin_comment
comment|/* polling callback, must be first */
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
name|NETISR_IGMP
value|3
end_define

begin_comment
comment|/* IGMPv3 output queue */
end_comment

begin_define
define|#
directive|define
name|NETISR_ROUTE
value|14
end_define

begin_comment
comment|/* routing socket */
end_comment

begin_define
define|#
directive|define
name|NETISR_AARP
value|15
end_define

begin_comment
comment|/* Appletalk ARP */
end_comment

begin_define
define|#
directive|define
name|NETISR_ATALK2
value|16
end_define

begin_comment
comment|/* Appletalk phase 2 */
end_comment

begin_define
define|#
directive|define
name|NETISR_ATALK1
value|17
end_define

begin_comment
comment|/* Appletalk phase 1 */
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
name|NETISR_IPV6
value|27
end_define

begin_define
define|#
directive|define
name|NETISR_NATM
value|28
end_define

begin_define
define|#
directive|define
name|NETISR_POLLMORE
value|31
end_define

begin_comment
comment|/* polling callback, must be last */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|legacy_setsoftnet
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_define
define|#
directive|define
name|schednetisr
parameter_list|(
name|anisr
parameter_list|)
value|do {						\ 	atomic_set_rel_int(&netisr, 1<< (anisr));			\ 	legacy_setsoftnet();						\ } while (0)
end_define

begin_comment
comment|/* used to atomically schedule multiple netisrs */
end_comment

begin_define
define|#
directive|define
name|schednetisrbits
parameter_list|(
name|isrbits
parameter_list|)
value|do {					\ 	atomic_set_rel_int(&netisr, isrbits);				\ 	legacy_setsoftnet();						\ } while (0)
end_define

begin_struct_decl
struct_decl|struct
name|ifqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|netisr_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|netisr_dispatch
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netisr_queue
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_register
parameter_list|(
name|int
parameter_list|,
name|netisr_t
modifier|*
parameter_list|,
name|struct
name|ifqueue
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netisr_unregister
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

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

