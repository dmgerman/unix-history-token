begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Robert N. M. Watson  * Copyright (c) 2010-2011 Juniper Networks, Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson under contract  * to Juniper Networks, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETISR_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETISR_INTERNAL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_WANT_NETISR_INTERNAL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These definitions are private to the netisr implementation, but provided  * here for use by post-mortem crashdump analysis tools.  They should not be  * used in any other context as they can and will change.  Public definitions  * may be found in netisr.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_typedef
typedef|typedef
name|void
modifier|*
name|netisr_handler_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|netisr_m2flow_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|netisr_m2cpuid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|netisr_drainedcpu_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Each protocol is described by a struct netisr_proto, which holds all  * global per-protocol information.  This data structure is set up by  * netisr_register(), and derived from the public struct netisr_handler.  */
end_comment

begin_struct
struct|struct
name|netisr_proto
block|{
specifier|const
name|char
modifier|*
name|np_name
decl_stmt|;
comment|/* Character string protocol name. */
name|netisr_handler_t
modifier|*
name|np_handler
decl_stmt|;
comment|/* Protocol handler. */
name|netisr_m2flow_t
modifier|*
name|np_m2flow
decl_stmt|;
comment|/* Query flow for untagged packet. */
name|netisr_m2cpuid_t
modifier|*
name|np_m2cpuid
decl_stmt|;
comment|/* Query CPU to process packet on. */
name|netisr_drainedcpu_t
modifier|*
name|np_drainedcpu
decl_stmt|;
comment|/* Callback when drained a queue. */
name|u_int
name|np_qlimit
decl_stmt|;
comment|/* Maximum per-CPU queue depth. */
name|u_int
name|np_policy
decl_stmt|;
comment|/* Work placement policy. */
name|u_int
name|np_dispatch
decl_stmt|;
comment|/* Work dispatch policy. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NETISR_MAXPROT
value|16
end_define

begin_comment
comment|/* Compile-time limit. */
end_comment

begin_comment
comment|/*  * Protocol-specific work for each workstream is described by struct  * netisr_work.  Each work descriptor consists of an mbuf queue and  * statistics.  */
end_comment

begin_struct
struct|struct
name|netisr_work
block|{
comment|/* 	 * Packet queue, linked by m_nextpkt. 	 */
name|struct
name|mbuf
modifier|*
name|nw_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|nw_tail
decl_stmt|;
name|u_int
name|nw_len
decl_stmt|;
name|u_int
name|nw_qlimit
decl_stmt|;
name|u_int
name|nw_watermark
decl_stmt|;
comment|/* 	 * Statistics -- written unlocked, but mostly from curcpu. 	 */
name|u_int64_t
name|nw_dispatched
decl_stmt|;
comment|/* Number of direct dispatches. */
name|u_int64_t
name|nw_hybrid_dispatched
decl_stmt|;
comment|/* "" hybrid dispatches. */
name|u_int64_t
name|nw_qdrops
decl_stmt|;
comment|/* "" drops. */
name|u_int64_t
name|nw_queued
decl_stmt|;
comment|/* "" enqueues. */
name|u_int64_t
name|nw_handled
decl_stmt|;
comment|/* "" handled in worker. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Workstreams hold a queue of ordered work across each protocol, and are  * described by netisr_workstream.  Each workstream is associated with a  * worker thread, which in turn is pinned to a CPU.  Work associated with a  * workstream can be processd in other threads during direct dispatch;  * concurrent processing is prevented by the NWS_RUNNING flag, which  * indicates that a thread is already processing the work queue.  It is  * important to prevent a directly dispatched packet from "skipping ahead" of  * work already in the workstream queue.  */
end_comment

begin_struct
struct|struct
name|netisr_workstream
block|{
name|struct
name|intr_event
modifier|*
name|nws_intr_event
decl_stmt|;
comment|/* Handler for stream. */
name|void
modifier|*
name|nws_swi_cookie
decl_stmt|;
comment|/* swi(9) cookie for stream. */
name|struct
name|mtx
name|nws_mtx
decl_stmt|;
comment|/* Synchronize work. */
name|u_int
name|nws_cpu
decl_stmt|;
comment|/* CPU pinning. */
name|u_int
name|nws_flags
decl_stmt|;
comment|/* Wakeup flags. */
name|u_int
name|nws_pendingbits
decl_stmt|;
comment|/* Scheduled protocols. */
comment|/* 	 * Each protocol has per-workstream data. 	 */
name|struct
name|netisr_work
name|nws_work
index|[
name|NETISR_MAXPROT
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Per-workstream flags.  */
end_comment

begin_define
define|#
directive|define
name|NWS_RUNNING
value|0x00000001
end_define

begin_comment
comment|/* Currently running in a thread. */
end_comment

begin_define
define|#
directive|define
name|NWS_DISPATCHING
value|0x00000002
end_define

begin_comment
comment|/* Currently being direct-dispatched. */
end_comment

begin_define
define|#
directive|define
name|NWS_SCHEDULED
value|0x00000004
end_define

begin_comment
comment|/* Signal issued. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_NETISR_INTERNAL_H_ */
end_comment

end_unit

