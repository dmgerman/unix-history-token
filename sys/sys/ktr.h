begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: ktr.h,v 1.10.2.7 2000/03/16 21:44:42 cp Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Wraparound kernel trace buffer support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KTR_H_
end_define

begin_comment
comment|/*  * Hack around due to egcs-1.1.2 not knowing what __func__ is.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|==
literal|91
end_if

begin_comment
comment|/* egcs 1.1.2 */
end_comment

begin_define
define|#
directive|define
name|__func__
value|__FUNCTION__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Trace classes  */
end_comment

begin_define
define|#
directive|define
name|KTR_GEN
value|0x00000001
end_define

begin_comment
comment|/* General (TR) */
end_comment

begin_define
define|#
directive|define
name|KTR_NET
value|0x00000002
end_define

begin_comment
comment|/* Network */
end_comment

begin_define
define|#
directive|define
name|KTR_DEV
value|0x00000004
end_define

begin_comment
comment|/* Device driver */
end_comment

begin_define
define|#
directive|define
name|KTR_LOCK
value|0x00000008
end_define

begin_comment
comment|/* MP locking */
end_comment

begin_define
define|#
directive|define
name|KTR_SMP
value|0x00000010
end_define

begin_comment
comment|/* MP general */
end_comment

begin_define
define|#
directive|define
name|KTR_FS
value|0x00000020
end_define

begin_comment
comment|/* Filesystem */
end_comment

begin_define
define|#
directive|define
name|KTR_PMAP
value|0x00000040
end_define

begin_comment
comment|/* Pmap tracing */
end_comment

begin_define
define|#
directive|define
name|KTR_MALLOC
value|0x00000080
end_define

begin_comment
comment|/* Malloc tracing */
end_comment

begin_define
define|#
directive|define
name|KTR_TRAP
value|0x00000100
end_define

begin_comment
comment|/* Trap processing */
end_comment

begin_define
define|#
directive|define
name|KTR_INTR
value|0x00000200
end_define

begin_comment
comment|/* Interrupt tracing */
end_comment

begin_define
define|#
directive|define
name|KTR_SIG
value|0x00000400
end_define

begin_comment
comment|/* Signal processing */
end_comment

begin_define
define|#
directive|define
name|KTR_CLK
value|0x00000800
end_define

begin_comment
comment|/* hardclock verbose */
end_comment

begin_define
define|#
directive|define
name|KTR_PROC
value|0x00001000
end_define

begin_comment
comment|/* Process scheduling */
end_comment

begin_define
define|#
directive|define
name|KTR_SYSC
value|0x00002000
end_define

begin_comment
comment|/* System call */
end_comment

begin_define
define|#
directive|define
name|KTR_INIT
value|0x00004000
end_define

begin_comment
comment|/* System initialization */
end_comment

begin_define
define|#
directive|define
name|KTR_KGDB
value|0x00008000
end_define

begin_comment
comment|/* Trace kgdb internals */
end_comment

begin_define
define|#
directive|define
name|KTR_IO
value|0x00010000
end_define

begin_comment
comment|/* Upper I/O  */
end_comment

begin_define
define|#
directive|define
name|KTR_LOCKMGR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|KTR_NFS
value|0x00040000
end_define

begin_comment
comment|/* The obvious */
end_comment

begin_define
define|#
directive|define
name|KTR_VOP
value|0x00080000
end_define

begin_comment
comment|/* The obvious */
end_comment

begin_define
define|#
directive|define
name|KTR_VM
value|0x00100000
end_define

begin_comment
comment|/* The virtual memory system */
end_comment

begin_define
define|#
directive|define
name|KTR_WITNESS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|KTR_RUNQ
value|0x00400000
end_define

begin_comment
comment|/* Run queue */
end_comment

begin_define
define|#
directive|define
name|KTR_ALL
value|0x007fffff
end_define

begin_comment
comment|/*  * Trace classes which can be assigned to particular use at compile time  * These must remain in high 22 as some assembly code counts on it  */
end_comment

begin_define
define|#
directive|define
name|KTR_CT1
value|0x010000000
end_define

begin_define
define|#
directive|define
name|KTR_CT2
value|0x020000000
end_define

begin_define
define|#
directive|define
name|KTR_CT3
value|0x040000000
end_define

begin_define
define|#
directive|define
name|KTR_CT4
value|0x080000000
end_define

begin_define
define|#
directive|define
name|KTR_CT5
value|0x100000000
end_define

begin_define
define|#
directive|define
name|KTR_CT6
value|0x200000000
end_define

begin_define
define|#
directive|define
name|KTR_CT7
value|0x400000000
end_define

begin_define
define|#
directive|define
name|KTR_CT8
value|0x800000000
end_define

