begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Henrik Vestergaard Draboel  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by (name).  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Process realtime-priority specifications to rtprio.  */
end_comment

begin_comment
comment|/* priority types */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_REALTIME
value|0
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_IDLE
value|2
end_define

begin_comment
comment|/* RTP_PRIO_FIFO is POSIX.1B SCHED_FIFO.  */
end_comment

begin_define
define|#
directive|define
name|RTP_PRIO_FIFO_BIT
value|4
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_FIFO
value|(RTP_PRIO_REALTIME | RTP_PRIO_FIFO_BIT)
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_BASE
parameter_list|(
name|P
parameter_list|)
value|((P)& ~RTP_PRIO_FIFO_BIT)
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_IS_REALTIME
parameter_list|(
name|P
parameter_list|)
value|(RTP_PRIO_BASE(P) == RTP_PRIO_REALTIME)
end_define

begin_define
define|#
directive|define
name|RTP_PRIO_NEED_RR
parameter_list|(
name|P
parameter_list|)
value|((P) != RTP_PRIO_FIFO)
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

begin_struct
struct|struct
name|rtprio
block|{
name|u_short
name|type
decl_stmt|;
name|u_short
name|prio
decl_stmt|;
block|}
struct|;
end_struct

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

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|rtprio
name|__P
argument_list|(
operator|(
name|int
operator|,
name|pid_t
operator|,
expr|struct
name|rtprio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

