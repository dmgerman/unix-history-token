begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ktrace.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_KTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_KTRACE_H_
end_define

begin_comment
comment|/*  * operations to ktrace system call  (KTROP(op))  */
end_comment

begin_define
define|#
directive|define
name|KTROP_SET
value|0
end_define

begin_comment
comment|/* set trace points */
end_comment

begin_define
define|#
directive|define
name|KTROP_CLEAR
value|1
end_define

begin_comment
comment|/* clear trace points */
end_comment

begin_define
define|#
directive|define
name|KTROP_CLEARFILE
value|2
end_define

begin_comment
comment|/* stop all tracing to file */
end_comment

begin_define
define|#
directive|define
name|KTROP
parameter_list|(
name|o
parameter_list|)
value|((o)&3)
end_define

begin_comment
comment|/* macro to extract operation */
end_comment

begin_comment
comment|/*  * flags (ORed in with operation)  */
end_comment

begin_define
define|#
directive|define
name|KTRFLAG_DESCEND
value|4
end_define

begin_comment
comment|/* perform op on all children too */
end_comment

begin_comment
comment|/*  * ktrace record header  */
end_comment

begin_struct
struct|struct
name|ktr_header
block|{
name|int
name|ktr_len
decl_stmt|;
comment|/* length of buf */
name|short
name|ktr_type
decl_stmt|;
comment|/* trace record type */
name|pid_t
name|ktr_pid
decl_stmt|;
comment|/* process id */
name|char
name|ktr_comm
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* command name */
name|struct
name|timeval
name|ktr_time
decl_stmt|;
comment|/* timestamp */
name|void
modifier|*
name|ktr_buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Test for kernel trace point (MP SAFE).  *  * KTRCHECK() just checks that the type is enabled and is only for  * internal use in the ktrace subsystem.  KTRPOINT() checks against  * ktrace recursion as well as checking that the type is enabled and  * is the public interface.  */
end_comment

begin_define
define|#
directive|define
name|KTRCHECK
parameter_list|(
name|td
parameter_list|,
name|type
parameter_list|)
value|((td)->td_proc->p_traceflag& (1<< type))
end_define

begin_define
define|#
directive|define
name|KTRPOINT
parameter_list|(
name|td
parameter_list|,
name|type
parameter_list|)
value|(KTRCHECK((td), (type))&& !(td)->td_inktrace)
end_define

begin_comment
comment|/*  * ktrace record types  */
end_comment

begin_comment
comment|/*  * KTR_SYSCALL - system call record  */
end_comment

begin_define
define|#
directive|define
name|KTR_SYSCALL
value|1
end_define

begin_struct
struct|struct
name|ktr_syscall
block|{
name|short
name|ktr_code
decl_stmt|;
comment|/* syscall number */
name|short
name|ktr_narg
decl_stmt|;
comment|/* number of arguments */
comment|/* 	 * followed by ktr_narg register_t 	 */
name|register_t
name|ktr_args
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_SYSRET - return from system call record  */
end_comment

begin_define
define|#
directive|define
name|KTR_SYSRET
value|2
end_define

begin_struct
struct|struct
name|ktr_sysret
block|{
name|short
name|ktr_code
decl_stmt|;
name|short
name|ktr_eosys
decl_stmt|;
name|int
name|ktr_error
decl_stmt|;
name|register_t
name|ktr_retval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_NAMEI - namei record  */
end_comment

begin_define
define|#
directive|define
name|KTR_NAMEI
value|3
end_define

begin_comment
comment|/* record contains pathname */
end_comment

begin_comment
comment|/*  * KTR_GENIO - trace generic process i/o  */
end_comment

begin_define
define|#
directive|define
name|KTR_GENIO
value|4
end_define

begin_struct
struct|struct
name|ktr_genio
block|{
name|int
name|ktr_fd
decl_stmt|;
name|enum
name|uio_rw
name|ktr_rw
decl_stmt|;
comment|/* 	 * followed by data successfully read/written 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_PSIG - trace processed signal  */
end_comment

begin_define
define|#
directive|define
name|KTR_PSIG
value|5
end_define

begin_struct
struct|struct
name|ktr_psig
block|{
name|int
name|signo
decl_stmt|;
name|sig_t
name|action
decl_stmt|;
name|int
name|code
decl_stmt|;
name|sigset_t
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_CSW - trace context switches  */
end_comment

begin_define
define|#
directive|define
name|KTR_CSW
value|6
end_define

begin_struct
struct|struct
name|ktr_csw
block|{
name|int
name|out
decl_stmt|;
comment|/* 1 if switch out, 0 if switch in */
name|int
name|user
decl_stmt|;
comment|/* 1 if usermode (ivcsw), 0 if kernel (vcsw) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_USER - data comming from userland  */
end_comment

begin_define
define|#
directive|define
name|KTR_USER_MAXLEN
value|2048
end_define

begin_comment
comment|/* maximum length of passed data */
end_comment

begin_define
define|#
directive|define
name|KTR_USER
value|7
end_define

begin_comment
comment|/*  * KTR_DROP - If this bit is set in ktr_type, then at least one event  * between the previous record and this record was dropped.  */
end_comment

begin_define
define|#
directive|define
name|KTR_DROP
value|0x8000
end_define

begin_comment
comment|/*  * kernel trace points (in p_traceflag)  */
end_comment

begin_define
define|#
directive|define
name|KTRFAC_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|KTRFAC_SYSCALL
value|(1<<KTR_SYSCALL)
end_define

begin_define
define|#
directive|define
name|KTRFAC_SYSRET
value|(1<<KTR_SYSRET)
end_define

begin_define
define|#
directive|define
name|KTRFAC_NAMEI
value|(1<<KTR_NAMEI)
end_define

begin_define
define|#
directive|define
name|KTRFAC_GENIO
value|(1<<KTR_GENIO)
end_define

begin_define
define|#
directive|define
name|KTRFAC_PSIG
value|(1<<KTR_PSIG)
end_define

begin_define
define|#
directive|define
name|KTRFAC_CSW
value|(1<<KTR_CSW)
end_define

begin_define
define|#
directive|define
name|KTRFAC_USER
value|(1<<KTR_USER)
end_define

begin_comment
comment|/*  * trace flags (also in p_traceflags)  */
end_comment

begin_define
define|#
directive|define
name|KTRFAC_ROOT
value|0x80000000
end_define

begin_comment
comment|/* root set this trace */
end_comment

begin_define
define|#
directive|define
name|KTRFAC_INHERIT
value|0x40000000
end_define

begin_comment
comment|/* pass trace flags to children */
end_comment

begin_define
define|#
directive|define
name|KTRFAC_DROP
value|0x20000000
end_define

begin_comment
comment|/* last event was dropped */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|ktrace_mtx
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ktrnamei
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ktrcsw
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ktrpsig
parameter_list|(
name|int
parameter_list|,
name|sig_t
parameter_list|,
name|sigset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ktrgenio
parameter_list|(
name|int
parameter_list|,
name|enum
name|uio_rw
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ktrsyscall
parameter_list|(
name|int
parameter_list|,
name|int
name|narg
parameter_list|,
name|register_t
name|args
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ktrsysret
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|register_t
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ktrace
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utrace
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