begin_comment
comment|/* Trace classes to compile in */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KTR_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|KTR_COMPILE
value|(KTR_GEN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Version number for ktr_entry struct.  Increment this when you break binary  * compatibility.  */
end_comment

begin_define
define|#
directive|define
name|KTR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|KTR_PARMS
value|6
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|ktr_entry
block|{
name|u_int64_t
name|ktr_timestamp
decl_stmt|;
name|int
name|ktr_cpu
decl_stmt|;
name|int
name|ktr_line
decl_stmt|;
specifier|const
name|char
modifier|*
name|ktr_file
decl_stmt|;
specifier|const
name|char
modifier|*
name|ktr_desc
decl_stmt|;
name|u_long
name|ktr_parms
index|[
name|KTR_PARMS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|ktr_cpumask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ktr_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ktr_entries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ktr_verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|ktr_idx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ktr_entry
name|ktr_buf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KTR
end_ifdef

begin_function_decl
name|void
name|ktr_tracepoint
parameter_list|(
name|u_int
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|u_long
name|arg1
parameter_list|,
name|u_long
name|arg2
parameter_list|,
name|u_long
name|arg3
parameter_list|,
name|u_long
name|arg4
parameter_list|,
name|u_long
name|arg5
parameter_list|,
name|u_long
name|arg6
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CTR6
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|do {			\ 	if (KTR_COMPILE& (m))						\ 		ktr_tracepoint((m), __FILE__, __LINE__, format,		\ 		    (u_long)p1, (u_long)p2, (u_long)p3, (u_long)p4,	\ 		    (u_long)p5, (u_long)p6);				\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|CTR0
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|)
value|CTR6(m, format, 0, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR1
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|)
value|CTR6(m, format, p1, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR2
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|CTR6(m, format, p1, p2, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR3
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|CTR6(m, format, p1, p2, p3, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR4
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|CTR6(m, format, p1, p2, p3, p4, 0, 0)
end_define

begin_define
define|#
directive|define
name|CTR5
parameter_list|(
name|m
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|CTR6(m, format, p1, p2, p3, p4, p5, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* KTR */
end_comment

begin_undef
undef|#
directive|undef
name|KTR_COMPILE
end_undef

begin_define
define|#
directive|define
name|KTR_COMPILE
value|0
end_define

begin_define
define|#
directive|define
name|CTR0
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CTR1
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CTR2
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CTR3
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CTR4
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CTR5
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CTR6
parameter_list|(
name|m
parameter_list|,
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KTR */
end_comment

begin_define
define|#
directive|define
name|TR0
parameter_list|(
name|d
parameter_list|)
value|CTR0(KTR_GEN, d)
end_define

begin_define
define|#
directive|define
name|TR1
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|)
value|CTR1(KTR_GEN, d, p1)
end_define

begin_define
define|#
directive|define
name|TR2
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|CTR2(KTR_GEN, d, p1, p2)
end_define

begin_define
define|#
directive|define
name|TR3
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|CTR3(KTR_GEN, d, p1, p2, p3)
end_define

begin_define
define|#
directive|define
name|TR4
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|CTR4(KTR_GEN, d, p1, p2, p3, p4)
end_define

begin_define
define|#
directive|define
name|TR5
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|CTR5(KTR_GEN, d, p1, p2, p3, p4, p5)
end_define

begin_define
define|#
directive|define
name|TR6
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|CTR6(KTR_GEN, d, p1, p2, p3, p4, p5, p6)
end_define

begin_comment
comment|/*  * Trace initialization events, similar to CTR with KTR_INIT, but  * completely ifdef'ed out if KTR_INIT isn't in KTR_COMPILE (to  * save string space, the compiler doesn't optimize out strings  * for the conditional ones above).  */
end_comment

begin_if
if|#
directive|if
operator|(
name|KTR_COMPILE
operator|&
name|KTR_INIT
operator|)
operator|!=
literal|0
end_if

begin_define
define|#
directive|define
name|ITR0
parameter_list|(
name|d
parameter_list|)
value|CTR0(KTR_INIT, d)
end_define

begin_define
define|#
directive|define
name|ITR1
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|)
value|CTR1(KTR_INIT, d, p1)
end_define

begin_define
define|#
directive|define
name|ITR2
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|CTR2(KTR_INIT, d, p1, p2)
end_define

begin_define
define|#
directive|define
name|ITR3
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|CTR3(KTR_INIT, d, p1, p2, p3)
end_define

begin_define
define|#
directive|define
name|ITR4
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|CTR4(KTR_INIT, d, p1, p2, p3, p4)
end_define

begin_define
define|#
directive|define
name|ITR5
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|CTR5(KTR_INIT, d, p1, p2, p3, p4, p5)
end_define

begin_define
define|#
directive|define
name|ITR6
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|CTR6(KTR_INIT, d, p1, p2, p3, p4, p5, p6)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ITR0
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR1
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR2
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR3
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR4
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR5
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ITR6
parameter_list|(
name|d
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_KTR_H_ */
end_comment

end_unit

