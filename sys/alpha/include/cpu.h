begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: cpu.h,v 1.18 1997/09/23 23:17:49 mjacob Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cpu.h 1.16 91/03/25$  *  *	@(#)cpu.h	8.4 (Berkeley) 1/5/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_CPU_H_
end_define

begin_comment
comment|/*  * Exported definitions unique to Alpha cpu support.  */
end_comment

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|(alpha_pal_rdusp())
end_define

begin_comment
comment|/*  * Arguments to hardclock and gatherstats encapsulate the previous  * machine state in an opaque clockframe.  One the Alpha, we use  * what we push on an interrupt (a trapframe).  */
end_comment

begin_struct
struct|struct
name|clockframe
block|{
name|struct
name|trapframe
name|cf_tf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|framep
parameter_list|)
define|\
value|(((framep)->tf_regs[FRAME_PS]& ALPHA_PSL_USERMODE) != 0)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->tf_regs[FRAME_PC])
end_define

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|TRAPF_USERMODE(&(framep)->cf_tf)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|TRAPF_PC(&(framep)->cf_tf)
end_define

begin_comment
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CONSDEV
value|1
end_define

begin_comment
comment|/* dev_t: console terminal device */
end_comment

begin_define
define|#
directive|define
name|CPU_ROOT_DEVICE
value|2
end_define

begin_comment
comment|/* string: root device name */
end_comment

begin_define
define|#
directive|define
name|CPU_UNALIGNED_PRINT
value|3
end_define

begin_comment
comment|/* int: print unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|CPU_UNALIGNED_FIX
value|4
end_define

begin_comment
comment|/* int: fix unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|CPU_UNALIGNED_SIGBUS
value|5
end_define

begin_comment
comment|/* int: SIGBUS unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|CPU_BOOTED_KERNEL
value|6
end_define

begin_comment
comment|/* string: booted kernel name */
end_comment

begin_define
define|#
directive|define
name|CPU_ADJKERNTZ
value|7
end_define

begin_comment
comment|/* int:	timezone offset	(seconds) */
end_comment

begin_define
define|#
directive|define
name|CPU_DISRTCSET
value|8
end_define

begin_comment
comment|/* int: disable resettodr() call */
end_comment

begin_define
define|#
directive|define
name|CPU_WALLCLOCK
value|9
end_define

begin_comment
comment|/* int:	indicates wall CMOS clock */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|9
end_define

begin_comment
comment|/* 9 valid machdep IDs */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ 	{ "root_device", CTLTYPE_STRING }, \ 	{ "unaligned_print", CTLTYPE_INT }, \ 	{ "unaligned_fix", CTLTYPE_INT }, \ 	{ "unaligned_sigbus", CTLTYPE_INT }, \ 	{ "booted_kernel", CTLTYPE_STRING }, \ 	{ "adjkerntz", CTLTYPE_INT }, \ 	{ "disable_rtc_set", CTLTYPE_INT }, \ 	{ "wall_cmos_clock", CTLTYPE_INT }, \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rpb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|rpb
modifier|*
name|hwrpb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|mc_expected
decl_stmt|,
name|mc_received
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|XentArith
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentIF
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentInt
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentMM
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentRestart
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentSys
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|XentUna
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|alpha_init
parameter_list|(
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|alpha_pa_access
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_check
parameter_list|(
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_save
parameter_list|(
name|struct
name|thread
modifier|*
name|p
parameter_list|,
name|int
name|write
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_drop
parameter_list|(
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alpha_fpstate_switch
parameter_list|(
name|struct
name|thread
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|badaddr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|badaddr_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|console_restart
parameter_list|(
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpconf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exception_return
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|frametoreg
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|,
name|struct
name|reg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|fswintrberr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|init_prom_interface
parameter_list|(
name|struct
name|rpb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|interrupt
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|machine_check
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|hwrpb_checksum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hwrpb_restart_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regdump
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|regtoframe
parameter_list|(
name|struct
name|reg
modifier|*
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|savectx
parameter_list|(
name|struct
name|pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_iointr
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|switch_exit
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAGIC */
end_comment

begin_function_decl
name|void
name|syscall
parameter_list|(
name|u_int64_t
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trap
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return contents of in-cpu fast counter as a sort of "bogo-time"  * for non-critical timing.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|alpha_rpcc
argument_list|()
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALPHA_CPU_H_ */
end_comment

end_unit

