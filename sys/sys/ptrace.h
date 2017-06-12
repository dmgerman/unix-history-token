begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ptrace.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

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
name|PT_LWPINFO
value|13
end_define

begin_comment
comment|/* Info about the LWP that stopped. */
end_comment

begin_define
define|#
directive|define
name|PT_GETNUMLWPS
value|14
end_define

begin_comment
comment|/* get total number of threads */
end_comment

begin_define
define|#
directive|define
name|PT_GETLWPLIST
value|15
end_define

begin_comment
comment|/* get thread list */
end_comment

begin_define
define|#
directive|define
name|PT_CLEARSTEP
value|16
end_define

begin_comment
comment|/* turn off single step */
end_comment

begin_define
define|#
directive|define
name|PT_SETSTEP
value|17
end_define

begin_comment
comment|/* turn on single step */
end_comment

begin_define
define|#
directive|define
name|PT_SUSPEND
value|18
end_define

begin_comment
comment|/* suspend a thread */
end_comment

begin_define
define|#
directive|define
name|PT_RESUME
value|19
end_define

begin_comment
comment|/* resume a thread */
end_comment

begin_define
define|#
directive|define
name|PT_TO_SCE
value|20
end_define

begin_define
define|#
directive|define
name|PT_TO_SCX
value|21
end_define

begin_define
define|#
directive|define
name|PT_SYSCALL
value|22
end_define

begin_define
define|#
directive|define
name|PT_FOLLOW_FORK
value|23
end_define

begin_define
define|#
directive|define
name|PT_LWP_EVENTS
value|24
end_define

begin_comment
comment|/* report LWP birth and exit */
end_comment

begin_define
define|#
directive|define
name|PT_GET_EVENT_MASK
value|25
end_define

begin_comment
comment|/* get mask of optional events */
end_comment

begin_define
define|#
directive|define
name|PT_SET_EVENT_MASK
value|26
end_define

begin_comment
comment|/* set mask of optional events */
end_comment

begin_define
define|#
directive|define
name|PT_GET_SC_ARGS
value|27
end_define

begin_comment
comment|/* fetch syscall args */
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
name|PT_VM_TIMESTAMP
value|40
end_define

begin_comment
comment|/* Get VM version (timestamp) */
end_comment

begin_define
define|#
directive|define
name|PT_VM_ENTRY
value|41
end_define

begin_comment
comment|/* Get VM map (entry) */
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

begin_comment
comment|/* Events used with PT_GET_EVENT_MASK and PT_SET_EVENT_MASK */
end_comment

begin_define
define|#
directive|define
name|PTRACE_EXEC
value|0x0001
end_define

begin_define
define|#
directive|define
name|PTRACE_SCE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PTRACE_SCX
value|0x0004
end_define

begin_define
define|#
directive|define
name|PTRACE_SYSCALL
value|(PTRACE_SCE | PTRACE_SCX)
end_define

begin_define
define|#
directive|define
name|PTRACE_FORK
value|0x0008
end_define

begin_define
define|#
directive|define
name|PTRACE_LWP
value|0x0010
end_define

begin_define
define|#
directive|define
name|PTRACE_VFORK
value|0x0020
end_define

begin_define
define|#
directive|define
name|PTRACE_DEFAULT
value|(PTRACE_EXEC)
end_define

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

begin_comment
comment|/* Argument structure for PT_LWPINFO. */
end_comment

