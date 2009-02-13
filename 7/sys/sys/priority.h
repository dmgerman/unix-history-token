begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994, Henrik Vestergaard Draboel  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Henrik Vestergaard Draboel.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PRIORITY_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PRIORITY_H_
end_define

begin_comment
comment|/*  * Process priority specifications.  */
end_comment

begin_comment
comment|/*  * Priority classes.  */
end_comment

begin_define
define|#
directive|define
name|PRI_ITHD
value|1
end_define

begin_comment
comment|/* Interrupt thread. */
end_comment

begin_define
define|#
directive|define
name|PRI_REALTIME
value|2
end_define

begin_comment
comment|/* Real time process. */
end_comment

begin_define
define|#
directive|define
name|PRI_TIMESHARE
value|3
end_define

begin_comment
comment|/* Time sharing process. */
end_comment

begin_define
define|#
directive|define
name|PRI_IDLE
value|4
end_define

begin_comment
comment|/* Idle process. */
end_comment

begin_comment
comment|/*  * PRI_FIFO is POSIX.1B SCHED_FIFO.  */
end_comment

begin_define
define|#
directive|define
name|PRI_FIFO_BIT
value|8
end_define

begin_define
define|#
directive|define
name|PRI_FIFO
value|(PRI_FIFO_BIT | PRI_REALTIME)
end_define

begin_define
define|#
directive|define
name|PRI_BASE
parameter_list|(
name|P
parameter_list|)
value|((P)& ~PRI_FIFO_BIT)
end_define

begin_define
define|#
directive|define
name|PRI_IS_REALTIME
parameter_list|(
name|P
parameter_list|)
value|(PRI_BASE(P) == PRI_REALTIME)
end_define

begin_define
define|#
directive|define
name|PRI_NEED_RR
parameter_list|(
name|P
parameter_list|)
value|((P) != PRI_FIFO)
end_define

begin_comment
comment|/*  * Priorities.  Note that with 64 run queues, differences less than 4 are  * insignificant.  */
end_comment

begin_comment
comment|/*  * Priorities range from 0 to 255, but differences of less then 4 (RQ_PPQ)  * are insignificant.  Ranges are as follows:  *  * Interrupt threads:		0 - 63  * Top half kernel threads:	64 - 127  * Realtime user threads:	128 - 159  * Time sharing user threads:	160 - 223  * Idle user threads:		224 - 255  *  * XXX If/When the specific interrupt thread and top half thread ranges  * disappear, a larger range can be used for user processes.  */
end_comment

begin_define
define|#
directive|define
name|PRI_MIN
value|(0)
end_define

begin_comment
comment|/* Highest priority. */
end_comment

begin_define
define|#
directive|define
name|PRI_MAX
value|(255)
end_define

begin_comment
comment|/* Lowest priority. */
end_comment

begin_define
define|#
directive|define
name|PRI_MIN_ITHD
value|(PRI_MIN)
end_define

begin_define
define|#
directive|define
name|PRI_MAX_ITHD
value|(PRI_MIN_KERN - 1)
end_define

begin_define
define|#
directive|define
name|PI_REALTIME
value|(PRI_MIN_ITHD + 0)
end_define

begin_define
define|#
directive|define
name|PI_AV
value|(PRI_MIN_ITHD + 4)
end_define

begin_define
define|#
directive|define
name|PI_TTYHIGH
value|(PRI_MIN_ITHD + 8)
end_define

begin_define
define|#
directive|define
name|PI_TAPE
value|(PRI_MIN_ITHD + 12)
end_define

begin_define
define|#
directive|define
name|PI_NET
value|(PRI_MIN_ITHD + 16)
end_define

begin_define
define|#
directive|define
name|PI_DISK
value|(PRI_MIN_ITHD + 20)
end_define

begin_define
define|#
directive|define
name|PI_TTYLOW
value|(PRI_MIN_ITHD + 24)
end_define

begin_define
define|#
directive|define
name|PI_DISKLOW
value|(PRI_MIN_ITHD + 28)
end_define

begin_define
define|#
directive|define
name|PI_DULL
value|(PRI_MIN_ITHD + 32)
end_define

begin_define
define|#
directive|define
name|PI_SOFT
value|(PRI_MIN_ITHD + 36)
end_define

begin_define
define|#
directive|define
name|PRI_MIN_KERN
value|(64)
end_define

begin_define
define|#
directive|define
name|PRI_MAX_KERN
value|(PRI_MIN_REALTIME - 1)
end_define

begin_define
define|#
directive|define
name|PSWP
value|(PRI_MIN_KERN + 0)
end_define

begin_define
define|#
directive|define
name|PVM
value|(PRI_MIN_KERN + 4)
end_define

begin_define
define|#
directive|define
name|PINOD
value|(PRI_MIN_KERN + 8)
end_define

begin_define
define|#
directive|define
name|PRIBIO
value|(PRI_MIN_KERN + 12)
end_define

begin_define
define|#
directive|define
name|PVFS
value|(PRI_MIN_KERN + 16)
end_define

begin_define
define|#
directive|define
name|PZERO
value|(PRI_MIN_KERN + 20)
end_define

begin_define
define|#
directive|define
name|PSOCK
value|(PRI_MIN_KERN + 24)
end_define

begin_define
define|#
directive|define
name|PWAIT
value|(PRI_MIN_KERN + 28)
end_define

begin_define
define|#
directive|define
name|PCONFIG
value|(PRI_MIN_KERN + 32)
end_define

begin_define
define|#
directive|define
name|PLOCK
value|(PRI_MIN_KERN + 36)
end_define

begin_define
define|#
directive|define
name|PPAUSE
value|(PRI_MIN_KERN + 40)
end_define

begin_define
define|#
directive|define
name|PRI_MIN_REALTIME
value|(128)
end_define

begin_define
define|#
directive|define
name|PRI_MAX_REALTIME
value|(PRI_MIN_TIMESHARE - 1)
end_define

begin_define
define|#
directive|define
name|PRI_MIN_TIMESHARE
value|(160)
end_define

begin_define
define|#
directive|define
name|PRI_MAX_TIMESHARE
value|(PRI_MIN_IDLE - 1)
end_define

begin_define
define|#
directive|define
name|PUSER
value|(PRI_MIN_TIMESHARE)
end_define

begin_define
define|#
directive|define
name|PRI_MIN_IDLE
value|(224)
end_define

begin_define
define|#
directive|define
name|PRI_MAX_IDLE
value|(PRI_MAX)
end_define

begin_struct
struct|struct
name|priority
block|{
name|u_char
name|pri_class
decl_stmt|;
comment|/* Scheduling class. */
name|u_char
name|pri_level
decl_stmt|;
comment|/* Normal priority level. */
name|u_char
name|pri_native
decl_stmt|;
comment|/* Priority before propogation. */
name|u_char
name|pri_user
decl_stmt|;
comment|/* User priority based on p_cpu and p_nice. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PRIORITY_H_ */
end_comment

end_unit

