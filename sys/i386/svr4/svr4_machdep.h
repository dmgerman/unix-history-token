begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_SVR4_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_SVR4_MACHDEP_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR4_MACHDEP_JUST_REGS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<svr4/svr4_types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Machine dependent portions [X86]  */
end_comment

begin_define
define|#
directive|define
name|SVR4_X86_GS
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_X86_FS
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_X86_ES
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_X86_DS
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EDI
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_X86_ESI
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EBP
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_X86_ESP
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EBX
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EDX
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_X86_ECX
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EAX
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_X86_TRAPNO
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_X86_ERR
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EIP
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_X86_CS
value|15
end_define

begin_define
define|#
directive|define
name|SVR4_X86_EFL
value|16
end_define

begin_define
define|#
directive|define
name|SVR4_X86_UESP
value|17
end_define

begin_define
define|#
directive|define
name|SVR4_X86_SS
value|18
end_define

begin_define
define|#
directive|define
name|SVR4_X86_MAXREG
value|19
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SVR4_MACHDEP_JUST_REGS
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|svr4_greg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|svr4_greg_t
name|svr4_gregset_t
index|[
name|SVR4_X86_MAXREG
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|f_x87
index|[
literal|62
index|]
decl_stmt|;
comment|/* x87 registers */
name|long
name|f_weitek
index|[
literal|33
index|]
decl_stmt|;
comment|/* weitek */
block|}
name|svr4_fregset_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|svr4_ucontext
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|svr4_getcontext
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|svr4_ucontext
operator|*
operator|,
name|sigset_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_setcontext
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|svr4_ucontext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|svr4_gregset_t
name|greg
decl_stmt|;
name|svr4_fregset_t
name|freg
decl_stmt|;
block|}
name|svr4_mcontext_t
typedef|;
end_typedef

begin_comment
comment|/*  * SYSARCH numbers  */
end_comment

begin_define
define|#
directive|define
name|SVR4_SYSARCH_FPHW
value|40
end_define

begin_define
define|#
directive|define
name|SVR4_SYSARCH_DSCR
value|75
end_define

begin_struct
struct|struct
name|svr4_ssd
block|{
name|unsigned
name|int
name|selector
decl_stmt|;
name|unsigned
name|int
name|base
decl_stmt|;
name|unsigned
name|int
name|limit
decl_stmt|;
name|unsigned
name|int
name|access1
decl_stmt|;
name|unsigned
name|int
name|access2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Processor traps  */
end_comment

begin_define
define|#
directive|define
name|SVR4_T_DIVIDE
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_T_TRCTRAP
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_T_NMI
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_T_BPTFLT
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_T_OFLOW
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_T_BOUND
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_T_PRIVINFLT
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_T_DNA
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_T_DOUBLEFLT
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_T_FPOPFLT
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_T_TSSFLT
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_T_SEGNPFLT
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_T_STKFLT
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_T_PROTFLT
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_T_PAGEFLT
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_T_ALIGNFLT
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SVR4_MACHDEP_JUST_REGS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_SVR4_MACHDEP_H_ */
end_comment

end_unit

