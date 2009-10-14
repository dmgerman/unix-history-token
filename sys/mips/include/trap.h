begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: trap.h,v 1.3 1999/01/27 04:46:06 imp Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah Hdr: trap.h 1.1 90/07/09  *	from: @(#)trap.h	8.1 (Berkeley) 6/10/93  *	JNPR: trap.h,v 1.3 2006/12/02 09:53:41 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TRAP_H_
end_define

begin_comment
comment|/*  * Trap codes also known in trap.c for name strings.  * Used for indexing so modify with care.  */
end_comment

begin_define
define|#
directive|define
name|T_INT
value|0
end_define

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|T_TLB_MOD
value|1
end_define

begin_comment
comment|/* TLB modified fault */
end_comment

begin_define
define|#
directive|define
name|T_TLB_LD_MISS
value|2
end_define

begin_comment
comment|/* TLB miss on load or ifetch */
end_comment

begin_define
define|#
directive|define
name|T_TLB_ST_MISS
value|3
end_define

begin_comment
comment|/* TLB miss on a store */
end_comment

begin_define
define|#
directive|define
name|T_ADDR_ERR_LD
value|4
end_define

begin_comment
comment|/* Address error on a load or ifetch */
end_comment

begin_define
define|#
directive|define
name|T_ADDR_ERR_ST
value|5
end_define

begin_comment
comment|/* Address error on a store */
end_comment

begin_define
define|#
directive|define
name|T_BUS_ERR_IFETCH
value|6
end_define

begin_comment
comment|/* Bus error on an ifetch */
end_comment

begin_define
define|#
directive|define
name|T_BUS_ERR_LD_ST
value|7
end_define

begin_comment
comment|/* Bus error on a load or store */
end_comment

begin_define
define|#
directive|define
name|T_SYSCALL
value|8
end_define

begin_comment
comment|/* System call */
end_comment

begin_define
define|#
directive|define
name|T_BREAK
value|9
end_define

begin_comment
comment|/* Breakpoint */
end_comment

begin_define
define|#
directive|define
name|T_RES_INST
value|10
end_define

begin_comment
comment|/* Reserved instruction exception */
end_comment

begin_define
define|#
directive|define
name|T_COP_UNUSABLE
value|11
end_define

begin_comment
comment|/* Coprocessor unusable */
end_comment

begin_define
define|#
directive|define
name|T_OVFLOW
value|12
end_define

begin_comment
comment|/* Arithmetic overflow */
end_comment

begin_define
define|#
directive|define
name|T_TRAP
value|13
end_define

begin_comment
comment|/* Trap instruction */
end_comment

begin_define
define|#
directive|define
name|T_VCEI
value|14
end_define

begin_comment
comment|/* Virtual coherency instruction */
end_comment

begin_define
define|#
directive|define
name|T_FPE
value|15
end_define

begin_comment
comment|/* Floating point exception */
end_comment

begin_define
define|#
directive|define
name|T_IWATCH
value|16
end_define

begin_comment
comment|/* Inst. Watch address reference */
end_comment

begin_define
define|#
directive|define
name|T_C2E
value|18
end_define

begin_comment
comment|/* Exception from coprocessor 2 */
end_comment

begin_define
define|#
directive|define
name|T_DWATCH
value|23
end_define

begin_comment
comment|/* Data Watch address reference */
end_comment

begin_define
define|#
directive|define
name|T_MCHECK
value|24
end_define

begin_comment
comment|/* Received an MCHECK */
end_comment

begin_define
define|#
directive|define
name|T_VCED
value|31
end_define

begin_comment
comment|/* Virtual coherency data */
end_comment

begin_define
define|#
directive|define
name|T_USER
value|0x20
end_define

begin_comment
comment|/* user-mode flag or'ed with type */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|DDB
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|)
end_if

begin_struct
struct|struct
name|trapdebug
block|{
comment|/* trap history buffer for debugging */
name|u_int
name|status
decl_stmt|;
name|u_int
name|cause
decl_stmt|;
name|u_int
name|vadr
decl_stmt|;
name|u_int
name|pc
decl_stmt|;
name|u_int
name|ra
decl_stmt|;
name|u_int
name|sp
decl_stmt|;
name|u_int
name|code
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|trapdebug_enter
parameter_list|(
name|x
parameter_list|,
name|cd
parameter_list|)
value|{	\ 	intrmask_t s = disableintr();	\ 	trp->status = x->sr;		\ 	trp->cause = x->cause;		\ 	trp->vadr = x->badvaddr;	\ 	trp->pc = x->pc;		\ 	trp->sp = x->sp;		\ 	trp->ra = x->ra;		\ 	trp->code = cd;			\ 	if (++trp ==&trapdebug[TRAPSIZE])	\ 		trp = trapdebug;	\ 	restoreintr(s);			\ }
end_define

begin_define
define|#
directive|define
name|TRAPSIZE
value|10
end_define

begin_comment
comment|/* Trap log buffer length */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|trapdebug
name|trapdebug
index|[
name|TRAPSIZE
index|]
decl_stmt|,
modifier|*
name|trp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|trapDump
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|trapdebug_enter
parameter_list|(
name|x
parameter_list|,
name|cd
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|MipsFPTrap
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsKernGenException
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsKernIntr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsKernTLBInvalidException
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsTLBInvalidException
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsTLBMissException
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsUserGenException
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsUserIntr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MipsUserTLBInvalidException
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/* XXX */
end_comment

begin_function_decl
name|int
name|check_address
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_trap_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_trap_exit
parameter_list|(
name|void
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

begin_comment
comment|/* !_MACHINE_TRAP_H_ */
end_comment

end_unit

