begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*/* 	$Id$	 */
end_comment

begin_comment
comment|//#ifndef lint
end_comment

begin_comment
comment|//static char vcid[] = "$Id$";
end_comment

begin_comment
comment|//#endif /* lint */
end_comment

begin_comment
comment|/**  * @file alias_sctp.h  * Copyright (c) 2008, Centre for Advanced Internet Architectures  * Swinburne University of Technology, Melbourne, Australia  * (CRICOS number 00111D).  *   * Alias_sctp forms part of the libalias kernel module to handle   * Network Address Translation (NAT) for the SCTP protocol.  *  *  This software was developed by David A. Hayes  *  with leadership and advice from Jason But  *  * The design is outlined in CAIA technical report number  080618A  * (D. Hayes and J. But, "Alias_sctp Version 0.1: SCTP NAT implementation in IPFW")  *  * Development is part of the CAIA SONATA project,  * proposed by Jason But and Grenville Armitage:  * http://caia.swin.edu.au/urp/sonata/  *  *   * This project has been made possible in part by a grant from  * the Cisco University Research Program Fund at Community  * Foundation Silicon Valley.  *  *  *  All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The names of the authors, the "Centre for Advanced Internet Architectures"  *     and "Swinburne University of Technology" may not be used to endorse  *     or promote products derived from this software without specific  *     prior written permission.  *   *  THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS "AS IS" AND  *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *  SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_SCTP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_SCTP_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifdef	_KERNEL
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_comment
comment|/**  * These are defined in sctp_os_bsd.h, but it can't be included due to its local file  * inclusion, so I'm defining them here.  *   */
end_comment

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/* The packed define for 64 bit platforms */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_PACKED
end_ifndef

begin_define
define|#
directive|define
name|SCTP_PACKED
value|__attribute__((packed))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#ifndef SCTP_PACKED
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|SCTP_UNUSED
value|__attribute__((unused))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#ifndef SCTP_UNUSED
end_comment

begin_include
include|#
directive|include
file|<netinet/sctp.h>
end_include

begin_comment
comment|//#include<netinet/sctp_os_bsd.h> --might be needed later for mbuf stuff
end_comment

begin_include
include|#
directive|include
file|<netinet/sctp_header.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#ifdef _KERNEL
end_comment

begin_define
define|#
directive|define
name|LINK_SCTP
value|IPPROTO_SCTP
end_define

begin_define
define|#
directive|define
name|SN_TO_LOCAL
value|0
end_define

begin_comment
comment|/**< packet traveling from global to local */
end_comment

begin_define
define|#
directive|define
name|SN_TO_GLOBAL
value|1
end_define

begin_comment
comment|/**< packet traveling from local to global */
end_comment

begin_define
define|#
directive|define
name|SN_TO_NODIR
value|99
end_define

begin_comment
comment|/**< used where direction is not important */
end_comment

begin_define
define|#
directive|define
name|SN_NAT_PKT
value|0x0000
end_define

begin_comment
comment|/**< Network Address Translate packet */
end_comment

begin_define
define|#
directive|define
name|SN_DROP_PKT
value|0x0001
end_define

begin_comment
comment|/**< drop packet (don't forward it) */
end_comment

begin_define
define|#
directive|define
name|SN_PROCESSING_ERROR
value|0x0003
end_define

begin_comment
comment|/**< Packet processing error */
end_comment

begin_define
define|#
directive|define
name|SN_REPLY_ABORT
value|0x0010
end_define

begin_comment
comment|/**< Reply with ABORT to sender (don't forward it) */
end_comment

begin_define
define|#
directive|define
name|SN_SEND_ABORT
value|0x0020
end_define

begin_comment
comment|/**< Send ABORT to destination */
end_comment

begin_define
define|#
directive|define
name|SN_TX_ABORT
value|0x0030
end_define

begin_comment
comment|/**< mask for transmitting abort */
end_comment

begin_define
define|#
directive|define
name|SN_REFLECT_ERROR
value|0x0100
end_define

begin_comment
comment|/**< Reply with ERROR to sender on OOTB packet Tbit set */
end_comment

begin_define
define|#
directive|define
name|SN_REPLY_ERROR
value|0x0200
end_define

begin_comment
comment|/**< Reply with ERROR to sender on ASCONF clash */
end_comment

begin_define
define|#
directive|define
name|SN_TX_ERROR
value|0x0300
end_define

begin_comment
comment|/**< mask for transmitting error */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_RESPOND
value|0x1000
end_define

begin_comment
comment|/**< Signal to libalias that there is a response packet to send */
end_comment

begin_comment
comment|/*  * Data structures  */
end_comment

begin_comment
comment|/**  * @brief sctp association information  *  * Structure that contains information about a particular sctp association  * currently under Network Address Translation.  * Information is stored in network byte order (as is libalias)***  */
end_comment