begin_struct
struct|struct
name|ptrace_lwpinfo
block|{
name|lwpid_t
name|pl_lwpid
decl_stmt|;
comment|/* LWP described. */
name|int
name|pl_event
decl_stmt|;
comment|/* Event that stopped the LWP. */
define|#
directive|define
name|PL_EVENT_NONE
value|0
define|#
directive|define
name|PL_EVENT_SIGNAL
value|1
name|int
name|pl_flags
decl_stmt|;
comment|/* LWP flags. */
define|#
directive|define
name|PL_FLAG_SA
value|0x01
comment|/* M:N thread */
define|#
directive|define
name|PL_FLAG_BOUND
value|0x02
comment|/* M:N bound thread */
define|#
directive|define
name|PL_FLAG_SCE
value|0x04
comment|/* syscall enter point */
define|#
directive|define
name|PL_FLAG_SCX
value|0x08
comment|/* syscall leave point */
define|#
directive|define
name|PL_FLAG_EXEC
value|0x10
comment|/* exec(2) succeeded */
define|#
directive|define
name|PL_FLAG_SI
value|0x20
comment|/* siginfo is valid */
define|#
directive|define
name|PL_FLAG_FORKED
value|0x40
comment|/* new child */
define|#
directive|define
name|PL_FLAG_CHILD
value|0x80
comment|/* I am from child */
define|#
directive|define
name|PL_FLAG_BORN
value|0x100
comment|/* new LWP */
define|#
directive|define
name|PL_FLAG_EXITED
value|0x200
comment|/* exiting LWP */
define|#
directive|define
name|PL_FLAG_VFORKED
value|0x400
comment|/* new child via vfork */
define|#
directive|define
name|PL_FLAG_VFORK_DONE
value|0x800
comment|/* vfork parent has resumed */
name|sigset_t
name|pl_sigmask
decl_stmt|;
comment|/* LWP signal mask */
name|sigset_t
name|pl_siglist
decl_stmt|;
comment|/* LWP pending signal */
name|struct
name|__siginfo
name|pl_siginfo
decl_stmt|;
comment|/* siginfo for signal */
name|char
name|pl_tdname
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* LWP name */
name|pid_t
name|pl_child_pid
decl_stmt|;
comment|/* New child pid */
name|u_int
name|pl_syscall_code
decl_stmt|;
name|u_int
name|pl_syscall_narg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Argument structure for PT_VM_ENTRY. */
end_comment

begin_struct
struct|struct
name|ptrace_vm_entry
block|{
name|int
name|pve_entry
decl_stmt|;
comment|/* Entry number used for iteration. */
name|int
name|pve_timestamp
decl_stmt|;
comment|/* Generation number of VM map. */
name|u_long
name|pve_start
decl_stmt|;
comment|/* Start VA of range. */
name|u_long
name|pve_end
decl_stmt|;
comment|/* End VA of range (incl). */
name|u_long
name|pve_offset
decl_stmt|;
comment|/* Offset in backing object. */
name|u_int
name|pve_prot
decl_stmt|;
comment|/* Protection of memory range. */
name|u_int
name|pve_pathlen
decl_stmt|;
comment|/* Size of path. */
name|long
name|pve_fileid
decl_stmt|;
comment|/* File ID. */
name|uint32_t
name|pve_fsid
decl_stmt|;
comment|/* File system ID. */
name|char
modifier|*
name|pve_path
decl_stmt|;
comment|/* Path name of object. */
block|}
struct|;
end_struct

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

begin_function_decl
name|int
name|ptrace_clear_single_step
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

begin_function_decl
name|ssize_t
name|proc_readmem
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|proc
modifier|*
name|_p
parameter_list|,
name|vm_offset_t
name|_va
parameter_list|,
name|void
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|proc_writemem
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|proc
modifier|*
name|_p
parameter_list|,
name|vm_offset_t
name|_va
parameter_list|,
name|void
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_len
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
end_ifdef

begin_struct_decl
struct_decl|struct
name|reg32
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg32
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dbreg32
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|proc_read_regs32
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|reg32
modifier|*
name|_reg32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_write_regs32
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|reg32
modifier|*
name|_reg32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_read_fpregs32
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|fpreg32
modifier|*
name|_fpreg32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_write_fpregs32
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|fpreg32
modifier|*
name|_fpreg32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_read_dbregs32
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|dbreg32
modifier|*
name|_dbreg32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_write_dbregs32
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|struct
name|dbreg32
modifier|*
name|_dbreg32
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

