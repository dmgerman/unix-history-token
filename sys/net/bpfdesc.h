begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpfdesc.h	8.1 (Berkeley) 6/10/93  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_BPFDESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_BPFDESC_H_
end_define

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/*  * Descriptor associated with each open bpf file.  */
end_comment

begin_struct
struct|struct
name|bpf_d
block|{
name|struct
name|bpf_d
modifier|*
name|bd_next
decl_stmt|;
comment|/* Linked list of descriptors */
comment|/* 	 * Buffer slots: two mbuf clusters buffer the incoming packets. 	 *   The model has three slots.  Sbuf is always occupied. 	 *   sbuf (store) - Receive interrupt puts packets here. 	 *   hbuf (hold) - When sbuf is full, put cluster here and 	 *                 wakeup read (replace sbuf with fbuf). 	 *   fbuf (free) - When read is done, put cluster here. 	 * On receiving, if sbuf is full and fbuf is 0, packet is dropped. 	 */
name|caddr_t
name|bd_sbuf
decl_stmt|;
comment|/* store slot */
name|caddr_t
name|bd_hbuf
decl_stmt|;
comment|/* hold slot */
name|caddr_t
name|bd_fbuf
decl_stmt|;
comment|/* free slot */
name|int
name|bd_slen
decl_stmt|;
comment|/* current length of store buffer */
name|int
name|bd_hlen
decl_stmt|;
comment|/* current length of hold buffer */
name|int
name|bd_bufsize
decl_stmt|;
comment|/* absolute length of buffers */
name|struct
name|bpf_if
modifier|*
name|bd_bif
decl_stmt|;
comment|/* interface descriptor */
name|u_long
name|bd_rtout
decl_stmt|;
comment|/* Read timeout in 'ticks' */
name|struct
name|bpf_insn
modifier|*
name|bd_filter
decl_stmt|;
comment|/* filter code */
name|u_long
name|bd_rcount
decl_stmt|;
comment|/* number of packets received */
name|u_long
name|bd_dcount
decl_stmt|;
comment|/* number of packets dropped */
name|u_char
name|bd_promisc
decl_stmt|;
comment|/* true if listening promiscuously */
name|u_char
name|bd_state
decl_stmt|;
comment|/* idle, waiting, or timed out */
name|u_char
name|bd_immediate
decl_stmt|;
comment|/* true to return on packet arrival */
name|int
name|bd_hdrcmplt
decl_stmt|;
comment|/* false to fill in src lladdr automatically */
name|int
name|bd_seesent
decl_stmt|;
comment|/* true if bpf should see sent packets */
name|int
name|bd_async
decl_stmt|;
comment|/* non-zero if packet reception should generate signal */
name|int
name|bd_sig
decl_stmt|;
comment|/* signal to send upon packet reception */
name|struct
name|sigio
modifier|*
name|bd_sigio
decl_stmt|;
comment|/* information for async I/O */
if|#
directive|if
name|BSD
operator|<
literal|199103
name|u_char
name|bd_selcoll
decl_stmt|;
comment|/* true if selects collide */
name|int
name|bd_timedout
decl_stmt|;
name|struct
name|proc
modifier|*
name|bd_selproc
decl_stmt|;
comment|/* process that last selected us */
else|#
directive|else
name|u_char
name|bd_pad
decl_stmt|;
comment|/* explicit alignment */
name|struct
name|selinfo
name|bd_sel
decl_stmt|;
comment|/* bsd select info */
endif|#
directive|endif
name|struct
name|callout
name|bd_callout
decl_stmt|;
comment|/* for BPF timeouts with select */
block|}
struct|;
end_struct

begin_comment
comment|/* Values for bd_state */
end_comment

begin_define
define|#
directive|define
name|BPF_IDLE
value|0
end_define

begin_comment
comment|/* no select in progress */
end_comment

begin_define
define|#
directive|define
name|BPF_WAITING
value|1
end_define

begin_comment
comment|/* waiting for read timeout in select */
end_comment

begin_define
define|#
directive|define
name|BPF_TIMED_OUT
value|2
end_define

begin_comment
comment|/* read timeout has expired in select */
end_comment

begin_comment
comment|/*  * Descriptor associated with each attached hardware interface.  */
end_comment

begin_struct
struct|struct
name|bpf_if
block|{
name|struct
name|bpf_if
modifier|*
name|bif_next
decl_stmt|;
comment|/* list of all interfaces */
name|struct
name|bpf_d
modifier|*
name|bif_dlist
decl_stmt|;
comment|/* descriptor list */
name|u_int
name|bif_dlt
decl_stmt|;
comment|/* link layer type */
name|u_int
name|bif_hdrlen
decl_stmt|;
comment|/* length of header (with padding) */
name|struct
name|ifnet
modifier|*
name|bif_ifp
decl_stmt|;
comment|/* corresponding interface */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

