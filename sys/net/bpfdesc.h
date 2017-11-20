begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1990, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)bpfdesc.h	8.1 (Berkeley) 6/10/93  *  * $FreeBSD$  */
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
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/*  * Descriptor associated with each open bpf file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|zbuf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bpf_d
block|{
name|LIST_ENTRY
argument_list|(
argument|bpf_d
argument_list|)
name|bd_next
expr_stmt|;
comment|/* Linked list of descriptors */
comment|/* 	 * Buffer slots: two memory buffers store the incoming packets. 	 *   The model has three slots.  Sbuf is always occupied. 	 *   sbuf (store) - Receive interrupt puts packets here. 	 *   hbuf (hold) - When sbuf is full, put buffer here and 	 *                 wakeup read (replace sbuf with fbuf). 	 *   fbuf (free) - When read is done, put buffer here. 	 * On receiving, if sbuf is full and fbuf is 0, packet is dropped. 	 */
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
name|bd_hbuf_in_use
decl_stmt|;
comment|/* don't rotate buffers */
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
name|bd_rfilter
decl_stmt|;
comment|/* read filter code */
name|struct
name|bpf_insn
modifier|*
name|bd_wfilter
decl_stmt|;
comment|/* write filter code */
name|void
modifier|*
name|bd_bfilter
decl_stmt|;
comment|/* binary filter code */
name|u_int64_t
name|bd_rcount
decl_stmt|;
comment|/* number of packets received */
name|u_int64_t
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
name|u_char
name|bd_writer
decl_stmt|;
comment|/* non-zero if d is writer-only */
name|int
name|bd_hdrcmplt
decl_stmt|;
comment|/* false to fill in src lladdr automatically */
name|int
name|bd_direction
decl_stmt|;
comment|/* select packet direction */
name|int
name|bd_tstamp
decl_stmt|;
comment|/* select time stamping function */
name|int
name|bd_feedback
decl_stmt|;
comment|/* true to feed back sent packets */
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
name|struct
name|selinfo
name|bd_sel
decl_stmt|;
comment|/* bsd select info */
name|struct
name|mtx
name|bd_lock
decl_stmt|;
comment|/* per-descriptor lock */
name|struct
name|callout
name|bd_callout
decl_stmt|;
comment|/* for BPF timeouts with select */
name|struct
name|label
modifier|*
name|bd_label
decl_stmt|;
comment|/* MAC label for descriptor */
name|u_int64_t
name|bd_fcount
decl_stmt|;
comment|/* number of packets which matched filter */
name|pid_t
name|bd_pid
decl_stmt|;
comment|/* PID which created descriptor */
name|int
name|bd_locked
decl_stmt|;
comment|/* true if descriptor is locked */
name|u_int
name|bd_bufmode
decl_stmt|;
comment|/* Current buffer mode. */
name|u_int64_t
name|bd_wcount
decl_stmt|;
comment|/* number of packets written */
name|u_int64_t
name|bd_wfcount
decl_stmt|;
comment|/* number of packets that matched write filter */
name|u_int64_t
name|bd_wdcount
decl_stmt|;
comment|/* number of packets dropped during a write */
name|u_int64_t
name|bd_zcopy
decl_stmt|;
comment|/* number of zero copy operations */
name|u_char
name|bd_compat32
decl_stmt|;
comment|/* 32-bit stream on LP64 system */
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

begin_define
define|#
directive|define
name|BPFD_LOCK
parameter_list|(
name|bd
parameter_list|)
value|mtx_lock(&(bd)->bd_lock)
end_define

begin_define
define|#
directive|define
name|BPFD_UNLOCK
parameter_list|(
name|bd
parameter_list|)
value|mtx_unlock(&(bd)->bd_lock)
end_define

begin_define
define|#
directive|define
name|BPFD_LOCK_ASSERT
parameter_list|(
name|bd
parameter_list|)
value|mtx_assert(&(bd)->bd_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BPF_PID_REFRESH
parameter_list|(
name|bd
parameter_list|,
name|td
parameter_list|)
value|(bd)->bd_pid = (td)->td_proc->p_pid
end_define

begin_define
define|#
directive|define
name|BPF_PID_REFRESH_CUR
parameter_list|(
name|bd
parameter_list|)
value|(bd)->bd_pid = curthread->td_proc->p_pid
end_define

begin_define
define|#
directive|define
name|BPF_LOCK
parameter_list|()
value|mtx_lock(&bpf_mtx)
end_define

begin_define
define|#
directive|define
name|BPF_UNLOCK
parameter_list|()
value|mtx_unlock(&bpf_mtx)
end_define

begin_define
define|#
directive|define
name|BPF_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&bpf_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * External representation of the bpf descriptor  */
end_comment

begin_struct
struct|struct
name|xbpf_d
block|{
name|u_int
name|bd_structsize
decl_stmt|;
comment|/* Size of this structure. */
name|u_char
name|bd_promisc
decl_stmt|;
name|u_char
name|bd_immediate
decl_stmt|;
name|u_char
name|__bd_pad
index|[
literal|6
index|]
decl_stmt|;
name|int
name|bd_hdrcmplt
decl_stmt|;
name|int
name|bd_direction
decl_stmt|;
name|int
name|bd_feedback
decl_stmt|;
name|int
name|bd_async
decl_stmt|;
name|u_int64_t
name|bd_rcount
decl_stmt|;
name|u_int64_t
name|bd_dcount
decl_stmt|;
name|u_int64_t
name|bd_fcount
decl_stmt|;
name|int
name|bd_sig
decl_stmt|;
name|int
name|bd_slen
decl_stmt|;
name|int
name|bd_hlen
decl_stmt|;
name|int
name|bd_bufsize
decl_stmt|;
name|pid_t
name|bd_pid
decl_stmt|;
name|char
name|bd_ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|int
name|bd_locked
decl_stmt|;
name|u_int64_t
name|bd_wcount
decl_stmt|;
name|u_int64_t
name|bd_wfcount
decl_stmt|;
name|u_int64_t
name|bd_wdcount
decl_stmt|;
name|u_int64_t
name|bd_zcopy
decl_stmt|;
name|int
name|bd_bufmode
decl_stmt|;
comment|/* 	 * Allocate 4 64 bit unsigned integers for future expansion so we do 	 * not have to worry about breaking the ABI. 	 */
name|u_int64_t
name|bd_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BPFIF_RLOCK
parameter_list|(
name|bif
parameter_list|)
value|rw_rlock(&(bif)->bif_lock)
end_define

begin_define
define|#
directive|define
name|BPFIF_RUNLOCK
parameter_list|(
name|bif
parameter_list|)
value|rw_runlock(&(bif)->bif_lock)
end_define

begin_define
define|#
directive|define
name|BPFIF_WLOCK
parameter_list|(
name|bif
parameter_list|)
value|rw_wlock(&(bif)->bif_lock)
end_define

begin_define
define|#
directive|define
name|BPFIF_WUNLOCK
parameter_list|(
name|bif
parameter_list|)
value|rw_wunlock(&(bif)->bif_lock)
end_define

begin_define
define|#
directive|define
name|BPFIF_FLAG_DYING
value|1
end_define

begin_comment
comment|/* Reject new bpf consumers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

