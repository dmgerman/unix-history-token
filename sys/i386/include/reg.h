begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)reg.h	5.5 (Berkeley) 1/18/91  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_REG_H_
end_define

begin_comment
comment|/*  * Location of the users' stored  * registers within appropriate frame of 'trap' and 'syscall', relative to  * base of stack frame.  * Normal usage is u.u_ar0[XX] in kernel.  */
end_comment

begin_comment
comment|/* When referenced during a trap/exception, registers are at these offsets */
end_comment

begin_define
define|#
directive|define
name|tES
value|(0)
end_define

begin_define
define|#
directive|define
name|tDS
value|(1)
end_define

begin_define
define|#
directive|define
name|tEDI
value|(2)
end_define

begin_define
define|#
directive|define
name|tESI
value|(3)
end_define

begin_define
define|#
directive|define
name|tEBP
value|(4)
end_define

begin_define
define|#
directive|define
name|tISP
value|(5)
end_define

begin_define
define|#
directive|define
name|tEBX
value|(6)
end_define

begin_define
define|#
directive|define
name|tEDX
value|(7)
end_define

begin_define
define|#
directive|define
name|tECX
value|(8)
end_define

begin_define
define|#
directive|define
name|tEAX
value|(9)
end_define

begin_define
define|#
directive|define
name|tERR
value|(11)
end_define

begin_define
define|#
directive|define
name|tEIP
value|(12)
end_define

begin_define
define|#
directive|define
name|tCS
value|(13)
end_define

begin_define
define|#
directive|define
name|tEFLAGS
value|(14)
end_define

begin_define
define|#
directive|define
name|tESP
value|(15)
end_define

begin_define
define|#
directive|define
name|tSS
value|(16)
end_define

begin_comment
comment|/*  * Registers accessible to ptrace(2) syscall for debugger  * The machine-dependent code for PT_{SET,GET}REGS needs to  * use whichever order, defined above, is correct, so that it  * is all invisible to the user.  */
end_comment

begin_struct
struct|struct
name|reg
block|{
name|unsigned
name|int
name|r_es
decl_stmt|;
name|unsigned
name|int
name|r_ds
decl_stmt|;
name|unsigned
name|int
name|r_edi
decl_stmt|;
name|unsigned
name|int
name|r_esi
decl_stmt|;
name|unsigned
name|int
name|r_ebp
decl_stmt|;
name|unsigned
name|int
name|r_isp
decl_stmt|;
name|unsigned
name|int
name|r_ebx
decl_stmt|;
name|unsigned
name|int
name|r_edx
decl_stmt|;
name|unsigned
name|int
name|r_ecx
decl_stmt|;
name|unsigned
name|int
name|r_eax
decl_stmt|;
name|unsigned
name|int
name|r_trapno
decl_stmt|;
name|unsigned
name|int
name|r_err
decl_stmt|;
name|unsigned
name|int
name|r_eip
decl_stmt|;
name|unsigned
name|int
name|r_cs
decl_stmt|;
name|unsigned
name|int
name|r_eflags
decl_stmt|;
name|unsigned
name|int
name|r_esp
decl_stmt|;
name|unsigned
name|int
name|r_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via /proc/$pid/fpreg  */
end_comment

begin_struct
struct|struct
name|fpreg
block|{
comment|/* 	 * XXX should get struct from npx.h.  Here we give a slightly 	 * simplified struct.  This may be too much detail.  Perhaps 	 * an array of unsigned longs is best. 	 */
name|unsigned
name|long
name|fpr_env
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|char
name|fpr_acc
index|[
literal|8
index|]
index|[
literal|10
index|]
decl_stmt|;
name|unsigned
name|long
name|fpr_ex_sw
decl_stmt|;
name|unsigned
name|char
name|fpr_pad
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|set_regs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|reg
operator|*
name|regs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_REG_H_ */
end_comment

end_unit