begin_struct
struct|struct
name|sctp_nat_assoc
block|{
name|uint32_t
name|l_vtag
decl_stmt|;
comment|/**< local side verification tag */
name|uint16_t
name|l_port
decl_stmt|;
comment|/**< local side port number */
name|uint32_t
name|g_vtag
decl_stmt|;
comment|/**< global side verification tag */
name|uint16_t
name|g_port
decl_stmt|;
comment|/**< global side port number */
name|struct
name|in_addr
name|l_addr
decl_stmt|;
comment|/**< local ip address */
name|struct
name|in_addr
name|a_addr
decl_stmt|;
comment|/**< alias ip address */
name|int
name|state
decl_stmt|;
comment|/**< current state of NAT association */
name|int
name|TableRegister
decl_stmt|;
comment|/**< stores which look up tables association is registered in */
name|int
name|exp
decl_stmt|;
comment|/**< timer expiration in seconds from uptime */
name|int
name|exp_loc
decl_stmt|;
comment|/**< current location in timer_Q */
name|int
name|num_Gaddr
decl_stmt|;
comment|/**< number of global IP addresses in the list */
name|LIST_HEAD
argument_list|(
argument|sctpGlobalAddresshead
argument_list|,
argument|sctp_GlobalAddress
argument_list|)
name|Gaddr
expr_stmt|;
comment|/**< List of global addresses */
name|LIST_ENTRY
argument_list|(
argument|sctp_nat_assoc
argument_list|)
name|list_L
expr_stmt|;
comment|/**< Linked list of pointers for Local table*/
name|LIST_ENTRY
argument_list|(
argument|sctp_nat_assoc
argument_list|)
name|list_G
expr_stmt|;
comment|/**< Linked list of pointers for Global table */
name|LIST_ENTRY
argument_list|(
argument|sctp_nat_assoc
argument_list|)
name|timer_Q
expr_stmt|;
comment|/**< Linked list of pointers for timer Q */
comment|//Using libalias locking
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sctp_GlobalAddress
block|{
name|struct
name|in_addr
name|g_addr
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|sctp_GlobalAddress
argument_list|)
name|list_Gaddr
expr_stmt|;
comment|/**< Linked list of pointers for Global table */
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief SCTP chunk of interest  *  * The only chunks whose contents are of any interest are the INIT and ASCONF_AddIP  */
end_comment

begin_union
union|union
name|sctpChunkOfInt
block|{
name|struct
name|sctp_init
modifier|*
name|Init
decl_stmt|;
comment|/**< Pointer to Init Chunk */
name|struct
name|sctp_init_ack
modifier|*
name|InitAck
decl_stmt|;
comment|/**< Pointer to Init Chunk */
name|struct
name|sctp_paramhdr
modifier|*
name|Asconf
decl_stmt|;
comment|/**< Pointer to ASCONF chunk */
block|}
union|;
end_union

begin_comment
comment|/**  * @brief SCTP message  *   * Structure containing the relevant information from the SCTP message  */
end_comment

begin_struct
struct|struct
name|sctp_nat_msg
block|{
name|uint16_t
name|msg
decl_stmt|;
comment|/**< one of the key messages defined above */
ifdef|#
directive|ifdef
name|INET6
comment|//  struct ip6_hdr *ip_hdr;	/**< pointer to ip packet header */ /*no inet6 support yet*/
else|#
directive|else
name|struct
name|ip
modifier|*
name|ip_hdr
decl_stmt|;
comment|/**< pointer to ip packet header */
endif|#
directive|endif
comment|//#ifdef INET6
name|struct
name|sctphdr
modifier|*
name|sctp_hdr
decl_stmt|;
comment|/**< pointer to sctp common header */
name|union
name|sctpChunkOfInt
name|sctpchnk
decl_stmt|;
comment|/**< union of pointers to the chunk of interest */
name|int
name|chunk_length
decl_stmt|;
comment|/**< length of chunk of interest */
block|}
struct|;
end_struct

begin_comment
comment|/**  * @brief sctp nat timer queue structure  *   */
end_comment

begin_struct
struct|struct
name|sctp_nat_timer
block|{
name|int
name|loc_time
decl_stmt|;
comment|/**< time in seconds for the current location in the queue */
name|int
name|cur_loc
decl_stmt|;
comment|/**< index of the current location in the circular queue */
name|LIST_HEAD
argument_list|(
name|sctpTimerQ
argument_list|,
name|sctp_nat_assoc
argument_list|)
operator|*
name|TimerQ
expr_stmt|;
comment|/**< List of associations at this position in the timer Q */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//#ifndef _ALIAS_SCTP_H
end_comment

end_unit

