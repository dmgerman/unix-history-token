begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ptrace.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PTRACE_H_
end_define

begin_define
define|#
directive|define
name|PT_TRACE_ME
value|0
end_define

begin_comment
comment|/* child declares it's being traced */
end_comment

begin_define
define|#
directive|define
name|PT_READ_I
value|1
end_define

begin_comment
comment|/* read word in child's I space */
end_comment

begin_define
define|#
directive|define
name|PT_READ_D
value|2
end_define

begin_comment
comment|/* read word in child's D space */
end_comment

begin_comment
comment|/* was	PT_READ_U	3	 * read word in child's user structure */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_I
value|4
end_define

begin_comment
comment|/* write word in child's I space */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_D
value|5
end_define

begin_comment
comment|/* write word in child's D space */
end_comment

begin_comment
comment|/* was	PT_WRITE_U	6	 * write word in child's user structure */
end_comment

begin_define
define|#
directive|define
name|PT_CONTINUE
value|7
end_define

begin_comment
comment|/* continue the child */
end_comment

begin_define
define|#
directive|define
name|PT_KILL
value|8
end_define

begin_comment
comment|/* kill the child process */
end_comment

begin_define
define|#
directive|define
name|PT_STEP
value|9
end_define

begin_comment
comment|/* single step the child */
end_comment

begin_define
define|#
directive|define
name|PT_ATTACH
value|10
end_define

begin_comment
comment|/* trace some running process */
end_comment

begin_define
define|#
directive|define
name|PT_DETACH
value|11
end_define

begin_comment
comment|/* stop tracing a process */
end_comment

begin_define
define|#
directive|define
name|PT_IO
value|12
end_define

begin_comment
comment|/* do I/O to/from stopped process. */
end_comment

begin_define
define|#
directive|define
name|PT_GETREGS
value|33
end_define

begin_comment
comment|/* get general-purpose registers */
end_comment

begin_define
define|#
directive|define
name|PT_SETREGS
value|34
end_define

begin_comment
comment|/* set general-purpose registers */
end_comment

begin_define
define|#
directive|define
name|PT_GETFPREGS
value|35
end_define

begin_comment
comment|/* get floating-point registers */
end_comment

begin_define
define|#
directive|define
name|PT_SETFPREGS
value|36
end_define

begin_comment
comment|/* set floating-point registers */
end_comment

begin_define
define|#
directive|define
name|PT_GETDBREGS
value|37
end_define

begin_comment
comment|/* get debugging registers */
end_comment

begin_define
define|#
directive|define
name|PT_SETDBREGS
value|38
end_define

begin_comment
comment|/* set debugging registers */
end_comment

begin_define
define|#
directive|define
name|PT_FIRSTMACH
value|64
end_define

begin_comment
comment|/* for machine-specific requests */
end_comment

begin_include
include|#
directive|include
file|<machine/ptrace.h>
end_include

begin_comment
comment|/* machine-specific requests, if any */
end_comment

begin_struct
struct|struct
name|ptrace_io_desc
block|{
name|int
name|piod_op
decl_stmt|;
comment|/* I/O operation */
name|void
modifier|*
name|piod_offs
decl_stmt|;
comment|/* child offset */
name|void
modifier|*
name|piod_addr
decl_stmt|;
comment|/* parent offset */
name|size_t
name|piod_len
decl_stmt|;
comment|/* request length */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Operations in piod_op.  */
end_comment

begin_define
define|#
directive|define
name|PIOD_READ_D
value|1
end_define

begin_comment
comment|/* Read from D space */
end_comment

begin_define
define|#
directive|define
name|PIOD_WRITE_D
value|2
end_define

begin_comment
comment|/* Write to D space */
end_comment

begin_define
define|#
directive|define
name|PIOD_READ_I
value|3
end_define

begin_comment
comment|/* Read from I space */
end_comment

begin_define
define|#
directive|define
name|PIOD_WRITE_I
value|4
end_define

begin_comment
comment|/* Write to I space */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|ptrace_set_pc
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|unsigned
name|long
name|_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptrace_single_step
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__HAVE_PTRACE_MACHDEP
end_ifdef

begin_function_decl
name|int
name|cpu_ptrace
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|int
name|_req
parameter_list|,
name|void
modifier|*
name|_addr
parameter_list|,
name|int
name|_data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are prototypes for functions that implement some of the  * debugging functionality exported by procfs / linprocfs and by the  * ptrace(2) syscall.  They used to be part of procfs, but they don't  * really belong there.  */
end_comment

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dbreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|proc_read_regs
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|reg
modifier|*
name|_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_write_regs
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|reg
modifier|*
name|_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_read_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|fpreg
modifier|*
name|_fpreg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_write_fpregs
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|fpreg
modifier|*
name|_fpreg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_read_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|dbreg
modifier|*
name|_dbreg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_write_dbregs
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|dbreg
modifier|*
name|_dbreg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_sstep
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_rwmem
parameter_list|(
name|struct
name|proc
modifier|*
name|_p
parameter_list|,
name|struct
name|uio
modifier|*
name|_uio
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|ptrace
parameter_list|(
name|int
name|_request
parameter_list|,
name|pid_t
name|_pid
parameter_list|,
name|caddr_t
name|_addr
parameter_list|,
name|int
name|_data
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
comment|/* !_SYS_PTRACE_H_ */
end_comment

end_unit

