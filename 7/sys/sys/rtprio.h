begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994, Henrik Vestergaard Draboel  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Henrik Vestergaard Draboel.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_RTPRIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_RTPRIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/priority.h>
end_include

begin_comment
comment|/*  * Process realtime-priority specifications to rtprio.  */
end_comment

begin_comment
comment|/* priority types.  Start at 1 to catch uninitialized fields. */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_REALTIME
value|PRI_REALTIME
end_define

begin_comment
comment|/* real time process */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_NORMAL
value|PRI_TIMESHARE
end_define

begin_comment
comment|/* time sharing process */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_IDLE
value|PRI_IDLE
end_define

begin_comment
comment|/* idle process */
end_comment

begin_comment
comment|/* RTP_PRIO_FIFO is POSIX.1B SCHED_FIFO.  */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_FIFO_BIT
value|PRI_FIFO_BIT
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_FIFO
value|PRI_FIFO
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_BASE
parameter_list|(
name|P
parameter_list|)
value|PRI_BASE(P)
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_IS_REALTIME
parameter_list|(
name|P
parameter_list|)
value|PRI_IS_REALTIME(P)
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_NEED_RR
parameter_list|(
name|P
parameter_list|)
value|PRI_NEED_RR(P)
end_define

begin_comment
comment|/* priority range */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_MIN
value|0
end_define

begin_comment
comment|/* Highest priority */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_MAX
value|31
end_define

begin_comment
comment|/* Lowest priority */
end_comment

begin_comment
comment|/*  * rtprio() syscall functions  */
end_comment

begin_define
define|#
directive|define
name|RTP_LOOKUP
value|0
end_define

begin_define
define|#
directive|define
name|RTP_SET
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Scheduling class information.  */
end_comment

begin_struct
struct|struct
name|rtprio
block|{
name|u_short
name|type
decl_stmt|;
comment|/* scheduling class */
name|u_short
name|prio
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|rtp_to_pri
parameter_list|(
name|struct
name|rtprio
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pri_to_rtp
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|rtprio
modifier|*
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

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|rtprio
parameter_list|(
name|int
parameter_list|,
name|pid_t
parameter_list|,
name|struct
name|rtprio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rtprio_thread
parameter_list|(
name|int
parameter_list|,
name|lwpid_t
parameter_list|,
name|struct
name|rtprio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_RTPRIO_H_ */
end_comment

end_unit

